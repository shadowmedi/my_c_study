#define _CRT_SECURE_NO_WARNINGS
#include "singlyLinkedList.h"

void SListPrint(SListNode* phead) //��ӡ������
{
	SListNode* current = phead;//��ǰ���
	while (current != NULL)
	{
		printf("%d->", current->data);
		current = current->next;    //����һ�����ĵ�ַ����current
	}
	printf("NULL\n");
}

void SListPushBack(SListNode** phead, SListDataType num)//�������β��
{
	assert(phead);
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));//��������
	assert(newNode);
	newNode->data = num;
	newNode->next = NULL;
	if((*phead) != NULL)
	{ 
		SListNode* current = *phead;
		//��β���
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;//�ýṹ��ָ��ı�ṹ���ڲ�
	}
	else
	{
		//�����������ͷ����ǿգ�˵����ʱ������û������
		*phead = newNode;
	}
}

void SListPushFront(SListNode** phead, SListDataType num)//�������ͷ��
{
	assert(phead);
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	assert(newNode);
	newNode->data = num;
	newNode->next = *phead;
	*phead = newNode;
}

void SListPopBack(SListNode** phead)//�������βɾ
{
	assert(phead);
	if (*phead == NULL)
	{
		printf("û�п���ɾ���Ľ��\n");
		return;
	}
	SListNode* current = *phead;
	if (current->next != NULL)
	{
		while (current->next->next != NULL)
		{   //�ҵ�β����ǰһ�����
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

void SListPopFront(SListNode** phead)//�������ͷɾ
{
	assert(phead);
	if (*phead == NULL)
	{
		printf("û�п���ɾ���Ľ��\n");
		return;
	}
	SListNode* tem = (*phead)->next;
	free(*phead);
	*phead = tem;
}

SListNode* SListFind(SListNode* phead, SListDataType x)//����
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

void SListModify(SListNode* phead, SListDataType x, SListDataType ymdf)//�޸�
{
	if (phead == NULL)
	{
		printf("û�п����޸ĵ�ֵ\n");
		return ;
	}
	SListNode* tem = SListFind(phead, x);
	if (tem == NULL)
	{
		printf("�޸�ʧ��\n");
	}
	else
	{
		tem->data = ymdf;
	}
}
void SListErase(SListNode** phead, SListNode* pos)//ɾ��posλ�õĽ��
{
	assert(pos && phead);
	if (pos == *phead)
	{
		//ͷɾ
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

void SListInsert(SListNode** phead, SListNode* pos, SListDataType x)//��posλ��֮ǰ����һ�����
{
	assert(phead && pos && *phead);
	if (*phead == pos)
	{
		//ͷ��
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