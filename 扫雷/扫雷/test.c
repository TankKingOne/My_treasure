#define _CRT_SECURE_NO_WARNINGS 1

#include"ɨ��.h"

void game()
{
	char mine[ROWS][COLS];//�׵��Ų�
	char show[ROWS][COLS];//��ʾ��Ϣ
	InitBoard(mine, ROWS, COLS, '0');//��ʼ��Ϊ 0
	InitBoard(show, ROWS, COLS, '*');//��ʼ��Ϊ *
	PrintBoard(show, ROW, COL);
	SetMine(mine, ROW, COL, Level_1);//������
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
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("����������������룡\n");
			break;
		}

	} while (input);

	return 0;
}