#define _CRT_SECURE_NO_WARNINGS
//写一个宏，计算结构体中某变量相对于首地址的偏移，并给出说明
//考察：offsetof宏的实现
#include <stdio.h>
#include <stddef.h>
#define my_offsetof(structName, memberName) (size_t)(&(((structName*)0 )->memberName))
//结构体的成员的偏移量是相对于起始地址而言的
//如果起始地址为0
//那成员的地址其实也就是成员的偏移量
struct Student
{
	int age;//0~3
	char a;//4
	int t; //8 ~11
};
int main()
{
	size_t a = my_offsetof(struct Student, t);
	printf("%lld", a);
	return 0;
}