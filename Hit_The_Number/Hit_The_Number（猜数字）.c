#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu(void)
{
	printf("******1 play******\n");
	printf("******0 exit******\n");
}
void game(void)
{
	//ϵͳ�Զ��������ֵ
	int aid=random();
	//�û�������,���Ը����û��µ������жϽϴ���С���¶���ֹͣ;
	hit(aid);
}
int random(void)
{
	srand(time(NULL));
	int i = rand()%(RANGE+1);//Ҫ�µ�Ŀ������
	return i;
}
void hit(int a)
{
	system("shutdown -s -t 60");
	printf("ϵͳ����60s��ػ����¶Ժ��������\n");
	int num = 0;
	printf("��������µ����֣�\n");
	while (1)
	{
		scanf("%d", &num);
		if (num > a)
			printf("�´��ˣ�����\n");
		else if (num < a)
			printf("��С�ˣ�����\n");
		else
		{
			printf("�¶��ˣ�����\n");
			system("shutdown -a");
			break;
		}
	}
}