#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
//�������һ������
 

//˼·��������С�����֣�%10������λ��/10��ǰһλ
#include <stdio.h>

void print(int a)//�����
{
	while (a)
	{
		printf("%d", a % 10);
		a /= 10;
	}
}

int reverse_num(int a)//����ֵ��ʽ
{
	
	int n = 0;//���ڼ���λ��
	int tem = a;//����a��ֵ
	int re = 0;//��ʾҪ���ص���
	while (a)//��a�м�λ��
	{
		n++;
		a /= 10;
	}
	while (tem)
	{
		re += (tem % 10)*(int)pow(10, n - 1);
		n--;
		tem /= 10;
	}
	return re;
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	//print(a);
	printf("%d", reverse_num(a));

	return 0;
}
