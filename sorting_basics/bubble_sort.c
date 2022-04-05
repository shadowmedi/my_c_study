#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<assert.h>
//һ������С��������
//ð�����򣺴��������αȽ����ڵ�Ԫ��,�����Ԫ��>�ұ�Ԫ��,�򻥻�λ��,һ������,
//���԰�max�ŵ����Ҳ�,
//����N��,�����N-1��

void BubbleSort1(int* arr1, int sz)
{
	assert(arr1);
	for (int i = 0; i < sz - 1; i++)//ȷ������
	{
		int ass = 1;//�Ľ�:��һ������û�н��������Ѿ��ź���
		for (int j = 0; j < sz - 1 - i; j++)//һ��Ҫ�Ƚϵ�Ԫ�ض���
		{
			if (arr1[j] > arr1[j + 1])//�����Ԫ��>�ұ�Ԫ��,����
			{
				int tem = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = tem;
				ass = 0;
			}
		}
		if (ass == 1)
			return;
	}
}

//ͨ����ð������
void BubbleSort2(void* arr1, int num, int size, int (*pa)(const void* a, const void* b))
{
	//num-Ԫ�ظ�����size-ÿ��Ԫ�ش�С;
	//int (*pa)(const void*a, const void*b)-ָ������ָ��,�ú�����ר�űȽ�����Ԫ��
	for (int i = 0; i < num - 1; i++)//ȷ������
	{
		int ass = 1;
		for (int j = 0; j < num - 1 - i; j++)//һ����Ҫ�ȽϵĶ���
		{
			if (pa((char*)arr1 + j * size, (char*)arr1 + (j + 1) * size) > 0)//���Ԫ�ظ���
			{
				ass = 0;
				//����λ��
				for (int k = 0; k < size; k++)          //һ���ֽ�һ���ֽڽ���
				{
					char tem = *((char*)arr1 + j*size+k);
					*((char*)arr1 + j* size +k) = *((char*)arr1 + (j+1)*size+k);
					*((char*)arr1 + (j+1)*size+k) = tem;
				}
			}
		}
		if (ass == 1)
			return;
	}
}

int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}
int main()
{
	int arr1[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);//Ԫ�ظ���
	//BubbleSort1(arr1, sz);
	BubbleSort2(arr1, sz, 4, cmp);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
}