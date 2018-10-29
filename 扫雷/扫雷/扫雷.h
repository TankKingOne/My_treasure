#ifndef __GAME_H_
#define __GAME_H_

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define Level_1 10

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char key);
void SetMine(char arr[ROWS][COLS], int row, int col, int level);//²¼ÖÃÀ×
void PrintBoard(char arr[ROWS][COLS], int row, int col);//Êä³ö
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int GetMineCount(char mine[ROWS][COLS], int x, int y);

#endif //__GAME_H_