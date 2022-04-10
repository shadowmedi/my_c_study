#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<assert.h>
//从前往后依次比较字符的ASCII码值
int my_strcmp(const char* arr1, const char* arr2)
{
	assert(arr1 && arr2);
	while (*arr1 == *arr2 )//当两个字符相等时,比较下一对字符
	{
		if (*arr1 == '\0')//但如果都比较到'\0',说明两个字符串相等
		{
			return 0;
		}
		arr1++;
		arr2++;
	}
	//当比较到有一对字符不相等时
	if (*arr1 > *arr2)
		return 1;
	else if (*arr1 < *arr2)
		return -1;
}
int main()
{
	char arr1[5] = "abcd";
	char arr2[7] = "cdefg";
	printf("%d",my_strcmp(arr1, arr2));//比较字符串大小
	return 0;
}