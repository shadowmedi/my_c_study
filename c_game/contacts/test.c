#define _CRT_SECURE_NO_WARNINGS
#include "contacts.h"
//通讯录: 保存1000个联系人信息
// 功能：
//1 增加联系人
//2 删除联系人
//3 修改联系人
//4 查找联系人
//5 打印
Contact con;//创建一个通讯录

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
			printf("感谢使用！！！\n");
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
		default:
			printf("输入错误，请重新输入！！！");
			break;
		}
	} while(input);
}
int main()
{
	
	test();
	return 0;
}