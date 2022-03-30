#define _CRT_SECURE_NO_WARNINGS
#include "backgammon.h"
void menu(void)
{
	printf("************************\n");
	printf("*********0  exit********\n");
	printf("*********1  play********\n");
	printf("************************\n");
	printf("请输入0/1：\n");
}
void game(void)
{       
	char board[ROW][COL]={0};                  //创建二维数组来表示棋盘
	init_board(board, ROW, COL);               //初始化棋盘为全空格
	while (1)
	{
		display(board, ROW, COL);              //打印棋盘
		player_turn(board, ROW, COL);          //玩家回合
		display(board, ROW, COL);              //打印棋盘
		char result = is_over(board, ROW, COL);//判断是否结束
		if (result != 'c')
		{
			if (result == 'w')
			{
				printf("玩家赢了\n");
				break;
			}
			else if (result == 'l')
			{
				printf("电脑赢了\n");
				break;
			}
			else
			{
				printf("平局\n");
				break;
			}
		}
		computer_turn(board, ROW, COL);        //电脑的回合
		result = is_over(board, ROW, COL);
		if (result != 'c')
		{
			if (result == 'w')
			{
				printf("玩家赢了\n");
				break;
			}
			else if (result == 'l')
			{
				printf("电脑赢了\n");
				break;
			}
			else
			{
				printf("平局\n");
			}
		}
	}
}
void init_board(char arr[ROW][COL],int row,int col)
{
	//把二维数组的值初始化为‘空格’
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
	for (i = 0; i < row; i++)//表示要打印多少行
	{
		int j = 0;
		for (j = 0; j < col; j++)//表示一行中打印的内容
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
	printf("玩家下棋(请输入行和列)：\n");
	while (scanf("%d %d", &row, &col)==2)
	{
		if (getchar() != '\n'||row>3||col>3)
		{
			printf("输入错误,请重新输入\n");
			continue;
		}
		if (arr[row - 1][col - 1] == ' ')
		{
			arr[row - 1][col - 1] = '*';
			break;
		}
		else
			printf("该坐标已被占用，请重新输入\n");
	}
}
void computer_turn(char arr[ROW][COL], int row, int col)
{
	printf("电脑下棋：\n");
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
	//电脑赢l、平局p、玩家赢w、继续c
	int i;
	for (i = 0; i < row; i++)//有一行连成线
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
	for (i = 0; i < col; i++)//有一列连成线
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
	//对角线连成线
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