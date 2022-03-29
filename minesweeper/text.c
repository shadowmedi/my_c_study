#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
int main()
{
	int input;
	do
	{
		menu();
		printf("请输入0/1:");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("谢谢游玩！！！\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("输入错误，请重新输入！！！");
		}
	} while (input);
	return 0;
}