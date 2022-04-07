#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，
//请编写程序在这样的矩阵中查找某个数字是否存在。

//思路:每行最后一个数若大于查找数,排除最后一列；
//若小于查找数，排除一行

int main()
{
	int arr[3][3] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8} };
	int ser = 0;
	scanf("%d", &ser);
	int col = 2,row = 0;
	while (col>=0 && row <= 2)
	{
		if (arr[row][col] > ser)
		{
			//排除一列
			col--;
		}
		else if (arr[row][col] == ser)
		{
			printf("存在");
			break;
		}
		else
		{
			//排除一行
			row++;
		}
	}

	return 0;
}