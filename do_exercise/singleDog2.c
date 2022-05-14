#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。

//编写一个函数找出这两个只出现一次的数字。
int* alone(int num, int arr[])
{
	int single1 = 0;
	int single2 = 0;
	int ret = 0;//记录用0异或完所有数的值
	int i = 0;//遍历数组
	for (i = 0; i < num; i++)
	{
		ret ^= arr[i];
	}
	//最后的结果假设是000...011
	//说明2个单身狗在最后两个二进制位不相同
	//若以最后一个二进制位来分组
	//最后一个二进制位是1的分为1组
	//最后一个二进制位是0的分为1组
	//用0异或其中一组数的所有值就可以找到其中一个单身狗
	int pos = 0;//记录ret二进制位为1的位置
	for (i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}
	for (i = 0; i < num; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			single1 ^= arr[i];
		}
	}
	single2 = ret ^ single1;
	int* re = (int*)malloc(sizeof(int) * 2);
	if (re == NULL)
	{
		perror("malloc");
		return NULL;
	}
	else
	{
		re[0] = single1;
		re[1] = single2;
	}
	return re;
}
int main()
{
	int arr[6] = { 33, 33, 56, 56, 33, 76 };
	int num = sizeof(arr) / sizeof(arr[0]);
	int* re =alone(num, arr);
	printf("%d %d", re[0], re[1]);
	free(re);
	re = NULL;
	return 0;
}