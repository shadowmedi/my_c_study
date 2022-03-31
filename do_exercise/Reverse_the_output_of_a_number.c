#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
//反向输出一个整数
 

//思路：对于无小数部分：%10输出最低位，/10向前一位
#include <stdio.h>

void print(int a)//纯输出
{
	while (a)
	{
		printf("%d", a % 10);
		a /= 10;
	}
}

int reverse_num(int a)//返回值形式
{
	
	int n = 0;//用于计算位数
	int tem = a;//保留a的值
	int re = 0;//表示要返回的数
	while (a)//求a有几位数
	{
		n++;
		a /= 10;
	}
	while (tem)
	{
		re += (tem % 10)*(int)pow(10, n - 1);
		n--;
		tem /= 10;
	}
	return re;
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	//print(a);
	printf("%d", reverse_num(a));

	return 0;
}
