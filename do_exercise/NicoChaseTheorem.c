#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//任何一个整数 m 的立方都可以写成 m 个连续奇数之和。
//输入一个正整数 m（m≤100） ，将 m 的立方写成 m 个连续奇数之和的形式输出。

int sum1(int x, int y)
{
	//y个从x开始的连续奇数之和
	int sum = 0;
	if (x % 2 == 0)//若为偶数把它改成奇数
		x += 1;
	for (int i = 0; i < y; i++)//确定相加y次
	{
		sum += x + 2 * i;
	}
	return sum;
}
int main()
{
	int m = 0;
	scanf("%d", &m);
	int n = (int)pow(m, 3);
	int k = 1;
	for (k = 1; k <= n / 3; k += 2)
	{
		if (sum1(k, m) == n)//确定相加的起点
		{
			break;
		}
	}
	printf("%d", k);
	for (int t = 1; t < m; t++)//剩下的加上只有(m - 1)个
	{
		printf("+%d", k + 2 * t);
	}
	return 0;
}