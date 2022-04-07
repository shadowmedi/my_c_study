#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<assert.h>
//从前往后依次比较字符的ASCII码值
//当比较完任何一个'\0'终止比较
int my_strcmp(const char* arr1, const char* arr2)
{
	assert(arr1 && arr2);
	while (*arr1 == *arr2 && *arr1 != '\0')
	{
		arr1++;
		arr2++;
	}
	if (*(unsigned char*)arr1 > *(unsigned char*)arr2)
		return 1;
	else if (*(unsigned char*)arr1 < *(unsigned char*)arr2)
		return -1;
	else
		return 0;
}
int main()
{
	char arr1[5] = "abcd";
	char arr2[7] = "cdefg";
	printf("%d",my_strcmp(arr1, arr2));//比较字符串大小
	return 0;
}