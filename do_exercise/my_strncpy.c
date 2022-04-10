#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>
char* my_strncpy(char* destination, const char* source, size_t count)
{
	//(从左到右)从源字符串中拷贝count个字节(字符)到目标字符串相应位置
	char* re = destination;
	for (int i = 0; i < count; i++)
	{
		//要拷贝count次
		if (*source == '\0')//如果已经拷贝到源字符串末尾,那就用'\0'填充
		{
			*destination = '\0';
			destination++;
		}
		else//正常拷贝
		{
			*destination = *source;
			destination++;
			source++;
		}
	}
	return re;
}
int main()
{
	char arr1[10] = "abcd\0aaaa";
	char arr2[ ] = "qvzt";
	printf("%s", strncpy(arr1, arr2, 7));
	return 0;
}