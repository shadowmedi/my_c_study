#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdbool.h>
#include <math.h>
//�ж�������n�ַ���
//1 �Գ���
bool judge1(int a)
{
	if (a == 2)
		return true;
	else if (a == 1)
		return false;
	else
	{
		for (int i = 2; i <= a - 1; i++)//˼·����2��(a-1)�����Գ�����������������
		{
			if (a % i == 0)
				return false;
		}
		return true;
	}
}

bool judge2(int a)
{
	if (a == 2)
		return true;
	else if (a == 1)
		return false;
	else
	{
		for (int i = 2; i <= sqrt(a); i++)//a���Էֳ�2��������ˣ�����һ������һ��<=sqrt(a)
		{                                  //���<=sqrt(a)����������a���������Ǻ������һ������a������
			if (a % i == 0)
				return false;
		}
		return true;
	}
}


bool judge3(int a)
{
	if (a == 2)
		return true;
	else if (a == 1)
		return false;
	else if(a % 2 == 0)//���ܱ�2������a����2��a�Ͳ�������
	{
		return false;
	}
	else
	{
		for (int i = 3; i <= sqrt(a); i += 2) //��ʱ���ﲻ��Ҫ���%2�ı���
		{
			if (a % i == 0)
				return false;
		}
		return true;
	}
}

//2 ɸѡ��
bool arr[1000] = { 0 };
bool judge4(int a)
{
	for (int i = 0; i <= a; i++)
	{
		arr[i] = true;
	}
	arr[0] = false;
	arr[1] = false;
	for (int n = 2; n < a; n++)
	{
		if (arr[n] == true)
		{
			for (int k = 2; k * n <= a; k++)
			{
				arr[k * n] = false;
			}
		}
	}
	bool re = arr[a];
	return re;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	bool a = judge4(n);
	if (a == true)
	{
		printf("RIGHT\n");
	}

	return 0;
}