#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu(void)
{
	printf("******1 play******\n");
	printf("******0 exit******\n");
}
void game(void)
{
	//系统自动生成随机值
	int aid=random();
	//用户猜数字,电脑根据用户猜的数字判断较大或较小，猜对了停止;
	hit(aid);
}
int random(void)
{
	srand(time(NULL));
	int i = rand()%(RANGE+1);//要猜的目标数字
	return i;
}
void hit(int a)
{
	system("shutdown -s -t 60");
	printf("系统将在60s后关机，猜对后解除该命令！\n");
	int num = 0;
	printf("请输入你猜的数字：\n");
	while (1)
	{
		scanf("%d", &num);
		if (num > a)
			printf("猜大了！！！\n");
		else if (num < a)
			printf("猜小了！！！\n");
		else
		{
			printf("猜对了！！！\n");
			system("shutdown -a");
			break;
		}
	}
}