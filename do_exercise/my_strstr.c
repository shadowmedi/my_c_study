#define _CRT_SECURE_NO_WARNINGS
//strstr()�����������ַ������״γ����Ӵ��ĵ�ַ
//�Ҳ�������NULL
#include <stdio.h>
#include <assert.h>
//˼·:����2��ָ��p2,p1�ֱ�ָ�� Ҫ���ҵ��ִ� �� Դ�ַ���   ��Ԫ��      
// ����1��ָ��record����ָ��ʼ���յ�λ��
//��*p1!=*p2ʱ,record++, p1++

//��*p1 == *p2ʱ,record����,p1++,p2++,�������,
//ֱ��p2ָ��'\0'(Ҫ���ҵ��Ӵ��ҵ���)����*p1!=*p2(û�ҵ����Ӵ�)

char* my_strstr(const char* source, const char* search)
{
	assert(source && search);
	const char* p1 = source;
	const char* p2 = search;
	const char* record = p1;//��¼��ǰ��ʼ���յ�λ��
	while (*record != '\0')//��*record == '\0',˵��Դ�ַ������Ҳ����ִ�
	{
		//p1��recordһ��ʼ��ָ��ʼ���յ�λ��,��p1֮��Ҫ������p2ָ���Ԫ���������
		p1 = record;
		while (*p1 == *p2 && *p2 )//*p2Ϊ'\0'ʱ�Ѿ��ҵ���   ///////
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')//������ɺ��Ӵ���p2ָ��'\0',˵���ҵ���,���ؿ�ʼ���յ�λ��record
			return record;
		//���û�ҵ�,p2Ҫ����ָ���Ӵ������ַ�
		p2 = search;
		//ͬʱ��һ�ο�ʼ���յ�λ��+1
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
		printf("�Ҳ����Ӵ�");
	else
		printf("%s", re);//��arr1�����Ӵ�arr2
	return 0;
}