#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�

//��дһ�������ҳ�������ֻ����һ�ε����֡�
int* alone(int num, int arr[])
{
	int single1 = 0;
	int single2 = 0;
	int ret = 0;//��¼��0�������������ֵ
	int i = 0;//��������
	for (i = 0; i < num; i++)
	{
		ret ^= arr[i];
	}
	//���Ľ��������000...011
	//˵��2���������������������λ����ͬ
	//�������һ��������λ������
	//���һ��������λ��1�ķ�Ϊ1��
	//���һ��������λ��0�ķ�Ϊ1��
	//��0�������һ����������ֵ�Ϳ����ҵ�����һ������
	int pos = 0;//��¼ret������λΪ1��λ��
	for (i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)
		{
			pos = i;
			break;
		}
	}
	for (i = 0; i < num; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			single1 ^= arr[i];
		}
	}
	single2 = ret ^ single1;
	int* re = (int*)malloc(sizeof(int) * 2);
	if (re == NULL)
	{
		perror("malloc");
		return NULL;
	}
	else
	{
		re[0] = single1;
		re[1] = single2;
	}
	return re;
}
int main()
{
	int arr[6] = { 33, 33, 56, 56, 33, 76 };
	int num = sizeof(arr) / sizeof(arr[0]);
	int* re =alone(num, arr);
	printf("%d %d", re[0], re[1]);
	free(re);
	re = NULL;
	return 0;
}