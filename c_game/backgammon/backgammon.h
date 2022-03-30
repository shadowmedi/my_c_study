#pragma once
#include <stdio.h>
#include<time.h>
#define ROW 3
#define COL 3
//���˵�
void menu(void);

//��Ϸ��ʵ��
void game(void);

//��ʼ������
void init_board(char arr[ROW][COL],int row,int col);

//��ӡ����
void display(char arr[ROW][COL], int row, int col);

//��һغ�
void player_turn(char arr[ROW][COL], int row, int col);

//���Իغ�
void computer_turn(char arr[ROW][COL], int row, int col);

//��Ϸ����������
char is_over(char[ROW][COL], int row, int col);
