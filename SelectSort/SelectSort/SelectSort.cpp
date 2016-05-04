#include <stdio.h>
/*
Select Sort ѡ������
��������ݴ�С��������
*/
void swap(int *x, int * y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/*
�������ƣ�SelectSort(int *num,const int numlen)
����˵����num����Ҫ���������ָ��
		 numlen�����鳤��
�������ܣ�ѡ�����򷽷�������С����˳��������������Ԫ��
����ֵ����
*/
void SelectSort(int *num,const int numlen)
{
	int i = 0, j = 0;
	int len = numlen;
	int minimum = 0;
	int minimum_number = 0;
	for (i = 0; i < (len - 1); i++)
	{
		minimum = *(num+i);
		minimum_number = i;
		for (j = i; j < len; j++)
		{
			if (*(num+j)<minimum)
			{
				minimum = *(num+j);
				minimum_number = j;
			}
		}
		swap(num+i, num+minimum_number);
	}
}

int main()
{
	int num[] = {3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
	int len = sizeof(num) / sizeof(int);
	int i = 0;
	SelectSort(num,len);
	//��ӡ������
	for (i = 0; i < len; i++)
	{
		printf("%d \t", num[i]);
	}
	return 0;
}