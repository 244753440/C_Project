/*
Bubble Sort
冒泡排序，将数据从小到大排序
*/

#include <stdio.h>

void swap(int *x, int * y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int num[] = { 3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48 };
	int len = sizeof(num) / sizeof(int);
	int *pnum = num;
	int i = 0, j = 0;			//i代表总循环次数 j代表未排序数组元素循环次数
	for (i = 1; i < len; i++)
	{
		for (j = 0; j < (len - i); j++)
		{
			if (*(pnum + j)>*(pnum + j + 1))
				swap(pnum + j, pnum + j + 1);
		}
	}

	for (i = 0; i < len; i++)
	{
		printf("%d \t", num[i]);
	}
	return 0;
}