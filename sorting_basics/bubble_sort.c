#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<assert.h>
//一组数从小到大排序
//冒泡排序：从左到右依次比较相邻的元素,若左边元素>右边元素,则互换位置,一趟下来,
//可以把max放到最右侧,
//若有N个,需进行N-1趟

void BubbleSort1(int* arr1, int sz)
{
	assert(arr1);
	for (int i = 0; i < sz - 1; i++)//确定趟数
	{
		int ass = 1;//改进:若一趟下来没有交换，则已经排好序
		for (int j = 0; j < sz - 1 - i; j++)//一趟要比较的元素对数
		{
			if (arr1[j] > arr1[j + 1])//若左边元素>右边元素,互换
			{
				int tem = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = tem;
				ass = 0;
			}
		}
		if (ass == 1)
			return;
	}
}

//通用型冒泡排序
void BubbleSort2(void* arr1, int num, int size, int (*pa)(const void* a, const void* b))
{
	//num-元素个数；size-每个元素大小;
	//int (*pa)(const void*a, const void*b)-指向函数的指针,该函数是专门比较两个元素
	for (int i = 0; i < num - 1; i++)//确定趟数
	{
		int ass = 1;
		for (int j = 0; j < num - 1 - i; j++)//一趟需要比较的对数
		{
			if (pa((char*)arr1 + j * size, (char*)arr1 + (j + 1) * size) > 0)//左边元素更大
			{
				ass = 0;
				//互换位置
				for (int k = 0; k < size; k++)          //一个字节一个字节交换
				{
					char tem = *((char*)arr1 + j*size+k);
					*((char*)arr1 + j* size +k) = *((char*)arr1 + (j+1)*size+k);
					*((char*)arr1 + (j+1)*size+k) = tem;
				}
			}
		}
		if (ass == 1)
			return;
	}
}

int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int arr1[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);//元素个数
	//BubbleSort1(arr1, sz);
	BubbleSort2(arr1, sz, 4, cmp);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
}