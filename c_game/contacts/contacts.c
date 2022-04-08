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
	con->current = 0;//已保存数目设为0
	memset(con->data,0, sizeof(con->data));//初始化通讯录全部数据为0
}

void addc(Contact* con)
{
	if (con->current == 1000)
	{
		printf("通讯录已满，无法录入！！！\n");
		return;
	}
	printf("请输入联系人的名字:");
	scanf("%s",con->data[con->current].name);
	printf("请输入联系人的电话:");
	scanf("%s",con->data[con->current].telephone);
	printf("请输入联系人的地址:");
	scanf("%s",con->data[con->current].addr);
	con->current++;
	printf("录入成功！！！\n");
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
		printf("没有可以删除的联系人！！！\n");
		return;
	}
	printf("请输入要删除的名字:");
	char getname[7] = { 0 };
	scanf("%s", getname);
	int index = findbyname(con, getname);
	if (index == -1)//在通讯录中通过名字找到所在下标
	{
		printf("联系人不存在！！！\n");
		return;
	}
	for (int i = index; i < (con->current) - 1; i++)
	{
		con->data[i] = con->data[i + 1];
	}
	printf("删除成功！！！\n");
	con->current--;
}

void modifyc(Contact* con)
{
	if (con->current == 0)
	{
		printf("没有可以修改的联系人！！！\n");
		return;
	}
	printf("请输入你要修改的联系人姓名:");
	char getname[7] = { 0 };
	gets(getname);
	int index = findbyname(con, getname);
	if (index == -1)
	{
		printf("联系人不存在！！！\n");
		return;
	}
	scanf("%s %s %s", con->data[index].name, con->data[index].addr, con->data[index].telephone);
	printf("修改成功！！！\n");
}

void searchc(const Contact* con)
{
	if (con->current == 0)
	{
		printf("没有可以查找的联系人！！！\n");
		return;
	}
	printf("请输入要查找的联系人名字:");
	char getname[7] = { 0 };
	gets(getname);
	int index = findbyname(con, getname);
	if (index == -1)
	{
		printf("联系人不存在！！！\n");
		return;
	}
	printf("%-7s%-10s%-10s\n", "姓名", "地址", "电话");
	printf("%-7s%-10s%-10s\n", con->data[index].name, con->data[index].addr, con->data[index].telephone);
}

void printc(const Contact* con)
{
	if (con->current == 0)
	{
		printf("没有可以打印的联系人信息！！！\n");
		return;
	}
	printf("%-7s%-10s%-10s\n", "姓名", "地址", "电话");
	for (int i = 0; i < con->current; i++)
	{
		//要打印已经保存的所有联系人信息
		printf("%-6s%-10s%-10s\n", con->data[i].name, con->data[i].addr, con->data[i].telephone);
	}
}









