#define _CRT_SECURE_NO_WARNINGS
#include "sequence.h"
SL sqlist;//创建一个顺序表
void test1()
{
	SequenceListInit(&sqlist);
	human data1 = { 30,"v", "男" };
	human data2 = { 20 , "ve", "男" };
	SequenceListPushFront(&sqlist, data1);
	SequenceListPushFront(&sqlist, data2);
}
int main()
{
	test1();
	return 0;
}