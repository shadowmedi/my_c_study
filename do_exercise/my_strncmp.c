#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <stdio.h>
int my_strncmp(char* str1, char* str2, size_t num)
{
	assert(str1 && str2);
	for (int i = 0; i < num; i++)
	{
		//比较num对

		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else if (*str1 > *str2)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	//比较完num对后都是相等的
	return 0;
}
int main()
{
	char arr1[] = "abcd";
	char arr2[] = "abcf";
	printf("%d", my_strncmp(arr1, arr2, 3));
	return 0;
}