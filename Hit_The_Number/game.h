#pragma once
#define RANGE 100//猜的数字范围是0~100
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void menu(void);//主菜单
void game(void);
int random(void);//系统生成随机值
void hit(int a);//用户与游戏的互动