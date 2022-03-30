#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//思路：循环遍历这个范围，用%10取得个位的数字，用/10舍弃最底位，直到数为0
//bug不要在循环里改变循环变量
int main()
{
	int min = 0;
	int max = 0;
	int num = 0;//计算9的个数
	scanf("%d %d", &min, &max);
	int initmin = min;//防止改变min
	for (; initmin <= max; initmin++)
	{
		//判断其中的一个数字有多少个9
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