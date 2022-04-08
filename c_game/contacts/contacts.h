#pragma once
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>

typedef struct Persons//人的信息
{
    char telephone[10];//电话
    char name[7];          //名字
    char addr[10];         //地址
}Persons;


typedef struct Contact //一个通讯录类型
{
    Persons data[1000];  //通讯录大小
    int current;                //已经存储的联系人数目
}Contact;

enum inputs                 //枚举常量使代码可读性提升
{
    exit,        //0
    add,        //1
    delete,    //2
    modify,   //3 
    search,    //4
    print        //5
};
                             
void menu(void);//主菜单

void init(Contact* con);//初始化通讯录

void addc(Contact* con);//增加

void deletec(Contact* con);//删除

void modifyc(Contact* con);//修改

void searchc(const Contact* con);//查找

int findbyname(Contact* con,const char* getname);//通过输入的名字在通讯录中查找下标

void printc(const Contact* con);//打印


