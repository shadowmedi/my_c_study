#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//����n,��[1,n]֮���������� ,һ��������������������֮��,
//������ͳ�Ϊ����,����28������1+2+4+7+14=28����28��Ϊһ������)

int judge(int a, int b)
{
	//�ж�a�Ƿ�Ϊb������
	if (b % a == 0)
		return 1;
	else
		return 0;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int k = 1; k <= n; k++)//����1~n
	{
		int sum = 0;                    //�������ӵĺ�
		for (int p = 1; p < k; p++)//�������ӵ����п���
		{
			if (judge(p, k) == 1)
				sum += p;
		}
		if (sum == k)
			printf("%d ", k);
	}
}