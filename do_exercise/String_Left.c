#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>

//思路1：循环左旋法
//左旋一次，用变量记录左边第一个字符，然后将后面的字符依次向前1格，
//最后把变量值赋给最后一个字符位置
//左移多次只需放在循环中指定左移的次数

//注意：若有num个字符，左旋k次与左旋k%num次等价

void StringLeft1(char*const pa, int leftnum)
{
	assert(pa);
	int num = 0;
	char* initpa = pa;
	while (*initpa != '\0')           //num记录字符个数
	{
		num++;
		initpa++;
	}
	initpa = NULL;
	for (int k = 0; k < (leftnum % num); k++)
	{
		//该循环内部是左移一次的效果
		char tem = *pa;//记录第一个字符
		int i = 0;           //用于第1个字符后面整体向前移一格
		while (i < num - 1)
		{
			pa[i] = pa[i + 1];
			i++;
		}
		pa[i] = tem;
	}
}



int main()
{
	int leftnum = 0;
	scanf("%d", &leftnum);
	char arr[5] = "abcd";
	StringLeft1(arr, leftnum);
	printf("%s", arr);
	return 0;
}