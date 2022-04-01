#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
//将源字符串拷贝给目标字符串

char* my_strcpy(char* dest,const char* source)
{
	assert(dest && source);//断言皆不为空指针
	char* re = dest; //函数最后返回目标字符串首地址
	while (*dest++ = *source++)//先把source指向的字符赋给dest指向位置,再使它们的指向位置向后一位，	
	{                                             //直到把'\0'赋给dest
		;
	}
	return re;
}

int main()
{
	char dest[10] = "abcd";
	char source[5] = "efgh";

	printf("%s", my_strcpy(dest, source));
	return 0;
}