#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
void* my_memcpy(void* dest, const void* source, int size_t)
{
	//int size_t��Ҫ���������ݵ��ֽڴ�С
	//˼·:ת��Ϊchar*,һ���ֽ�һ���ֽڵؿ���
	assert(dest && source);
	void* re = dest;
	while (size_t > 0)
	{
		*(char*)dest = *(char*)source;
		dest = (char*)dest + 1;
		source = (char*)source + 1;
		size_t--;
	}
	return re;
}

int main()
{
	int arr1[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arr2[5] = { 0 };
	my_memcpy(arr2, arr1, 5 * sizeof(int));//��arr1��ǰ5�����ֿ�����arr2
	
	return 0;
}