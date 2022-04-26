#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define NAME_LENGTH 10
#define SEX_LENGTH 5
typedef struct human
{
	int age;            //����
	char name[NAME_LENGTH];//����
	char sex[SEX_LENGTH];      //�Ա�
}human;

typedef human sqtype;//˳����Ԫ�ص�������human

typedef struct seqlist
{
	sqtype* ptr;    //ָ�򿪱ٵĶ�̬�ڴ��׵�ַ
	int capacity;   //˳���ǰ����
	int size;          //��ǰ�Ѵ洢��Ԫ����Ŀ
}SL;

void SequenceListPrint(SL* pa);//��ӡ˳�������


//��˳��������ɾ�Ĳ�
void SequenceListInit(SL* pa);//��˳����ʼ��

void SequenceListJudgeDilation(SL* pa);//�ж��Ƿ���Ҫ����

void SequenceListPushBack(SL* pa, human* data);//β��

void SequenceListPopBack(SL* pa);//βɾ

void SequenceListPopFront(SL* pa);//ͷ��

void SequenceListPopFront(SL* pa);//ͷɾ

human* SequenceListSearch(SL* pa, char* name);//˳������

void SequenceListModify(SL* pa, char* name, human* modify);//˳����޸�

// ˳�����posλ�ò���data
void SequenceListInsert(SL* pa, int pos, human* data);

// ˳���ɾ��posλ�õ�ֵ
void SequenceListErase(SL* pa, int pos);











