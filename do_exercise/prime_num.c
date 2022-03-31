#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdbool.h>
#include <math.h>
//判断素数的n种方法
//1 试除法
bool judge1(int a)
{
	if (a == 2)
		return true;
	else if (a == 1)
		return false;
	else
	{
		for (int i = 2; i <= a - 1; i++)//思路：从2到(a-1)依次试除，若整除则不是素数
		{
			if (a % i == 0)
				return false;
		}
		return true;
	}
}

bool judge2(int a)
{
	if (a == 2)
		return true;
	else if (a == 1)
		return false;
	else
	{
		for (int i = 2; i <= sqrt(a); i++)//a可以分成2个因数相乘，其中一个因数一定<=sqrt(a)
		{                                  //如果<=sqrt(a)的数都不是a的因数，那后面的数一定不是a的因数
			if (a % i == 0)
				return false;
		}
		return true;
	}
}


bool judge3(int a)
{
	if (a == 2)
		return true;
	else if (a == 1)
		return false;
	else if(a % 2 == 0)//若能被2整除且a不是2，a就不是素数
	{
		return false;
	}
	else
	{
		for (int i = 3; i <= sqrt(a); i += 2) //此时这里不需要检测%2的倍数
		{
			if (a % i == 0)
				return false;
		}
		return true;
	}
}

//2 筛选法
bool arr[1000] = { 0 };
bool judge4(int a)
{
	for (int i = 0; i <= a; i++)
	{
		arr[i] = true;
	}
	arr[0] = false;
	arr[1] = false;
	for (int n = 2; n < a; n++)
	{
		if (arr[n] == true)
		{
			for (int k = 2; k * n <= a; k++)
			{
				arr[k * n] = false;
			}
		}
	}
	bool re = arr[a];
	return re;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	bool a = judge4(n);
	if (a == true)
	{
		printf("RIGHT\n");
	}

	return 0;
}