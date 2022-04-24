#define _CRT_SECURE_NO_WARNINGS
#include "sequence.h"

//初始化顺序表
void SequenceListInit(SL* pa)
{
	assert(pa);
	pa->capacity = 5;
	pa->size = 0;
	pa->ptr = (human*)calloc(5 , sizeof(human));
}

//判断是否需要扩容
void SequenceListJudgeDilation(SL* pa)
{
	assert(pa);
	if (pa->size == pa->capacity)//如果要添加数据时容量已满，扩容
	{
		pa->capacity += 5;
		human* tem = realloc(pa->ptr, (pa->capacity) * sizeof(human));
		if (tem == NULL)
		{
			perror("realloc");
			return;
		}
		pa->ptr = tem;
	}
}

//判断是否需要缩容
void SequenceListJudgeContractancy(SL* pa)
{
	assert(pa);
	if (pa->capacity - pa->size > 5)
	{
		//空间浪费
		pa->capacity -= 5;
		human* tem = (human*)realloc(pa->ptr, pa->capacity);
		if (tem == NULL)
		{
			perror("realloc");
			return;
		}
		pa->ptr = tem;
	}
}

//尾插
void SequenceListPushBack(SL* pa, human data)
{
	assert(pa);
	SequenceListJudgeDilation(pa);//加入数据首先判断是否需要扩容
	pa->ptr[pa->size] = data;
	pa->size++;
}

//尾删
void SequenceListPopBack(SL* pa)
{
	assert(pa && pa->size > 0);//数据不能为0
	pa->size--;
	SequenceListJudgeContractancy(pa);//删除数据后考虑是否需要缩容
}

//头插
void SequenceListPushFront(SL* pa, human data)
{
	assert(pa);
	SequenceListJudgeDilation(pa);//判断是否需要扩容
	//从后往前拷贝数据
	memmove(pa->ptr+1, pa->ptr, sizeof(human) * (pa->size));
	pa->ptr[0] = data;
	pa->size++;
}

//头删