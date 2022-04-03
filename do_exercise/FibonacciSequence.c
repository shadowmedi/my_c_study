#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//斐波那契数列及应用
// 1 判断一个数是否在斐波那契数列上
// 2 斐波那契数列的第n个数是什么
// 3 输出斐波那契数列中小于n的所有数
// 4 已知有一个楼梯N级，小谢同学从下往上走，一步可以走一级，也可以走2级。问：他走到第n级楼梯有多少种走法？
// 5 一对兔子每个月能生出一对小兔子来。如果所有兔子都不死，那么一年以后可以繁殖多少对兔子？


// 1 1 2 3 5 8 13 ……
//分析：1个数是前2个数之和
//a(n) = a(n-1)+a(n-2)

int FBNC1(int x)            //判断一个数是否在斐波那契数列上
{
	int x1 = 1, x2 = 1, x3 = 0;
	if (x == 1)
		return 1;
	else
	{
		while (x3 < x)    //从前2个数一直推到 >= x的数
		{
			x3 = x1 + x2; //若第3个数<x, 则重置第三个数和前2个数。
			x1 = x2;
			x2 = x3;
		}
		if (x == x3)
			return 1;
		else
			return 0;
	}
}

int FBNC2(int n)        // 斐波那契数列的第n个数是什么
{
	int x1 = 1, x2 = 1, x3 = 0;
	if (n == 1 || n == 2)
		return 1;
	else
	{
		for (int num = 3; num <= n; num++)
		{
			x3 = x1 + x2;
			x1 = x2;
			x2 = x3;
		}
		return x3;
	}
}

void FBNC3(int x)
{
	int x1 = 0, x2 = 1, x3 = 1;//假设斐波那契数列多一个0，就能一个循环中重复打印两次1
	while (x3 < x)
	{
		printf("%d ", x3);
		x3 = x1 + x2;
		x1 = x2;
		x2 = x3;
	}
}

int FBNC4(int n)
{   // 4 已知有一个楼梯N级，小谢同学从下往上走，一步可以走一级，也可以走2级。
	// 问：他走到第n级楼梯有多少种走法？
	//分析：走到第n级楼梯走法有  FBNC4(n - 1)+FBNC4(n - 2), 所以也可以递归
	//登上1级:1种；登上2级:2种；登上3级:3种;登上4级:5种
	int i = 1;
	int ret1 = 1;
	int ret2 = 2;
	int ret3 = 0;
	switch (n)
	{
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	default:
		for (i = 3; i <= n; i++)
		{
			ret3 = ret1 + ret2;
			ret1 = ret2;
			ret2 = ret3;
		}
		return ret3;
	}
}

int FBNC5(int x)
{
	int init = 2;
	
}
int main()
{
	int x = 0;
	scanf("%d", &x);
	/*if (FBNC1(x) == 1)
	{
		printf("是\n");
	}*/
	//printf("%d", FBNC2(x));
	//FBNC3(x);
	return 0;
}