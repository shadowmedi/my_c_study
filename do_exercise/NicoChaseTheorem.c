#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//�κ�һ������ m ������������д�� m ����������֮�͡�
//����һ�������� m��m��100�� ���� m ������д�� m ����������֮�͵���ʽ�����

int sum1(int x, int y)
{
	//y����x��ʼ����������֮��
	int sum = 0;
	if (x % 2 == 0)//��Ϊż�������ĳ�����
		x += 1;
	for (int i = 0; i < y; i++)//ȷ�����y��
	{
		sum += x + 2 * i;
	}
	return sum;
}
int main()
{
	int m = 0;
	scanf("%d", &m);
	int n = (int)pow(m, 3);
	int k = 1;
	for (k = 1; k <= n / 3; k += 2)
	{
		if (sum1(k, m) == n)//ȷ����ӵ����
		{
			break;
		}
	}
	printf("%d", k);
	for (int t = 1; t < m; t++)//ʣ�µļ���ֻ��(m - 1)��
	{
		printf("+%d", k + 2 * t);
	}
	return 0;
}