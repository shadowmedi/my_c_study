#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<assert.h>
//��ǰ�������αȽ��ַ���ASCII��ֵ
int my_strcmp(const char* arr1, const char* arr2)
{
	assert(arr1 && arr2);
	while (*arr1 == *arr2 )//�������ַ����ʱ,�Ƚ���һ���ַ�
	{
		if (*arr1 == '\0')//��������Ƚϵ�'\0',˵�������ַ������
		{
			return 0;
		}
		arr1++;
		arr2++;
	}
	//���Ƚϵ���һ���ַ������ʱ
	if (*arr1 > *arr2)
		return 1;
	else if (*arr1 < *arr2)
		return -1;
}
int main()
{
	char arr1[5] = "abcd";
	char arr2[7] = "cdefg";
	printf("%d",my_strcmp(arr1, arr2));//�Ƚ��ַ�����С
	return 0;
}