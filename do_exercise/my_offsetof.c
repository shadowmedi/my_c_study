#define _CRT_SECURE_NO_WARNINGS
//дһ���꣬����ṹ����ĳ����������׵�ַ��ƫ�ƣ�������˵��
//���죺offsetof���ʵ��
#include <stdio.h>
#include <stddef.h>
#define my_offsetof(structName, memberName) (size_t)(&(((structName*)0 )->memberName))
//�ṹ��ĳ�Ա��ƫ�������������ʼ��ַ���Ե�
//�����ʼ��ַΪ0
//�ǳ�Ա�ĵ�ַ��ʵҲ���ǳ�Ա��ƫ����
struct Student
{
	int age;//0~3
	char a;//4
	int t; //8 ~11
};
int main()
{
	size_t a = my_offsetof(struct Student, t);
	printf("%lld", a);
	return 0;
}