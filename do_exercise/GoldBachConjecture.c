#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//2000���ڵĲ�С��4����ż�����ܹ��ֽ�Ϊ��������֮��
//(����֤��°ͺղ����2000���ڵ���ż������)��

int is_leap(int num)//�ж��Ƿ�Ϊ����
{
	if (num == 2)
		return 1;
	else if (num == 1)
		return 0;
	else if (num % 2 == 0)
		return 0;
	else
	{
		for (int i = 3; i <= sqrt(num); i += 2)
		{
			if (num % i == 0)
				return 0;
		}
		return 1;
	}
}
int main()
{
	for (int i = 4; i <= 2000; i += 2)
	{
		int a = 2;
		for (a = 2; a <= i / 2; a++)
		{
			int b = i - a;
			if (is_leap(a) && is_leap(b))     //i�ļ���һ����һ��<=i/2
				printf("%d=%d+%d\n", i, a, b);
		}
	}
	return 0;
}