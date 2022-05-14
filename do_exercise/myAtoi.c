#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
//空指针
//空字符串
//前面有空白字符
//非数字字符
//前面有+-
//溢出
//要点：设置一种状态，说明当前返回值是正确的、合理的
enum Status
{
    VALID,
    INVALID
}status = INVALID;//因为非法的情况较多，所以初始值设为非法

int my_atoi(const char* arr)
{
    int flag = 1;//标记正负
    long long ret = 0;
    assert(arr);//空指针
    if (*arr == '\0')//空字符串
    {
        return 0;//非法的0
    }
    while (isspace(*arr))//前面有空白字符
    {
        arr++;
    }
    if (*arr == '+')//处理正负
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
                //判断是否越界
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
//模拟实现atoi
//把字符串转换成数字
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
        printf("非法转换，转换时发生错误!!!\n");
    }
    return 0;
}