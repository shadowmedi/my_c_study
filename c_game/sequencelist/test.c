#define _CRT_SECURE_NO_WARNINGS
#include "sequence.h"
SL sqlist;//����һ��˳���
void test1()
{
	SequenceListInit(&sqlist);
	human data1 = { 30,"v", "��" };
	human data2 = { 20 , "ve", "��" };
	SequenceListPushFront(&sqlist, data1);
	SequenceListPushFront(&sqlist, data2);
}
int main()
{
	test1();
	return 0;
}