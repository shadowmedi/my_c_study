#define _CRT_SECURE_NO_WARNINGS
#include "backgammon.h"

//测试三子棋游戏的逻辑
int main()
{
	int input = 2;
	do
	{
		menu();//主菜单
		scanf("%d", &input);
		while (getchar() != '\n')//若用户输入字母，用getchar()吸收
		{
			input=2;             //同时把输入改为一定是错的
		}
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("输入错误，请重新输入\n");
				break;
		}

	} while (input);
	return 0;
}