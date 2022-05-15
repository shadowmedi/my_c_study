#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
typedef int SListDataType;//单链表的数据类型

typedef struct SListNode //定义单链表的一个结点类型
{
	SListDataType data;     //存放当前结点数据
	struct SListNode* next;//存放下一个结点的地址
}SListNode;

void SListPrint(SListNode* phead);//打印单链表

void SListPushBack(SListNode** phead, SListDataType num);//单链表的尾插

void SListPushFront(SListNode** phead, SListDataType num);//单链表的头插

void SListPopBack(SListNode** phead);//单链表的尾删

void SListPopFront(SListNode** phead);//单链表的头删

SListNode* SListFind(SListNode* phead, SListDataType x);//查找

void SListModify(SListNode* phead, SListDataType x, SListDataType ymdf);//修改

void SListErase(SListNode** phead, SListNode* pos);//删除pos位置的结点

void SListInsert(SListNode** phead, SListNode* pos, SListDataType x);//在pos位置之前插入一个结点



