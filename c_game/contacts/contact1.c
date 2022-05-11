#define _CRT_SECURE_NO_WARNINGS
#include "contact1.h"

void menu(void)
{
	printf("****************************\n");
	printf("****************************\n");
	printf("1 add             2 delete        \n");
	printf("3 modify        4 search        \n");
	printf("5 print            0 exit             \n");
	printf("6 clear            7 sort             \n");
	printf("*****************************\n");
	printf("*****************************\n");
}

//�ļ��汾���������ļ�����
void loadData(Contact* con)
{
	FILE*pf = fopen("D:\\cde.txt", "rb");
	if (pf == NULL)
	{
		perror("loadData:fopen");
		return;
	}
	while (fread(&(con->data[con->current]), sizeof(Persons), 1, pf) == 1)
	{
		con->current++;
		expensionContact(con);
	}
	fclose(pf);
}
void initContact(Contact* con)//��ʼ����̬ͨѶ¼
{
	con->current = 0;            //��ǰ����
	con->capacity = TRANS; //����
	con->data = (Persons*)calloc(TRANS, sizeof(Persons));//���붯̬�ռ䣬�׵�ַ��ͨѶ¼��data
	if (con->data == NULL)
	{
		perror("��ʼ��ʧ��");
		return;
	}
	//�ļ��汾���������ļ�����
	loadData(con);
}

//��̬�汾
/*void initContact(Contact* con)
{
	con->current = 0;//�ѱ�����Ŀ��Ϊ0
	memset(con->data,0, sizeof(con->data));//��ʼ��ͨѶ¼ȫ������Ϊ0
}*/

//�ļ��汾 ����ͨѶ¼
void destoryContact(Contact* con)
{
	FILE* pf = fopen("D:\\cde.txt", "wb");
	for (int i = 0; i < con->current; i++)
	{
		fwrite(&(con->data[i]), sizeof(Persons), 1, pf);
	}
	fclose(pf);
}
//��̬�汾

void expensionContact(Contact* con)//�ж��Ƿ�����
{
	if (con->capacity == con->current)//��ǰ������������ͬʱ����
	{
		Persons* tem = (Persons*)realloc(con->data, sizeof(Persons)*(con->capacity + TRANS));
		if (tem == NULL)
		{
			perror("����ʧ�ܣ�expensionContact");
			return;
		}
		con->data = tem;
		con->capacity += TRANS;
	}
}
/*void destoryContact(Contact* con)
{
	//����ͨѶ¼����Ϣ���ļ���
	FILE* pf = fopen("D://cde", "wb");
	if (pf == NULL)
	{
		perror("dextoryContact:fopen");
		return;
	}
	//д�ļ�
	fwrite(con->data, sizeof(Persons), )
	fclose(pf);
}*/

void reduceContact(Contact* con)
{
	if (con->capacity - con->current > 3)//������3�����ϵĿռ�
	{
		Persons* tem = (Persons*)realloc(con->data,sizeof(Persons)*(con->capacity - TRANS));
		if (tem == NULL)
		{
			printf("����ʧ��");
			return;
		}
		con->data = tem;
		con->capacity -= TRANS;
	}
}
void addc(Contact* con)
{
	//��̬�汾
	/*if (con->current == 1000)
	{
		printf("ͨѶ¼�������޷�¼�룡����\n");
		return;
	}*/

	//��̬�汾
	expensionContact(con);//�ж��Ƿ���Ҫ����
	printf("��������ϵ�˵�����:");
	scanf("%s", con->data[con->current].name);
	printf("��������ϵ�˵ĵ绰:");
	scanf("%s", con->data[con->current].telephone);
	printf("��������ϵ�˵ĵ�ַ:");
	scanf("%s", con->data[con->current].addr);
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
	reduceContact(con);
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
	scanf("%s", getname);
	int index = findbyname(con, getname);
	if (index == -1)
	{
		printf("��ϵ�˲����ڣ�����\n");
		return;
	}
	printf("�������޸���Ϣ\n");
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
	scanf("%s", getname);
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

void clearc(Contact* con)
{
	Persons* tem = (Persons*)realloc(con->data, TRANS);
	if (tem == NULL)
	{
		perror("clear:realloc");
		return;
	}
	con->capacity = TRANS;
	con->current = 0;
}

void sortc(Contact* con)
{
	if (con->current == 0)
	{
		printf("�޿������ͨѶ��\n");
		return;
	}
	for (int i = 0; i < con->current - 1; i++)
	{
		int ass = 1;
		for (int k = 0; k < con->current - 1 - i; k++)
		{
			if (strcmp(con->data[k].name, con->data[k + 1].name) > 0)
			{
				//����
				ass = 0;
				Persons tem = con->data[k];
				con->data[k] = con->data[k + 1];
				con->data[k + 1] = tem;
			}
		}
		if (ass == 1)
			return;
	}
}
