#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
int my_strlen(const char* arr)
{
	assert(arr);//���Բ�Ϊ��ָ��
	int num = 0;//ͳ����Ŀ
	while (*arr++)//���ȿ�*arr�Ƿ�Ϊ'\0'��Ȼ��arr++
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