#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
int main()
{
	int input;
	do
	{
		menu();
		printf("������0/1:");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("лл���棡����\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("����������������룡����");
		}
	} while (input);
	return 0;
}