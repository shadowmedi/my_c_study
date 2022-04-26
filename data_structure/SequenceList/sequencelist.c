#define _CRT_SECURE_NO_WARNINGS
#include "sequence.h"

//��ʼ��˳���
void SequenceListInit(SL* pa)
{
	assert(pa);
	pa->capacity = 5;
	pa->size = 0;
	pa->ptr = (human*)calloc(5 , sizeof(human));
}

//����˳���
void SequenceListDestory(SL* pa)
{
	free(pa->ptr);
	pa->ptr = NULL;
	pa = NULL;
}

//��ӡ
void SequenceListPrint(SL* pa)
{
	assert(pa);
	printf("%-5s%-10s%-5s\n", "����", "����", "�Ա�");
	for (int i = 0; i < pa->size; i++)
	{
		printf("%-5d%-10s%-5s\n", pa->ptr[i].age, pa->ptr[i].name, pa->ptr[i].sex);
	}
}

//�ж��Ƿ���Ҫ����
void SequenceListJudgeDilation(SL* pa)
{
	assert(pa);
	if (pa->size == pa->capacity)//���Ҫ�������ʱ��������������
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

//�ж��Ƿ���Ҫ����
void SequenceListJudgeContractancy(SL* pa)
{
	assert(pa);
	if (pa->capacity - pa->size > 5)
	{
		//�ռ��˷�
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

//β��
void SequenceListPushBack(SL* pa, human* data)
{
	assert(pa && data);
	SequenceListJudgeDilation(pa);//�������������ж��Ƿ���Ҫ����
	pa->ptr[pa->size] = *data;
	pa->size++;
}

//βɾ
void SequenceListPopBack(SL* pa)
{
	assert(pa && pa->size > 0);//���ݲ���Ϊ0
	pa->size--;
	SequenceListJudgeContractancy(pa);//ɾ�����ݺ����Ƿ���Ҫ����
}

//ͷ��
void SequenceListPushFront(SL* pa, human* data)
{
	assert(pa && data);
	SequenceListJudgeDilation(pa);//�ж��Ƿ���Ҫ����
	//�Ӻ���ǰ��������
	memmove(pa->ptr+1, pa->ptr, sizeof(human) * (pa->size));
	pa->ptr[0] = *data;
	pa->size++;
}

//ͷɾ
void SequenceListPopFront(SL* pa)
{
	assert(pa && pa->size > 0);//˳���Ԫ����Ŀ�������0
	for (int i = 0; i < pa->size; i++)
	{
		pa->ptr[i] = pa->ptr[i + 1];
	}
	pa->size--;
	SequenceListJudgeContractancy(pa);
}

// ˳������
human* SequenceListSearch(SL* pa, char* name)
{
	for (int i = 0; i < pa->size; i++)
	{
		if (strcmp(name, pa->ptr[i].name) == 0)
		{
			return &(pa->ptr[i]);
		}
	}
	return NULL;//�Ҳ���
}

//˳����޸�
void SequenceListModify(SL* pa, char* name, human* modify)//ͨ���������ҵ�Ҫ�޸ĵ��˵���Ϣ
{
	human* re = NULL;
	re = SequenceListSearch(pa, name);
	if (re == NULL)
	{
		printf("�Ҳ���Ҫ�޸ĵ��ˣ�����");
		return;
	}
	re->age = modify->age;
	strcpy(re->name, modify->name);
	strcpy(re->sex, modify->sex);
}

//��posλ�ò���data
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
			//�Ӻ���ǰ����
			pa->ptr[i + 1] = pa->ptr[i];
		}
		pa->ptr[pos] = *data;
		pa->size++;
	}
}

// ˳���ɾ��posλ�õ�ֵ
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