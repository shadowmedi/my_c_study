#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>
char* my_strncpy(char* destination, const char* source, size_t count)
{
	//(������)��Դ�ַ����п���count���ֽ�(�ַ�)��Ŀ���ַ�����Ӧλ��
	char* re = destination;
	for (int i = 0; i < count; i++)
	{
		//Ҫ����count��
		if (*source == '\0')//����Ѿ�������Դ�ַ���ĩβ,�Ǿ���'\0'���
		{
			*destination = '\0';
			destination++;
		}
		else//��������
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