#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
//实现strcat() 字符串追加
//将源字符串的内容追加到目标字符串末尾
//思路：从源字符串的'\0'开始修改字符
char* my_strcat(char* dest, const char* source)
{
	assert(dest && source);//断言都不是空指针
	char* re = dest;      //记住目标字符串的首位置
	while (*dest != '\0')//使dest指向'\0'
	{
		dest++;
	}
	while (*dest++ = *source++)//把源字符串的内容赋给源字符串
	{                                            //每次赋给一个字符，地址向后移动一位
		;                                       //当找到源字符串的'\0'时，先把它赋给目标字符串，再退出循环
	}
	return re;
}
int main()
{
	char source[6] = "efgho";
	char dest[10] = "abci";
	printf("%s\n", my_strcat(dest, source));
	printf("%s\n", dest);
	return 0;
}
//注意：strcat不管目标数组是否有足够空间