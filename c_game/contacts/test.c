#define _CRT_SECURE_NO_WARNINGS
#include "contacts.h"
//ͨѶ¼: ����1000����ϵ����Ϣ
// ���ܣ�
//1 ������ϵ��
//2 ɾ����ϵ��
//3 �޸���ϵ��
//4 ������ϵ��
//5 ��ӡ
//6�����ϵ��
//7����������������ϵ��
Contact con;//����һ��ͨѶ¼

void test(void)
{
	
	int input = 0;	
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case exit:
			printf("��лʹ�ã�����\n");
			break;
		case add:
			addc(&con);
			break;
		case delete:
			deletec(&con);
			break;
		case modify:
			modifyc(&con);
			break;
		case search:
			searchc(&con);
			break;
		case print:
			printc(&con);
			break;
		case clear:
			clearc(&con);
			break;
		case sort:
			sortc(&con);
			break;
		default:
			printf("����������������룡����");
			break;
		}
	} while(input);
}
int main()
{
	
	test();
	return 0;
}