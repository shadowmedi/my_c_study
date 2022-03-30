#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 11
#define COLS 11
#define ROW ROWS-2
#define COL COLS-2
#define SETMINE 10
void menu(void);//主菜单
void game(void);//游戏实现
void init_board(char board[ROWS][COLS], int rows, int cols, char set);//初始化show和mine棋盘
void set_mine(char myboard[ROWS][COLS], int row, int col);//设置雷
void display(char board[ROWS][COLS], int row, int col);//打印show棋盘
void find_mine(char showboard1[ROWS][COLS], char myboard2[ROWS][COLS], int row, int col);//查找雷，与玩家的互动
int num_of_mine(char mineboard[ROWS][COLS], int x, int y);//返回附近的炸弹数目