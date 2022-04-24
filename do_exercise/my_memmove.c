#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
//�����ص��ڴ濽��
void* my_memmove(void* dest, const void* source, int size_t)
{
	assert(dest && source);
	//�����ص��ڴ�ʱ��Ӧ�Ȱ��ص��������ȿ�����Ŀ���ַ���,�Է��ص����ֱ��޸�
	void* re = dest;
	if (dest > source)
	{
		//�ص�����ֻ�ܳ�����Դ�ַ���β��,���Դ�Դ�ַ���ĩ��ǰ����
		while (size_t--)
		{
			*((char*)dest + size_t) = *((char*)source + size_t);
		}
	}
	else if (dest <= source)
	{
		//�ص�����ֻ�ܳ�����Դ�ַ����ײ������Դ�ǰ��󿽱�
		while (size_t)
		{
			*(char*)dest = *(char*)source;
			(char*)dest = (char*)dest + 1;
			(char*)source = (char*)source + 1;
			size_t--;
		}
	}
	return re;
}
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	my_memmove(arr+2, arr , 24);
	//������Ч��:1 2 1 2 3 4 5 6 9 10
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
