#define _CRT_SECURE_NO_WARNINGS
#include "backgammon.h"

//������������Ϸ���߼�
int main()
{
	int input = 2;
	do
	{
		menu();//���˵�
		scanf("%d", &input);
		while (getchar() != '\n')//���û�������ĸ����getchar()����
		{
			input=2;             //ͬʱ�������Ϊһ���Ǵ��
		}
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("�����������������\n");
				break;
		}

	} while (input);
	return 0;
}