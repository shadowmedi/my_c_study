#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//����һ��������n(3~7),�������nλˮ�ɻ�����

//ˮ�ɻ�����ָһ��nλ������,���ĸ�λ���ֵ�n����֮�͵���������

//��153 = 1^3+5^3+3^3

//˼·��ģ10ȡλ,��pow����ȡ��max��min,ѭ�����������Χ��
/*
int main()
{
	int n = 0;
	scanf("%d", &n);
	int max = (int)pow(10, n) - 1;
	int min = (int)pow(10, n - 1);
	for (; min <= max; min++)
	{
		int sum = 0, tem = min;
		while (tem)
		{
			sum += (int)pow(tem % 10, n);
			tem /= 10;
		}
		if (sum == min)
			printf("%d\n", sum);
	}
	return 0;
}*/

//����ˮ�ɻ���
//��������������֣����м��ֳ��������֣�
// ����1461 ���Բ�ֳɣ�1��461��,��14��61��,��146��1),
// ������в�ֺ�ĳ˻�֮�͵�����������һ������ˮ�ɻ�����
//���磺655 = 6 * 55 + 65 * 5

int judge(int x)
{
	int n = 0;//��¼λ��
	int tem = x;
	while (tem)
	{
		n++;
		tem /= 10;
	}

	int sum = 0;//��¼�˻�֮��
	while (n>1)
	{
		sum += (x % (int)pow(10, n-1)) * (x / (int)pow(10, n-1));
		n--;
	}
	if(sum == x)
		return 1;
	return 0;
}
int main()
{
	//�ж��Ƿ�Ϊ����ˮ�ɻ���
	int x = 0;
	scanf("%d", &x);
	int a = judge(x);
	if (a == 1)
		printf("YES");
	return 0;
}