#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//勾股数就是可以构成一个直角三角形三边的一组正整数。

//bug:进入循环时嵌套的循环变量注意初始化值

/*问题描述
勾股数是一组三个自然数，a < b < c，以这三个数为三角形的三条边能够形成一个直角三角形
	输出所有a + b + c <= 1000的勾股数
	a小的先输出；a相同的，b小的先输出。
	输出格式
	每行为一组勾股数，用空格隔开
	样例输出
	例如，结果的前三行应当是
	3 4 5
	5 12 13
	6 8 10
*/
//思路：定义三边长判断a*a+b*b==c*c(循环穷举)

/*
int main()
{
	int a = 3, b = 4, c = 5;
	for (a = 3; a < 500; a++)
		for (b = a+1; b < 500; b++)//b要大于a，所以b直接从a+1开始遍历
			for (c = 5; c <= 500; c++)
			{
				if (a + c + b > 1000 || a+b <= c)
					break;
				if (a * a + b * b == c * c )
				{
					printf("%-3d %-3d %-3d\n", a, b, c);
				}
			}
	
	return 0;
}*/

//改进
//由于知道a,b就能求出c，判断c*c==(sqrt(a*a+b*b))^2
int main()
{
	int a = 3, b = 4, c = 5;
	for (a = 3; a < 500; a++)
		for (b = a + 1; b < 500; b++)
		{
			c = (int)sqrt(a * a + b * b);
			if (c * c == a * a + b * b && a+b+c <= 1000 &&a + b > c)
				printf("%-3d %-3d %-3d\n", a, b, c);
		}
	return 0;
}


