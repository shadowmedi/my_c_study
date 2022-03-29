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
	char mine_board[ROWS][COLS];             //������źͲ����׵���Ϣ
	char show_board[ROWS][COLS];             //���������չʾ���׵����
	init_board(mine_board, ROWS, COLS,'0');  //��ʼ��mine���̣�����'1'��ʾ,������'0'��ʾ
	init_board(show_board, ROWS, COLS,'#');  //��ʼ��show���̣�δ�ŵĵ�����#��ʾ
	set_mine(mine_board, ROW, COL);          //������
	display(show_board, ROW, COL);           //��ӡ����
	//display(mine_board, ROW, COL);
	find_mine(show_board, mine_board, ROW, COL);
}
void init_board(char board[ROWS][COLS], int rows, int cols, char set)//��ʼ��mine���̣�����'1'��ʾ,������'0'��ʾ
{
	for (int i = 0; i < rows; i++)                                   //��ʼ��show���̣�δ�ŵĵ�����#��ʾ
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void set_mine(char myboard[ROWS][COLS], int row, int col)//��ֻ������ROW*COL�ķ�Χ
{
	int num = 0;
	srand((unsigned int)time(NULL));
	while (num < SETMINE)
	{
		int x = rand() % row + 1;       //������
		int y = rand() % col + 1;       //������
		if (myboard[x][y] == '0')           //x��yһ���� > 0��
		{
			myboard[x][y] = '1';
			num++;
		}
	}
}
void display(char board[ROWS][COLS], int row, int col)
{
	printf("-----------------ɨ��----------------\n");
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
	int count = 0; //�����Ѿ�����ķ���λ��,�Ȱ���Щλ��ȫ���ҵ������ʤ��
	while (count < (row * col - SETMINE))
	{
		printf("������������꣨��/�У�:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (myboard2[x][y] == '1')
			{
				printf("��Ϸ�������㱻ը���ˣ�\n");
				display(myboard2, ROW, COL);
				break;
			}
			else   //��ʾ������Χ��ը����Ŀ
			{
				count++;
				showboard1[x][y] = num_of_mine(myboard2, x, y)+'0';
				display(showboard1, ROW, COL);
			}//'0'+1='1' '0'+ 3= '3'���ǵ�ASCI��ֵ�����ڵ�
		}
		else
		{
			printf("����Ƿ�,���������룡��\n");
		}	
	}
	if (count == row*col - SETMINE)
	{
		printf("��ϲ�㣬���׳ɹ���������\n");
	}
}
int num_of_mine(char mineboard[ROWS][COLS], int x, int y)
{
	//��Ϊ'1'��ʾ�ף�'0'��ʾ����
	//'0'-'0' == 0
	//'1'-'0' == 1
	//�������ǿ��԰Ѹ���8�����ӵ��ַ�ȫ�����������ټ�ȥ8*'0'
	//������ΪROWS��COLS���������̣��������õ�ֻ��ROW*COL��Χ������Ϊ�����ṩ�˷���
	return mineboard[x - 1][y - 1] + 
		mineboard[x - 1][y] + 
		mineboard[x - 1][y + 1] + 
		mineboard[x][y - 1] + 
		mineboard[x][y + 1] + 
		mineboard[x + 1][y - 1] + 
		mineboard[x + 1][y] + 
		mineboard[x + 1][y + 1]- 8*'0';
}