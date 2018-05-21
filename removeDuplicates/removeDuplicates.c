#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
	int i = 0;
	int len = 1;
	int temp = nums[0];

	if (numsSize < len)
		return numsSize;

	for (i = 1; i < numsSize; i++)
	{
		if (temp != nums[i])
		{
			nums[len] = nums[i];
			temp = nums[i];
			len++;
		}
	}

	return len;
}

int main()
{
	int nums[3] = {0,0,10};
	int len = 0;
	int i = 0;

	len = removeDuplicates(nums, sizeof(nums) / sizeof(int));

	printf("%d\n",len);

	for (i = 0; i < len; i++)
	{
		printf("%d\t", nums[i]);
	}
	printf("\n");
	return 0;


}
