#pragma once
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>
#include <malloc.h>

typedef struct Persons//人的信息
{
    char telephone[10];//电话
    char name[7];          //名字
    char addr[10];         //地址
}Persons;

//静态版本

/*typedef struct Contact //一个通讯录类型
{
    Persons data[1000];  //通讯录大小
    int current;                //已经存储的联系人数目
}Contact;*/

//动态版本
typedef struct Contact
{
    Persons* data;//指向开辟的动态空间首地址
    int current;//已经存储的联系人数目
    int capacity;//当前容量
}Contact;

#define TRANS 3

enum inputs                 //枚举常量使代码可读性提升
{
    exit,        //0
    add,        //1
    delete,    //2
    modify,   //3 
    search,    //4
    print,        //5
    clear,       //6
    sort         //7
};

void menu(void);//主菜单

void loadData(Contact* con);//加载文件数据

void initContact(Contact* con);//初始化通讯录

void destoryContact(Contact*con);//保存通讯录


void expensionContact(Contact* con);//扩容

void reduceContact(Contact* con);//缩容

void addc(Contact* con);//增加

void deletec(Contact* con);//删除

void modifyc(Contact* con);//修改

void searchc(const Contact* con);//查找

int findbyname(Contact* con, const char* getname);//通过输入的名字在通讯录中查找下标

void printc(const Contact* con);//打印

void clearc(Contact* con);//清空

void sortc(Contact* con);//排序

