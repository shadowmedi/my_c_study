#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//大小写转换
int main()
{
	char a = getchar();
	if (a >= 65 && a <= 90)//65~90是大写字母
	{
		a += 32;
	}
	else if (a >= 97 && a <= 122)//97~122是大写字母
	{
		a -= 32;
	}
	putchar(a);
	return 0;
}