#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
//������ʵ���߼�
int main()
{
	while (1)
	{
		menu();
		printf("��ѡ��1/0��(���ѡ��0,ϵͳ����60s��ػ�������)");
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
			printf("��л���棡����\n");
			goto below;
			break;
		case 1:
			game();
			break;
		default:
			printf("����������������룡����\n");
		}
	}
below:
	;
	return 0;
}