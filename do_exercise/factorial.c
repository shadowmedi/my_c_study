#define _CRT_SECURE_NO_WARNINGS
//�ú����͵ݹ�ֱ�ʵ����һ�����Ľ׳�
#include <stdio.h>

int factorial1(int a)//����
{
	int ret = 1;
	for (; a > 1; a--)
	{
		ret *= a;
	}
	return ret;
}

int factorial2(int a)//�ݹ�     a! = a* (a-1)!
{
	if (a == 1)
		return 1;
	else
		return a * factorial2(a - 1);
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	int ret = factorial2(a);
	printf("%d", ret);
	return 0;
}