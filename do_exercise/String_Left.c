#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>

//˼·1��ѭ��������
//����һ�Σ��ñ�����¼��ߵ�һ���ַ���Ȼ�󽫺�����ַ�������ǰ1��
//���ѱ���ֵ�������һ���ַ�λ��
//���ƶ��ֻ�����ѭ����ָ�����ƵĴ���

//ע�⣺����num���ַ�������k��������k%num�εȼ�

void StringLeft1(char*const pa, int leftnum)
{
	assert(pa);
	int num = 0;
	char* initpa = pa;
	while (*initpa != '\0')           //num��¼�ַ�����
	{
		num++;
		initpa++;
	}
	initpa = NULL;
	for (int k = 0; k < (leftnum % num); k++)
	{
		//��ѭ���ڲ�������һ�ε�Ч��
		char tem = *pa;//��¼��һ���ַ�
		int i = 0;           //���ڵ�1���ַ�����������ǰ��һ��
		while (i < num - 1)
		{
			pa[i] = pa[i + 1];
			i++;
		}
		pa[i] = tem;
	}
}



int main()
{
	int leftnum = 0;
	scanf("%d", &leftnum);
	char arr[5] = "abcd";
	StringLeft1(arr, leftnum);
	printf("%s", arr);
	return 0;
}