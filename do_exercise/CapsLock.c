#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//��Сдת��
int main()
{
	char a = getchar();
	if (a >= 65 && a <= 90)//65~90�Ǵ�д��ĸ
	{
		a += 32;
	}
	else if (a >= 97 && a <= 122)//97~122�Ǵ�д��ĸ
	{
		a -= 32;
	}
	putchar(a);
	return 0;
}