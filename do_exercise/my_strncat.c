#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>

char* my_strncat(char* destination, char* source, size_t num)
{
	//��Դ�ַ�����num���ַ�׷�ӵ�Ŀ���ַ�����һ��'\0'��
	//��Դ�ַ���׷������ֹͣ
	char* re = destination;//����Ŀ���ַ�����ʼֵ
	while (*destination)//ʹ*destination�ҵ�'\0'
	{
		destination++;
	}
	//��ʼ׷��
	for (int i = 0; i < num; i++)
	{
		//׷��num���ַ�
		if (*source != '\0')//����׷��
		{
			*destination = *source;
			destination++;
			source++;
		}
		else if(*source == '\0')//Դ�ַ����Ѿ�ȫ��׷������
		{
			*destination = *source;
			return re;//ֱ�ӽ�������
		}
	}
	//׷�ӵ�num���ַ���û��'\0'
	*destination = '\0';//ĩβ�Զ����'\0'
	return re;
}
int main()
{
	char arr1[20] = "a\0xxxxxxxxxxx";
	char arr2[5] = "abcd";
	//strncat(arr1, arr2, 5);
	printf("%s",my_strncat(arr1, arr2, 4));

	return 0;
}