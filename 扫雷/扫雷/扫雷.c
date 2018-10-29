#define _CRT_SECURE_NO_WARNINGS 1

#include"É¨À×.h"

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char key)
{
	//int i = 0;
	//int j = 0;
	//for (i = 0; i < ROW; i++)
	//{
	//	for (j = 0; j < COL; j++)
	//	{
	//		arr[i][j] = key;
	//	}
	//}
	memset(&arr[0][0], key, rows*cols * sizeof(arr[0][0]));
}

void SetMine(char arr[ROWS][COLS], int row, int col, int level)//²¼ÖÃÀ×
{
	while (level)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			level--;
		}
	}
	//PrintBoard(mine, row, col);
}

void PrintBoard(char arr[ROWS][COLS], int row, int col)//Êä³ö
{
	int i = 0;
	int j = 0;
	
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row*col - Level_1)
	{
		printf("ÇëÊäÈë×ø±ê:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("You died!\n");
				PrintBoard(mine, row, col);
				break;
			}
			else
			{
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				PrintBoard(show, row, col);
				win++;
			}
		}
		else
		{
			printf("Input Error!\n");
		}
	}
	if (win == row * col - Level_1)
	{
		printf("You Win!!!\n");
	}
}

int GetMineCount(char mine[ROWS][COLS],int x,int y)
{
	int count = 0;
	count = mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1]
		+ mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0';

	return count;
}
