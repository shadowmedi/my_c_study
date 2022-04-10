#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<assert.h>
int my_strlen1(const char* arr)
{
	assert(arr);//断言不为空指针
	int num = 0;//统计数目
	while (*arr++)//首先看*arr是否为'\0'，然后arr++
	{
		num++;
	}
	arr = NULL;
	return num;
}

size_t my_strlen(const char* arr)
{
	assert(arr);//断言不为空指针
	if (*arr == '\0')
		return 0;
	else
		return 1 + my_strlen(arr + 1);
}

size_t my_strlen3(const char* arr)
{
	assert(arr);//断言不为空指针
	const char* init = arr;//保留arr的初始值
	while (*arr)//使arr指向'\0'
	{
		arr++;
	}
	size_t num = arr - init;//两个指针相减得到它们之间的元素个数
	return num;
}
int main()
{
	char arr1[10] = "abc";
	printf("%d", (int)my_strlen3(arr1));
	return 0;
}