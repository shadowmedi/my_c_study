#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//���ֲ���
//�ڵ��������в���ĳ���������������±�
int BinarySearch(int* pa, int sz, int ser)
{
	int left = 0;
	int right = sz - 1;//����˫�±꣬�ֱ�ָ���һ��Ԫ�غ����һ��Ԫ��
	int mid = left + (right - left) / 2;//ָ���м�Ԫ��
	while (right >= left)        //�����±�>=���±�
	{
		mid = left + (right - left) / 2;//�����м�Ԫ��
		if (pa[mid] > ser)//���м�Ԫ��>Ҫ���ҵ�Ԫ��,˵��Ҫ���ҵ�Ԫ�ص��±���mid���
		{
			right = mid - 1;//��С��Χ���ų�mid�±�֮���������
		}
		else if (pa[mid] < ser)//���м�Ԫ��<Ҫ���ҵ�Ԫ��,˵��Ҫ���ҵ�Ԫ�ص��±���mid�ұ�
		{
			left = mid + 1;//��С��Χ���ų�mid�±�֮ǰ��������
		}
		else
			return mid;
	}
	return -1;//�Ҳ�������-1
}
int main()
{
	int arr[10] = {  1, 2, 3, 4, 5, 6, 7, 8, 9,10 };
	int ser = 0;
	scanf("%d", &ser);
	int sz = sizeof(arr) / sizeof(arr[0]);
	int re =BinarySearch(arr, sz, ser);
	printf("%d", re);
	return 0;
}