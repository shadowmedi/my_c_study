#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<assert.h>
int my_strlen1(const char* arr)
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

size_t my_strlen(const char* arr)
{
	assert(arr);//���Բ�Ϊ��ָ��
	if (*arr == '\0')
		return 0;
	else
		return 1 + my_strlen(arr + 1);
}

size_t my_strlen3(const char* arr)
{
	assert(arr);//���Բ�Ϊ��ָ��
	const char* init = arr;//����arr�ĳ�ʼֵ
	while (*arr)//ʹarrָ��'\0'
	{
		arr++;
	}
	size_t num = arr - init;//����ָ������õ�����֮���Ԫ�ظ���
	return num;
}
int main()
{
	char arr1[10] = "abc";
	printf("%d", (int)my_strlen3(arr1));
	return 0;
}