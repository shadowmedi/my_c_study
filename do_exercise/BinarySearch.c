#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//二分查找
//在递增数列中查找某个数，并返回其下标
int BinarySearch(int* pa, int sz, int ser)
{
	int left = 0;
	int right = sz - 1;//定义双下标，分别指向第一个元素和最后一个元素
	int mid = left + (right - left) / 2;//指向中间元素
	while (right >= left)        //若右下标>=左下标
	{
		mid = left + (right - left) / 2;//重置中间元素
		if (pa[mid] > ser)//若中间元素>要查找的元素,说明要查找的元素的下标在mid左边
		{
			right = mid - 1;//缩小范围，排除mid下标之后的所有数
		}
		else if (pa[mid] < ser)//若中间元素<要查找的元素,说明要查找的元素的下标在mid右边
		{
			left = mid + 1;//缩小范围，排除mid下标之前的所有数
		}
		else
			return mid;
	}
	return -1;//找不到返回-1
}
int main()
{
	int arr[10] = {  1, 2, 3, 4, 5, 6, 7, 8, 9,10 };
	int ser = 0;
	scanf("%d", &ser);
	int sz = sizeof(arr) / sizeof(arr[0]);
	int re =BinarySearch(arr, sz, ser);
	printf("%d", re);
	return 0;
}