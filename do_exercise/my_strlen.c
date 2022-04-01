#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
int my_strlen(const char* arr)
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
int main()
{
	char arr1[10] = "abcdehi";
	printf("%d", my_strlen(arr1));
	return 0;
}