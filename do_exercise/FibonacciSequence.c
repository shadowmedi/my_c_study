#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//쳲��������м�Ӧ��
// 1 �ж�һ�����Ƿ���쳲�����������
// 2 쳲��������еĵ�n������ʲô
// 3 ���쳲�����������С��n��������
// 4 ��֪��һ��¥��N����Слͬѧ���������ߣ�һ��������һ����Ҳ������2�����ʣ����ߵ���n��¥���ж������߷���
// 5 һ������ÿ����������һ��С������������������Ӷ���������ôһ���Ժ���Է�ֳ���ٶ����ӣ�


// 1 1 2 3 5 8 13 ����
//������1������ǰ2����֮��
//a(n) = a(n-1)+a(n-2)

int FBNC1(int x)            //�ж�һ�����Ƿ���쳲�����������
{
	int x1 = 1, x2 = 1, x3 = 0;
	if (x == 1)
		return 1;
	else
	{
		while (x3 < x)    //��ǰ2����һֱ�Ƶ� >= x����
		{
			x3 = x1 + x2; //����3����<x, �����õ���������ǰ2������
			x1 = x2;
			x2 = x3;
		}
		if (x == x3)
			return 1;
		else
			return 0;
	}
}

int FBNC2(int n)        // 쳲��������еĵ�n������ʲô
{
	int x1 = 1, x2 = 1, x3 = 0;
	if (n == 1 || n == 2)
		return 1;
	else
	{
		for (int num = 3; num <= n; num++)
		{
			x3 = x1 + x2;
			x1 = x2;
			x2 = x3;
		}
		return x3;
	}
}

void FBNC3(int x)
{
	int x1 = 0, x2 = 1, x3 = 1;//����쳲��������ж�һ��0������һ��ѭ�����ظ���ӡ����1
	while (x3 < x)
	{
		printf("%d ", x3);
		x3 = x1 + x2;
		x1 = x2;
		x2 = x3;
	}
}

int FBNC4(int n)
{   // 4 ��֪��һ��¥��N����Слͬѧ���������ߣ�һ��������һ����Ҳ������2����
	// �ʣ����ߵ���n��¥���ж������߷���
	//�������ߵ���n��¥���߷���  FBNC4(n - 1)+FBNC4(n - 2), ����Ҳ���Եݹ�
	//����1��:1�֣�����2��:2�֣�����3��:3��;����4��:5��
	int i = 1;
	int ret1 = 1;
	int ret2 = 2;
	int ret3 = 0;
	switch (n)
	{
	case 1:
		return 1;
		break;
	case 2:
		return 2;
		break;
	default:
		for (i = 3; i <= n; i++)
		{
			ret3 = ret1 + ret2;
			ret1 = ret2;
			ret2 = ret3;
		}
		return ret3;
	}
}

int FBNC5(int x)
{
	int init = 2;
	
}
int main()
{
	int x = 0;
	scanf("%d", &x);
	/*if (FBNC1(x) == 1)
	{
		printf("��\n");
	}*/
	//printf("%d", FBNC2(x));
	//FBNC3(x);
	return 0;
}