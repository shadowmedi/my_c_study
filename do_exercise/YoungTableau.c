#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ�
//���д�����������ľ����в���ĳ�������Ƿ���ڡ�

//˼·:ÿ�����һ���������ڲ�����,�ų����һ�У�
//��С�ڲ��������ų�һ��

int main()
{
	int arr[3][3] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8} };
	int ser = 0;
	scanf("%d", &ser);
	int col = 2,row = 0;
	while (col>=0 && row <= 2)
	{
		if (arr[row][col] > ser)
		{
			//�ų�һ��
			col--;
		}
		else if (arr[row][col] == ser)
		{
			printf("����");
			break;
		}
		else
		{
			//�ų�һ��
			row++;
		}
	}

	return 0;
}