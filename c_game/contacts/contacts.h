#pragma once
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <string.h>

typedef struct Persons//�˵���Ϣ
{
    char telephone[10];//�绰
    char name[7];          //����
    char addr[10];         //��ַ
}Persons;


typedef struct Contact //һ��ͨѶ¼����
{
    Persons data[1000];  //ͨѶ¼��С
    int current;                //�Ѿ��洢����ϵ����Ŀ
}Contact;

enum inputs                 //ö�ٳ���ʹ����ɶ�������
{
    exit,        //0
    add,        //1
    delete,    //2
    modify,   //3 
    search,    //4
    print        //5
};
                             
void menu(void);//���˵�

void init(Contact* con);//��ʼ��ͨѶ¼

void addc(Contact* con);//����

void deletec(Contact* con);//ɾ��

void modifyc(Contact* con);//�޸�

void searchc(const Contact* con);//����

int findbyname(Contact* con,const char* getname);//ͨ�������������ͨѶ¼�в����±�

void printc(const Contact* con);//��ӡ


