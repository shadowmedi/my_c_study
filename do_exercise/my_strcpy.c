#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
//��Դ�ַ���������Ŀ���ַ���

char* my_strcpy(char* dest,const char* source)
{
	assert(dest && source);//���ԽԲ�Ϊ��ָ��
	char* re = dest; //������󷵻�Ŀ���ַ����׵�ַ
	while (*dest++ = *source++)//�Ȱ�sourceָ����ַ�����destָ��λ��,��ʹ���ǵ�ָ��λ�����һλ��	
	{                                             //ֱ����'\0'����dest
		;
	}
	return re;
}

int main()
{
	char dest[10] = "abcd";
	char source[5] = "efgh";

	printf("%s", my_strcpy(dest, source));
	return 0;
}