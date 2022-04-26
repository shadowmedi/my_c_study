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

//销毁顺序表
void SequenceListDestory(SL* pa)
{
	free(pa->ptr);
	pa->ptr = NULL;
	pa = NULL;
}

//打印
void SequenceListPrint(SL* pa)
{
	assert(pa);
	printf("%-5s%-10s%-5s\n", "年龄", "名字", "性别");
	for (int i = 0; i < pa->size; i++)
	{
		printf("%-5d%-10s%-5s\n", pa->ptr[i].age, pa->ptr[i].name, pa->ptr[i].sex);
	}
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
void SequenceListPushBack(SL* pa, human* data)
{
	assert(pa && data);
	SequenceListJudgeDilation(pa);//加入数据首先判断是否需要扩容
	pa->ptr[pa->size] = *data;
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
void SequenceListPushFront(SL* pa, human* data)
{
	assert(pa && data);
	SequenceListJudgeDilation(pa);//判断是否需要扩容
	//从后往前拷贝数据
	memmove(pa->ptr+1, pa->ptr, sizeof(human) * (pa->size));
	pa->ptr[0] = *data;
	pa->size++;
}

//头删
void SequenceListPopFront(SL* pa)
{
	assert(pa && pa->size > 0);//顺序表元素数目必须大于0
	for (int i = 0; i < pa->size; i++)
	{
		pa->ptr[i] = pa->ptr[i + 1];
	}
	pa->size--;
	SequenceListJudgeContractancy(pa);
}

// 顺序表查找
human* SequenceListSearch(SL* pa, char* name)
{
	for (int i = 0; i < pa->size; i++)
	{
		if (strcmp(name, pa->ptr[i].name) == 0)
		{
			return &(pa->ptr[i]);
		}
	}
	return NULL;//找不到
}

//顺序表修改
void SequenceListModify(SL* pa, char* name, human* modify)//通过名字来找到要修改的人的信息
{
	human* re = NULL;
	re = SequenceListSearch(pa, name);
	if (re == NULL)
	{
		printf("找不到要修改的人！！！");
		return;
	}
	re->age = modify->age;
	strcpy(re->name, modify->name);
	strcpy(re->sex, modify->sex);
}

//在pos位置插入data
void SequenceListInsert(SL* pa, int pos, human* data)
{	
	assert(pos >= 0 && pos <= pa->size);
	SequenceListJudgeDilation(pa);
	if (pos == 0)
		SequenceListPushFront(pa, data);
	else if (pos == pa->size)
		SequenceListPushBack(pa, data);
	else
	{
		for (int i = pa->size - 1; i >= pos; i--)
		{
			//从后往前拷贝
			pa->ptr[i + 1] = pa->ptr[i];
		}
		pa->ptr[pos] = *data;
		pa->size++;
	}
}

// 顺序表删除pos位置的值
void SequenceListErase(SL* pa, int pos)
{
	assert(pos >= 0 && pos < pa->size);
	for (int i = pos; i < pa->size - 1; i++)
	{
		pa->ptr[i] = pa->ptr[i + 1];
	}
	pa->size--;
	SequenceListJudgeContractancy(pa);
}