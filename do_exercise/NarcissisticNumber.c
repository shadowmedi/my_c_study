#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//输入一个正整数n(3~7),输出所有n位水仙花数。

//水仙花数是指一个n位正整数,他的各位数字的n次幂之和等于它本身。

//例153 = 1^3+5^3+3^3

//思路：模10取位,用pow函数取得max和min,循环遍历这个范围内
/*
int main()
{
	int n = 0;
	scanf("%d", &n);
	int max = (int)pow(10, n) - 1;
	int min = (int)pow(10, n - 1);
	for (; min <= max; min++)
	{
		int sum = 0, tem = min;
		while (tem)
		{
			sum += (int)pow(tem % 10, n);
			tem /= 10;
		}
		if (sum == min)
			printf("%d\n", sum);
	}
	return 0;
}*/

//变种水仙花数
//描述把任意的数字，从中间拆分成两个数字，
// 比如1461 可以拆分成（1和461）,（14和61）,（146和1),
// 如果所有拆分后的乘积之和等于自身，则是一个变种水仙花数。
//例如：655 = 6 * 55 + 65 * 5

int judge(int x)
{
	int n = 0;//记录位数
	int tem = x;
	while (tem)
	{
		n++;
		tem /= 10;
	}

	int sum = 0;//记录乘积之和
	while (n>1)
	{
		sum += (x % (int)pow(10, n-1)) * (x / (int)pow(10, n-1));
		n--;
	}
	if(sum == x)
		return 1;
	return 0;
}
int main()
{
	//判断是否为变种水仙花数
	int x = 0;
	scanf("%d", &x);
	int a = judge(x);
	if (a == 1)
		printf("YES");
	return 0;
}