#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//1 创建临时变量
//2 位操作（异或）
//3 变量之间加减

void exchange(int* a, int* b)//创建临时变量
{
	int tem = *a;
	*a = *b;
	*b = tem;
}

void bit_operations(int* a, int* b)//位操作
{
	//一个数异或2次相同的数仍然是它本身
	//按位异或支持交换律
	*a = *a ^ *b;
	*b = *a ^ *b; //相当于*a ^ *b ^*b,所以把*a赋给了*b
	*a = *a ^ *b; //相当于原来的*a ^ *b ^ *a，所以把*b赋给了*a
}

void plus_minus(int* a, int* b)//变量之间相减
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	exchange(&a, &b);//形参是实参的临时拷贝，传址才能改变函数外的参数
	//bit_operations(&a, &b);
	//plus_minus(&a, &b);
	printf("a=%d  b=%d", a, b);
	return 0;
}