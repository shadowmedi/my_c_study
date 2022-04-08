#define _CRT_SECURE_NO_WARNINGS
#include "contacts.h"

void menu(void)
{
	printf("****************************\n");
	printf("****************************\n");
	printf("1 add             2 delete        \n");
	printf("3 modify        4 search        \n");
	printf("5 print            0 exit             \n");
	printf("                                            \n");
	printf("*****************************\n");
	printf("*****************************\n");
}

void init(Contact* con)
{
	con->current = 0;//�ѱ�����Ŀ��Ϊ0
	memset(con->data,0, sizeof(con->data));//��ʼ��ͨѶ¼ȫ������Ϊ0
}

void addc(Contact* con)
{
	if (con->current == 1000)
	{
		printf("ͨѶ¼�������޷�¼�룡����\n");
		return;
	}
	printf("��������ϵ�˵�����:");
	scanf("%s",con->data[con->current].name);
	printf("��������ϵ�˵ĵ绰:");
	scanf("%s",con->data[con->current].telephone);
	printf("��������ϵ�˵ĵ�ַ:");
	scanf("%s",con->data[con->current].addr);
	con->current++;
	printf("¼��ɹ�������\n");
	con->current++;
}

int findbyname(const Contact* con, const char* getname)
{
	for (int i = 0; i < con->current; i++)
	{
		if (strcmp(con->data[i].name, getname) == 0)
			return i;
	}
	return -1;
}

void deletec(Contact* con)
{
	if (con->current == 0)
	{
		printf("û�п���ɾ������ϵ�ˣ�����\n");
		return;
	}
	printf("������Ҫɾ��������:");
	char getname[7] = { 0 };
	scanf("%s", getname);
	int index = findbyname(con, getname);
	if (index == -1)//��ͨѶ¼��ͨ�������ҵ������±�
	{
		printf("��ϵ�˲����ڣ�����\n");
		return;
	}
	for (int i = index; i < (con->current) - 1; i++)
	{
		con->data[i] = con->data[i + 1];
	}
	printf("ɾ���ɹ�������\n");
	con->current--;
}

void modifyc(Contact* con)
{
	if (con->current == 0)
	{
		printf("û�п����޸ĵ���ϵ�ˣ�����\n");
		return;
	}
	printf("��������Ҫ�޸ĵ���ϵ������:");
	char getname[7] = { 0 };
	gets(getname);
	int index = findbyname(con, getname);
	if (index == -1)
	{
		printf("��ϵ�˲����ڣ�����\n");
		return;
	}
	scanf("%s %s %s", con->data[index].name, con->data[index].addr, con->data[index].telephone);
	printf("�޸ĳɹ�������\n");
}

void searchc(const Contact* con)
{
	if (con->current == 0)
	{
		printf("û�п��Բ��ҵ���ϵ�ˣ�����\n");
		return;
	}
	printf("������Ҫ���ҵ���ϵ������:");
	char getname[7] = { 0 };
	gets(getname);
	int index = findbyname(con, getname);
	if (index == -1)
	{
		printf("��ϵ�˲����ڣ�����\n");
		return;
	}
	printf("%-7s%-10s%-10s\n", "����", "��ַ", "�绰");
	printf("%-7s%-10s%-10s\n", con->data[index].name, con->data[index].addr, con->data[index].telephone);
}

void printc(const Contact* con)
{
	if (con->current == 0)
	{
		printf("û�п��Դ�ӡ����ϵ����Ϣ������\n");
		return;
	}
	printf("%-7s%-10s%-10s\n", "����", "��ַ", "�绰");
	for (int i = 0; i < con->current; i++)
	{
		//Ҫ��ӡ�Ѿ������������ϵ����Ϣ
		printf("%-6s%-10s%-10s\n", con->data[i].name, con->data[i].addr, con->data[i].telephone);
	}
}









