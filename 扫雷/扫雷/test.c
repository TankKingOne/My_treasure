#define _CRT_SECURE_NO_WARNINGS 1

#include"扫雷.h"

void game()
{
	char mine[ROWS][COLS];//雷的排布
	char show[ROWS][COLS];//显示信息
	InitBoard(mine, ROWS, COLS, '0');//初始化为 0
	InitBoard(show, ROWS, COLS, '*');//初始化为 *
	PrintBoard(show, ROW, COL);
	SetMine(mine, ROW, COL, Level_1);//布置雷
	PrintBoard(mine, ROW, COL);
	FindMine(mine, show, ROW, COL);
}

void menu()
{
	printf("***************************************\n");
	printf("********        1.  Play        *******\n");
	printf("********        0.  Exit        *******\n");
	printf("***************************************\n");
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}

	} while (input);

	return 0;
}