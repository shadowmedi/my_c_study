#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 11
#define COLS 11
#define ROW ROWS-2
#define COL COLS-2
#define SETMINE 10
void menu(void);//���˵�
void game(void);//��Ϸʵ��
void init_board(char board[ROWS][COLS], int rows, int cols, char set);//��ʼ��show��mine����
void set_mine(char myboard[ROWS][COLS], int row, int col);//������
void display(char board[ROWS][COLS], int row, int col);//��ӡshow����
void find_mine(char showboard1[ROWS][COLS], char myboard2[ROWS][COLS], int row, int col);//�����ף�����ҵĻ���
int num_of_mine(char mineboard[ROWS][COLS], int x, int y);//���ظ�����ը����Ŀ