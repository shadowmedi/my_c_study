#define _CRT_SECURE_NO_WARNINGS
//strstr()函数：返回字符串中首次出现子串的地址
//找不到返回NULL
#include <stdio.h>
#include <assert.h>
//思路:定义2个指针p2,p1分别指向 要查找的字串 和 源字符串   首元素      
// 定义1个指针record负责指向开始对照的位置
//当*p1!=*p2时,record++, p1++

//当*p1 == *p2时,record不变,p1++,p2++,逐个对照,
//直到p2指向'\0'(要查找的子串找到了)或者*p1!=*p2(没找到该子串)

char* my_strstr(const char* source, const char* search)
{
	assert(source && search);
	const char* p1 = source;
	const char* p2 = search;
	const char* record = p1;//记录当前开始对照的位置
	while (*record != '\0')//若*record == '\0',说明源字符串中找不到字串
	{
		//p1和record一开始都指向开始对照的位置,但p1之后要用来与p2指向的元素逐个对照
		p1 = record;
		while (*p1 == *p2 && *p2 )//*p2为'\0'时已经找到了   ///////
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')//对照完成后子串的p2指向'\0',说明找到了,返回开始对照的位置record
			return record;
		//如果没找到,p2要重新指向子串的首字符
		p2 = search;
		//同时下一次开始对照的位置+1
		record++;
	}
	return NULL;
}
int main()
{
	char arr1[] = "shadowmeditation";
	char arr2[] = "tion";
	char* re = my_strstr(arr1, arr2);
	if (re == NULL)
		printf("找不到子串");
	else
		printf("%s", re);//在arr1中找子串arr2
	return 0;
}