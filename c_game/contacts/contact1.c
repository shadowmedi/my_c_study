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

//文件版本——加载文件数据
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
void initContact(Contact* con)//初始化动态通讯录
{
	con->current = 0;            //当前人数
	con->capacity = TRANS; //容量
	con->data = (Persons*)calloc(TRANS, sizeof(Persons));//申请动态空间，首地址给通讯录的data
	if (con->data == NULL)
	{
		perror("初始化失败");
		return;
	}
	//文件版本——加载文件数据
	loadData(con);
}

//静态版本
/*void initContact(Contact* con)
{
	con->current = 0;//已保存数目设为0
	memset(con->data,0, sizeof(con->data));//初始化通讯录全部数据为0
}*/

//文件版本 保存通讯录
void destoryContact(Contact* con)
{
	FILE* pf = fopen("D:\\cde.txt", "wb");
	for (int i = 0; i < con->current; i++)
	{
		fwrite(&(con->data[i]), sizeof(Persons), 1, pf);
	}
	fclose(pf);
}
//动态版本

void expensionContact(Contact* con)//判断是否扩容
{
	if (con->capacity == con->current)//当前人数与容量相同时扩容
	{
		Persons* tem = (Persons*)realloc(con->data, sizeof(Persons)*(con->capacity + TRANS));
		if (tem == NULL)
		{
			perror("扩容失败！expensionContact");
			return;
		}
		con->data = tem;
		con->capacity += TRANS;
	}
}
/*void destoryContact(Contact* con)
{
	//保存通讯录的信息到文件中
	FILE* pf = fopen("D://cde", "wb");
	if (pf == NULL)
	{
		perror("dextoryContact:fopen");
		return;
	}
	//写文件
	fwrite(con->data, sizeof(Persons), )
	fclose(pf);
}*/

void reduceContact(Contact* con)
{
	if (con->capacity - con->current > 3)//如果多出3个以上的空间
	{
		Persons* tem = (Persons*)realloc(con->data,sizeof(Persons)*(con->capacity - TRANS));
		if (tem == NULL)
		{
			printf("缩容失败");
			return;
		}
		con->data = tem;
		con->capacity -= TRANS;
	}
}
void addc(Contact* con)
{
	//静态版本
	/*if (con->current == 1000)
	{
		printf("通讯录已满，无法录入！！！\n");
		return;
	}*/

	//动态版本
	expensionContact(con);//判断是否需要扩容
	printf("请输入联系人的名字:");
	scanf("%s", con->data[con->current].name);
	printf("请输入联系人的电话:");
	scanf("%s", con->data[con->current].telephone);
	printf("请输入联系人的地址:");
	scanf("%s", con->data[con->current].addr);
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
	reduceContact(con);
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
	scanf("%s", getname);
	int index = findbyname(con, getname);
	if (index == -1)
	{
		printf("联系人不存在！！！\n");
		return;
	}
	printf("请输入修改信息\n");
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
	scanf("%s", getname);
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
		printf("无可排序的通讯人\n");
		return;
	}
	for (int i = 0; i < con->current - 1; i++)
	{
		int ass = 1;
		for (int k = 0; k < con->current - 1 - i; k++)
		{
			if (strcmp(con->data[k].name, con->data[k + 1].name) > 0)
			{
				//交换
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
