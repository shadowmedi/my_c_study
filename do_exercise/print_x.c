#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_ROW 20
#define MAX_COL 20
//˼·1:������̬���鲢��ӡ
//˼·2:ֱ�Ӵ�ӡ
int main()
{
	int n = 0;
	while(~scanf("%d", &n))
	{
		char arr1[MAX_ROW][MAX_COL] = { 0 };
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				if (row + col == n - 1 || row == col)
				{
					arr1[row][col] = '*';
					printf("%c", arr1[row][col]);
				}
				else
				{
					arr1[row][col] = ' ';
					printf("%c", arr1[row][col]);
				}
			}
			putchar('\n');//��ӡ��һ�к���
		}
	}
	return 0;
}
/*int main()
{
	int n = 0;
	while (~scanf("%d", &n))
	{
		for (int row = 1; row <= n; row++)
		{
			for (int col = 1; col <= n; col++)
			{
				if (row == col || row + col == n + 1)
				{
					printf("*");
				}
				else
					printf(" ");
			}
			putchar('\n');//��ӡ��һ�к���
		}
	}
	return 0;
}*/