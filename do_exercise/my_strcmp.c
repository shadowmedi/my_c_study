#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<assert.h>
//��ǰ�������αȽ��ַ���ASCII��ֵ
//���Ƚ����κ�һ��'\0'��ֹ�Ƚ�
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
	printf("%d",my_strcmp(arr1, arr2));//�Ƚ��ַ�����С
	return 0;
}