#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
//ʵ��strcat() �ַ���׷��
//��Դ�ַ���������׷�ӵ�Ŀ���ַ���ĩβ
//˼·����Դ�ַ�����'\0'��ʼ�޸��ַ�
char* my_strcat(char* dest, const char* source)
{
	assert(dest && source);//���Զ����ǿ�ָ��
	char* re = dest;      //��סĿ���ַ�������λ��
	while (*dest != '\0')//ʹdestָ��'\0'
	{
		dest++;
	}
	while (*dest++ = *source++)//��Դ�ַ��������ݸ���Դ�ַ���
	{                                            //ÿ�θ���һ���ַ�����ַ����ƶ�һλ
		;                                       //���ҵ�Դ�ַ�����'\0'ʱ���Ȱ�������Ŀ���ַ��������˳�ѭ��
	}
	return re;
}
int main()
{
	char source[6] = "efgho";
	char dest[10] = "abci";
	printf("%s\n", my_strcat(dest, source));
	printf("%s\n", dest);
	return 0;
}
//ע�⣺strcat����Ŀ�������Ƿ����㹻�ռ�