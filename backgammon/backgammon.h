#pragma once
#include <stdio.h>
#include<time.h>
#define ROW 3
#define COL 3
//主菜单
void menu(void);

//游戏的实现
void game(void);

//初始化棋盘
void init_board(char arr[ROW][COL],int row,int col);

//打印棋盘
void display(char arr[ROW][COL], int row, int col);

//玩家回合
void player_turn(char arr[ROW][COL], int row, int col);

//电脑回合
void computer_turn(char arr[ROW][COL], int row, int col);

//游戏结束的条件
char is_over(char[ROW][COL], int row, int col);
