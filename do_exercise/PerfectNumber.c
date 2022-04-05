#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//输入n,求[1,n]之间所有完数 ,一个数等于它的所有因子之和,
//这个数就称为完数,例如28的因子1+2+4+7+14=28，则28即为一个完数)

int judge(int a, int b)
{
	//判断a是否为b的因子
	if (b % a == 0)
		return 1;
	else
		return 0;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int k = 1; k <= n; k++)//遍历1~n
	{
		int sum = 0;                    //定义因子的和
		for (int p = 1; p < k; p++)//遍历因子的所有可能
		{
			if (judge(p, k) == 1)
				sum += p;
		}
		if (sum == k)
			printf("%d ", k);
	}
}