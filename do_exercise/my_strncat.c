#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>

char* my_strncat(char* destination, char* source, size_t num)
{
	//将源字符串的num个字符追加到目标字符串第一个'\0'处
	//若源字符串追加完则停止
	char* re = destination;//保存目标字符串初始值
	while (*destination)//使*destination找到'\0'
	{
		destination++;
	}
	//开始追加
	for (int i = 0; i < num; i++)
	{
		//追加num个字符
		if (*source != '\0')//正常追加
		{
			*destination = *source;
			destination++;
			source++;
		}
		else if(*source == '\0')//源字符串已经全部追加完了
		{
			*destination = *source;
			return re;//直接结束函数
		}
	}
	//追加的num个字符都没有'\0'
	*destination = '\0';//末尾自动添加'\0'
	return re;
}
int main()
{
	char arr1[20] = "a\0xxxxxxxxxxx";
	char arr2[5] = "abcd";
	//strncat(arr1, arr2, 5);
	printf("%s",my_strncat(arr1, arr2, 4));

	return 0;
}