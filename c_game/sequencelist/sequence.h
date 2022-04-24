#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define NAME_LENGTH 10
#define SEX_LENGTH 5
typedef struct human
{
	int age;            //年龄
	char name[NAME_LENGTH];//姓名
	char sex[SEX_LENGTH];      //性别
}human;

typedef human sqtype;//顺序表的元素的类型是human

typedef struct seqlist
{
	sqtype* ptr;    //指向人的指针类型
	int capacity;   //顺序表当前容量
	int size;          //当前已存储的元素数目
}SL;

//对顺序表进行增删改查
void SequenceListInit(SL* pa);//对顺序表初始化

void SequenceListJudgeDilation(SL* pa);//判断是否需要扩容

void SequenceListPushBack(SL* pa, human data);//尾插

void SequenceListPopBack(SL* pa);//尾删

void SequenceListPushBack(SL* pa, human data);//头插












