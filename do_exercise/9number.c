#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//˼·��ѭ�����������Χ����%10ȡ�ø�λ�����֣���/10�������λ��ֱ����Ϊ0
//bug��Ҫ��ѭ����ı�ѭ������
int main()
{
	int min = 0;
	int max = 0;
	int num = 0;//����9�ĸ���
	scanf("%d %d", &min, &max);
	int initmin = min;//��ֹ�ı�min
	for (; initmin <= max; initmin++)
	{
		//�ж����е�һ�������ж��ٸ�9
		int tem = initmin;
		while (tem)
		{
			if (tem % 10 == 9)
				num++;
			tem /= 10;
		}
	}
	printf("%d", num);
	return 0;
}