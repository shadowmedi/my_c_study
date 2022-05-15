#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
typedef int SListDataType;//���������������

typedef struct SListNode //���嵥�����һ���������
{
	SListDataType data;     //��ŵ�ǰ�������
	struct SListNode* next;//�����һ�����ĵ�ַ
}SListNode;

void SListPrint(SListNode* phead);//��ӡ������

void SListPushBack(SListNode** phead, SListDataType num);//�������β��

void SListPushFront(SListNode** phead, SListDataType num);//�������ͷ��

void SListPopBack(SListNode** phead);//�������βɾ

void SListPopFront(SListNode** phead);//�������ͷɾ

SListNode* SListFind(SListNode* phead, SListDataType x);//����

void SListModify(SListNode* phead, SListDataType x, SListDataType ymdf);//�޸�

void SListErase(SListNode** phead, SListNode* pos);//ɾ��posλ�õĽ��

void SListInsert(SListNode** phead, SListNode* pos, SListDataType x);//��posλ��֮ǰ����һ�����



