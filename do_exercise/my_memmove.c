#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
//允许重叠内存拷贝
void* my_memmove(void* dest, const void* source, int size_t)
{
	assert(dest && source);
	//出现重叠内存时，应先把重叠部分优先拷贝给目标字符串,以防重叠部分被修改
	void* re = dest;
	if (dest > source)
	{
		//重叠部分只能出现在源字符串尾部,所以从源字符串末向前拷贝
		while (size_t--)
		{
			*((char*)dest + size_t) = *((char*)source + size_t);
		}
	}
	else if (dest <= source)
	{
		//重叠部分只能出现在源字符串首部，所以从前向后拷贝
		while (size_t)
		{
			*(char*)dest = *(char*)source;
			(char*)dest = (char*)dest + 1;
			(char*)source = (char*)source + 1;
			size_t--;
		}
	}
	return re;
}
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	my_memmove(arr+2, arr , 24);
	//拷贝后效果:1 2 1 2 3 4 5 6 9 10
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
