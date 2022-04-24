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
void SequenceListPushBack(SL* pa, human data)
{
	assert(pa);
	SequenceListJudgeDilation(pa);//�������������ж��Ƿ���Ҫ����
	pa->ptr[pa->size] = data;
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
void SequenceListPushFront(SL* pa, human data)
{
	assert(pa);
	SequenceListJudgeDilation(pa);//�ж��Ƿ���Ҫ����
	//�Ӻ���ǰ��������
	memmove(pa->ptr+1, pa->ptr, sizeof(human) * (pa->size));
	pa->ptr[0] = data;
	pa->size++;
}

//ͷɾ