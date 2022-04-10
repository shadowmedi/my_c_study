#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <assert.h>
/*printf("%s\n", strtok(str, delimiter));
	printf("%s\n", strtok(NULL, delimiter));
	printf("%s\n", strtok(NULL, delimiter));*/
	/*for (char* pa = str; strtok(pa, delimiter) != NULL; pa = NULL)
	{
		printf("%s\n", strtok(pa, delimiter));
	}*///error
int main()
{
	char str[] = "123456@outlook.com";//这是一个邮箱
	char delimiter[] = ".@";
	for (char* pa = strtok(str, delimiter); pa != NULL; pa = strtok(NULL, delimiter))
	{
		//只要之后函数的返回值不是NULL,就把分割的部分打印出来
		printf("%s\n", pa);
	}
	return 0;
}