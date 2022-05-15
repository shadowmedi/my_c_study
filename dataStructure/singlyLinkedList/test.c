#define _CRT_SECURE_NO_WARNINGS
#include "singlyLinkedList.h"

void test1SList()//基本链表的链接
{
	SListNode* n1 = NULL;
	SListPushFront(&n1, 3);
	SListPushFront(&n1, 4);
	SListPushFront(&n1, 99);
	SListPrint(n1);
	/*SListPopFront(&n1);
	SListPrint(n1);
	SListPopFront(&n1);
	SListPrint(n1);
	SListPopFront(&n1);
	SListPrint(n1);
	SListPopFront(&n1);*/
	SListNode* tem = SListFind(n1, 3);
	if (tem == NULL)
	{
		printf("查找失败\n");
	}
	else
	{
		SListInsert(&n1, tem, 77);
	}
	//SListModify(n1, 3, 55);
	SListPrint(n1);
}

int main()
{
	test1SList();
	return 0;
}