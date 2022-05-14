#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
//��ָ��
//���ַ���
//ǰ���пհ��ַ�
//�������ַ�
//ǰ����+-
//���
//Ҫ�㣺����һ��״̬��˵����ǰ����ֵ����ȷ�ġ������
enum Status
{
    VALID,
    INVALID
}status = INVALID;//��Ϊ�Ƿ�������϶࣬���Գ�ʼֵ��Ϊ�Ƿ�

int my_atoi(const char* arr)
{
    int flag = 1;//�������
    long long ret = 0;
    assert(arr);//��ָ��
    if (*arr == '\0')//���ַ���
    {
        return 0;//�Ƿ���0
    }
    while (isspace(*arr))//ǰ���пհ��ַ�
    {
        arr++;
    }
    if (*arr == '+')//��������
    {
        flag = 1;
        arr++;
    }
    else if (*arr == '-')
    {
        flag = -1;
        arr++;
    }
    while (*arr != '\0')
    {
        if (isdigit(*arr))
        {
            ret = ret * 10 + flag * (*arr - '0');
            if (ret > INT_MAX || ret < INT_MIN)
            {
                //�ж��Ƿ�Խ��
                ret = 0;
                break;
            }
            arr++;
        }
        else
        {
            ret = 0;
            break;
        }
    }
    if (*arr == '\0' && isdigit(*(arr - 1)))
    {
        status = VALID;
    }
    return ret;
}
//ģ��ʵ��atoi
//���ַ���ת��������
int main()
{
    char arr[20] = "          1054";
    
    int ret = my_atoi(arr);
    if (status == VALID)
    {
        printf("%d", ret);
    }
    else
    {
        printf("�Ƿ�ת����ת��ʱ��������!!!\n");
    }
    return 0;
}