#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//大端字节序存储：数据的低位字节处存储在高地址处，高位字节处存储在低地址处

//小端字节序存储：数据的低位字节处存储在低地址处，高位字节处存储在高地址处

int judge_sys1(void)
{
	//判断大小端的函数
	int a = 1;
	if (*(char*)&a == 1)//如果低位放在低地址处
	{
		return 1;//小端
	}
	else
		return 0;//大端
}

int judge_sys2(void)
{
	int a = 1;
	//小端01 00 00 00
	//大端00 00 00 01
	return *(char*)&a;  //小端返回1,大端返回0
}
int main()
{
	printf("%d", judge_sys2());
	return 0;
}