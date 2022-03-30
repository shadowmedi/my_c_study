#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu(void)
{
	printf("********************\n");
	printf("*******1 play*******\n");
	printf("*******0 exit*******\n");
	printf("********************\n");
}
void game(void)
{
	char mine_board[ROWS][COLS];             //用来存放和布置雷的信息
	char show_board[ROWS][COLS];             //用来给玩家展示排雷的情况
	init_board(mine_board, ROWS, COLS,'0');  //初始化mine棋盘，雷用'1'表示,非雷用'0'表示
	init_board(show_board, ROWS, COLS,'#');  //初始化show棋盘，未排的地区用#表示
	set_mine(mine_board, ROW, COL);          //设置雷
	display(show_board, ROW, COL);           //打印棋盘
	//display(mine_board, ROW, COL);
	find_mine(show_board, mine_board, ROW, COL);
}
void init_board(char board[ROWS][COLS], int rows, int cols, char set)//初始化mine棋盘，雷用'1'表示,非雷用'0'表示
{
	for (int i = 0; i < rows; i++)                                   //初始化show棋盘，未排的地区用#表示
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void set_mine(char myboard[ROWS][COLS], int row, int col)//雷只用设在ROW*COL的范围
{
	int num = 0;
	srand((unsigned int)time(NULL));
	while (num < SETMINE)
	{
		int x = rand() % row + 1;       //任意行
		int y = rand() % col + 1;       //任意列
		if (myboard[x][y] == '0')           //x和y一定是 > 0的
		{
			myboard[x][y] = '1';
			num++;
		}
	}
}
void display(char board[ROWS][COLS], int row, int col)
{
	printf("-----------------扫雷----------------\n");
	for (int i = 0; i <= COL; i++)
	{
		printf("%d ", i);
	}
	putchar('\n');
	for (int i = 1; i <= ROW; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		putchar('\n');
	}
}
void find_mine(char showboard1[ROWS][COLS], char myboard2[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0; //计算已经排完的非雷位置,等把这些位置全部找到，玩家胜出
	while (count < (row * col - SETMINE))
	{
		printf("请输入你的坐标（行/列）:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (myboard2[x][y] == '1')
			{
				printf("游戏结束，你被炸死了！\n");
				display(myboard2, ROW, COL);
				break;
			}
			else   //显示坐标周围的炸弹数目
			{
				count++;
				showboard1[x][y] = num_of_mine(myboard2, x, y)+'0';
				display(showboard1, ROW, COL);
			}//'0'+1='1' '0'+ 3= '3'它们的ASCI码值是相邻的
		}
		else
		{
			printf("坐标非法,请重新输入！！\n");
		}	
	}
	if (count == row*col - SETMINE)
	{
		printf("恭喜你，排雷成功！！！！\n");
	}
}
int num_of_mine(char mineboard[ROWS][COLS], int x, int y)
{
	//因为'1'表示雷，'0'表示非雷
	//'0'-'0' == 0
	//'1'-'0' == 1
	//所以我们可以把附近8个格子的字符全部加起来，再减去8*'0'
	//这里因为ROWS和COLS扩大了棋盘，但我们用的只有ROW*COL范围，这样为排雷提供了方便
	return mineboard[x - 1][y - 1] + 
		mineboard[x - 1][y] + 
		mineboard[x - 1][y + 1] + 
		mineboard[x][y - 1] + 
		mineboard[x][y + 1] + 
		mineboard[x + 1][y - 1] + 
		mineboard[x + 1][y] + 
		mineboard[x + 1][y + 1]- 8*'0';
}