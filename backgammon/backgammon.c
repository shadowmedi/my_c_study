#define _CRT_SECURE_NO_WARNINGS
#include "backgammon.h"
void menu(void)
{
	printf("************************\n");
	printf("*********0  exit********\n");
	printf("*********1  play********\n");
	printf("************************\n");
	printf("������0/1��\n");
}
void game(void)
{       
	char board[ROW][COL]={0};                  //������ά��������ʾ����
	init_board(board, ROW, COL);               //��ʼ������Ϊȫ�ո�
	while (1)
	{
		display(board, ROW, COL);              //��ӡ����
		player_turn(board, ROW, COL);          //��һغ�
		display(board, ROW, COL);              //��ӡ����
		char result = is_over(board, ROW, COL);//�ж��Ƿ����
		if (result != 'c')
		{
			if (result == 'w')
			{
				printf("���Ӯ��\n");
				break;
			}
			else if (result == 'l')
			{
				printf("����Ӯ��\n");
				break;
			}
			else
			{
				printf("ƽ��\n");
				break;
			}
		}
		computer_turn(board, ROW, COL);        //���ԵĻغ�
		result = is_over(board, ROW, COL);
		if (result != 'c')
		{
			if (result == 'w')
			{
				printf("���Ӯ��\n");
				break;
			}
			else if (result == 'l')
			{
				printf("����Ӯ��\n");
				break;
			}
			else
			{
				printf("ƽ��\n");
			}
		}
	}
}
void init_board(char arr[ROW][COL],int row,int col)
{
	//�Ѷ�ά�����ֵ��ʼ��Ϊ���ո�
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void display(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//��ʾҪ��ӡ������
	{
		int j = 0;
		for (j = 0; j < col; j++)//��ʾһ���д�ӡ������
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		putchar('\n');
		printf("---|---|---\n");
	}
	putchar('\n');
}
void player_turn(char arr[ROW][COL], int row, int col)
{
	printf("�������(�������к���)��\n");
	while (scanf("%d %d", &row, &col)==2)
	{
		if (getchar() != '\n'||row>3||col>3)
		{
			printf("�������,����������\n");
			continue;
		}
		if (arr[row - 1][col - 1] == ' ')
		{
			arr[row - 1][col - 1] = '*';
			break;
		}
		else
			printf("�������ѱ�ռ�ã�����������\n");
	}
}
void computer_turn(char arr[ROW][COL], int row, int col)
{
	printf("�������壺\n");
	while(1)
	{
		srand(time(NULL));
		int row = rand() % 3;
		int col = rand() % 3;
		if (arr[row][col] == ' ')
		{
		arr[row][col] = '#';
		break;
		}
	}
}
char is_over(char arr[ROW][COL], int row, int col)
{
	//����Ӯl��ƽ��p�����Ӯw������c
	int i;
	for (i = 0; i < row; i++)//��һ��������
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] == '#')
		{
			return 'l';
		}
		else if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][2] == '*')
		{
			return 'w';
		}
	}
	for (i = 0; i < col; i++)//��һ��������
	{
		if (arr[0][i] == arr[1][i] && arr[2][i] == arr[1][i] && arr[1][i] == '#')
		{
			return 'l';
		}
		else if (arr[0][i] == arr[1][i] && arr[2][i] == arr[1][i] && arr[0][i] == '*')
		{
			return 'w';
		}
	}
	//�Խ���������
	if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && arr[2][2] == '#')
	{
		return 'l';
	}
	else if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] == '*')
	{
		return 'w';
	}
	else if (arr[0][2] == arr[1][1] && arr[2][0] == arr[1][1] && arr[1][1] == '#')
	{
		return 'l';
	}
	else if (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0] && arr[1][1] == '*')
	{
		return 'w';
	}
	else
		return 'c';

}