#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//�˷��ھ����ӡ
//˼·��һ�д�ӡ��ʽ����==��ǰ��������
int main()
{
	int row, col;
	scanf("%d", &row);
	/*for (int i = 1; i <= row; i++)
	{
		for (int p = 1; p <= i; p++)
		{
			printf("%-d��%-d=%-2d  ", i, p, i * p);
		}
		putchar('\n');
	}*/
	/*for (int i = 1; i <= row; i++)
	{
		for (int p = 1; p <= row - i + 1; p++)
		{
			printf("%d��%d=%-2d  ", i, p, i * p);
		}
		putchar('\n');
	}*/
	for (int i = 1; i <= row; i++)//��׼��
	{
		for (int p = 1; p <= i; p++)
		{
			printf("%d��%d=%-2d  ", p, i, p * i);
		}
		putchar('\n');
	}
	return 0;
}