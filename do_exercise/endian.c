#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//����ֽ���洢�����ݵĵ�λ�ֽڴ��洢�ڸߵ�ַ������λ�ֽڴ��洢�ڵ͵�ַ��

//С���ֽ���洢�����ݵĵ�λ�ֽڴ��洢�ڵ͵�ַ������λ�ֽڴ��洢�ڸߵ�ַ��

int judge_sys1(void)
{
	//�жϴ�С�˵ĺ���
	int a = 1;
	if (*(char*)&a == 1)//�����λ���ڵ͵�ַ��
	{
		return 1;//С��
	}
	else
		return 0;//���
}

int judge_sys2(void)
{
	int a = 1;
	//С��01 00 00 00
	//���00 00 00 01
	return *(char*)&a;  //С�˷���1,��˷���0
}
int main()
{
	printf("%d", judge_sys2());
	return 0;
}