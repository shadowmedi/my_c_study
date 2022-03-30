#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
//猜数字实现逻辑
int main()
{
	while (1)
	{
		menu();
		printf("请选择1/0：(如果选择0,系统将在60s后关机！！！)");
		int choice = 2;
		scanf("%d", &choice);
		while (getchar() != '\n')
		{
			choice = 2;
		}
		switch (choice)
		{
		case 0:
			system("shutdown -s -t 60");
			printf("感谢游玩！！！\n");
			goto below;
			break;
		case 1:
			game();
			break;
		default:
			printf("输入错误，请重新输入！！！\n");
		}
	}
below:
	;
	return 0;
}