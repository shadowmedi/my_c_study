#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//1 ������ʱ����
//2 λ���������
//3 ����֮��Ӽ�

void exchange(int* a, int* b)//������ʱ����
{
	int tem = *a;
	*a = *b;
	*b = tem;
}

void bit_operations(int* a, int* b)//λ����
{
	//һ�������2����ͬ������Ȼ��������
	//��λ���֧�ֽ�����
	*a = *a ^ *b;
	*b = *a ^ *b; //�൱��*a ^ *b ^*b,���԰�*a������*b
	*a = *a ^ *b; //�൱��ԭ����*a ^ *b ^ *a�����԰�*b������*a
}

void plus_minus(int* a, int* b)//����֮�����
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	exchange(&a, &b);//�β���ʵ�ε���ʱ��������ַ���ܸı亯����Ĳ���
	//bit_operations(&a, &b);
	//plus_minus(&a, &b);
	printf("a=%d  b=%d", a, b);
	return 0;
}