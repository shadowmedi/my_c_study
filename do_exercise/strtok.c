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
	char str[] = "123456@outlook.com";//����һ������
	char delimiter[] = ".@";
	for (char* pa = strtok(str, delimiter); pa != NULL; pa = strtok(NULL, delimiter))
	{
		//ֻҪ֮�����ķ���ֵ����NULL,�Ͱѷָ�Ĳ��ִ�ӡ����
		printf("%s\n", pa);
	}
	return 0;
}