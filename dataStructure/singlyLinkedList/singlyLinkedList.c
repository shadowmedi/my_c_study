#define _CRT_SECURE_NO_WARNINGS
#include "singlyLinkedList.h"

void SListPrint(SListNode* phead) //打印单链表
{
	SListNode* current = phead;//当前结点
	while (current != NULL)
	{
		printf("%d->", current->data);
		current = current->next;    //把下一个结点的地址赋给current
	}
	printf("NULL\n");
}

void SListPushBack(SListNode** phead, SListDataType num)//单链表的尾插
{
	assert(phead);
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));//按需申请
	assert(newNode);
	newNode->data = num;
	newNode->next = NULL;
	if((*phead) != NULL)
	{ 
		SListNode* current = *phead;
		//找尾结点
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;//用结构体指针改变结构体内部
	}
	else
	{
		//如果穿过来的头结点是空，说明此时单链表没有数据
		*phead = newNode;
	}
}

void SListPushFront(SListNode** phead, SListDataType num)//单链表的头插
{
	assert(phead);
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	assert(newNode);
	newNode->data = num;
	newNode->next = *phead;
	*phead = newNode;
}

void SListPopBack(SListNode** phead)//单链表的尾删
{
	assert(phead);
	if (*phead == NULL)
	{
		printf("没有可以删除的结点\n");
		return;
	}
	SListNode* current = *phead;
	if (current->next != NULL)
	{
		while (current->next->next != NULL)
		{   //找到尾结点的前一个结点
			current = current->next;
		}
		free(current->next);
		current->next = NULL;
	}
	else
	{
		free(*phead);
		*phead = NULL;
	}
}

void SListPopFront(SListNode** phead)//单链表的头删
{
	assert(phead);
	if (*phead == NULL)
	{
		printf("没有可以删除的结点\n");
		return;
	}
	SListNode* tem = (*phead)->next;
	free(*phead);
	*phead = tem;
}

SListNode* SListFind(SListNode* phead, SListDataType x)//查找
{
	if (phead == NULL)
	{
		return NULL;
	}
	while (phead != NULL)
	{
		if (phead->data == x)
		{
			return phead;
		}
		phead = phead->next;
	}
	return NULL;
}

void SListModify(SListNode* phead, SListDataType x, SListDataType ymdf)//修改
{
	if (phead == NULL)
	{
		printf("没有可以修改的值\n");
		return ;
	}
	SListNode* tem = SListFind(phead, x);
	if (tem == NULL)
	{
		printf("修改失败\n");
	}
	else
	{
		tem->data = ymdf;
	}
}
void SListErase(SListNode** phead, SListNode* pos)//删除pos位置的结点
{
	assert(pos && phead);
	if (pos == *phead)
	{
		//头删
		SListPopFront(phead);
		return;
	}
	SListNode* tem = *phead;
	while (tem != NULL)
	{
		if (tem->next == pos)
		{
			tem->next = pos->next;
			free(pos);
			pos = NULL;
			return;
		}
		tem = tem->next;
	}
}

void SListInsert(SListNode** phead, SListNode* pos, SListDataType x)//在pos位置之前插入一个结点
{
	assert(phead && pos && *phead);
	if (*phead == pos)
	{
		//头插
		SListPushFront(phead, x);
		return;
	}
	else
	{
		SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
		newNode->data = x;
		newNode->next = pos;
		SListNode* tem = *phead;
		while (tem != NULL)
		{
			if (tem->next == pos)
			{
				tem->next = newNode;
				return;
			}
			tem = tem->next;
		}
	}

}