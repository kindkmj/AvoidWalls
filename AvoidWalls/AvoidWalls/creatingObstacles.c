#pragma once
#include <stdio.h>
#include "mainMenu.h"
#include "turboc.h"
extern int radomValue[10];

extern int score;
extern int icharacter;
extern int level;
extern int randomArrOrder;
extern int check;
extern int plyx;
extern int plyy;
extern int speed;


#define LEFT_WALL 7	//�������� ���� ���� ���� x��ǥ.(�׵θ����� ��� ��ǥ) 
#define RIGHT_WALL 47	//�������� ���� ������ ������ x��ǥ. 
#define BOTTOM_WALL 45	//�������� ���� �ٴڿ� ������ �������� ��
#define HALL_VALUE 5	//�������� �� ����ũ��


void makingFallingWall(int randomHallValue, int randomArr[],int randomArrOrder)
{
	int FallingWall = 0;
	
	 

	for (randomHallValue = LEFT_WALL; randomHallValue <= LEFT_WALL + randomArr[randomArrOrder]; randomHallValue++)
		gotoxy(randomHallValue, FallingWall);
	gotoxy(randomHallValue, FallingWall);
	printf("=");
}






void leftVerticalWall(int statingPointY, int startingPoint, int endPoint)	//���� ���κ� DrawHeightWall 1 �̶���Լ���
{

	int drawingWalls = 0;
    for (drawingWalls = startingPoint; drawingWalls <= endPoint; drawingWalls++)	//i�������� i���� ���� �׸�
    {
        gotoxy(statingPointY, drawingWalls);
        if (drawingWalls == startingPoint)      printf(" ");	//���� �𼭸� �κ��� ����ó��. �ٸ����̶� ���ļ� ��������� �������
        else if (drawingWalls == endPoint)   printf(" ");

        else         printf("|��|");		//�𼭸��� �ƴϸ� �̰� ����Ʈ

    }
}
void rightVerticalWall(int rightVerticalWall, int startingPoint, int endPoint)	//������ ���κ� DrawHeightWall 2 �̶���Լ���
{
    int drawingWalls = 0;
    for (drawingWalls = startingPoint; drawingWalls <= endPoint; drawingWalls++)
    {
        gotoxy(rightVerticalWall, drawingWalls);
        if (drawingWalls == startingPoint)      printf(" ");
        else if (drawingWalls == endPoint)   printf(" ");
        else         printf("|��|");
    }
}

void floorHorizontal(int ywall, int startingPoint, int endPoint)	//���� ���κ� DrawWidthWall 1�̶���Լ���
{
    int drawingWalls = 0;
    for (drawingWalls = startingPoint; drawingWalls <= endPoint; drawingWalls++)
    {
        gotoxy(drawingWalls, ywall);
        if (drawingWalls == startingPoint)      printf(" ");
        else if (drawingWalls == endPoint)   printf(" ");
        else         printf("=");
    }
}

void scoreHorizontal(int ywall, int startingPoint, int endPoint)	////������ ���κ� DrawWidthWall 2�̶���Լ���
{
    int idraw = 0;
    for (idraw = startingPoint; idraw <= endPoint; idraw++)
    {
        gotoxy(idraw, ywall);
        if (idraw == startingPoint)      printf(" ");
        else if (idraw == endPoint)   printf(" ");
        else         printf("^");
    }
}
void bottomHorizontal(int ywall, int startingPoint, int endpoint)	////�عٴ� ���κ� DrawWidthWall 3�̶���Լ���
{
    int idraw = 0;
    for (idraw = startingPoint; idraw <= endpoint; idraw++)
    {
        gotoxy(idraw, ywall);
        if (idraw == startingPoint)      printf(" ");
        else if (idraw == endpoint)   printf(" ");
        else         printf("#");
    }
}
void inputScore(int scoreXPoint, int socoreYPoint,int inputScore) //�����Է¶�
{
    scoreXPoint = 20, socoreYPoint = 7;	//������ ���� �����ǥ
    gotoxy(scoreXPoint, socoreYPoint);
    printf("���� %d", inputScore);	//������
}






void radomizeVal()
{



	int /*randomArrOrder = 0, */ranNum = 0;
	int randomArr[100] = { 0 };

	int FallingWall = 0;
	int randomHallValue = 5;
	int scoreXPoint = 20, socoreYPoint = 7;
	int speed = 0;
	do {
		
		randomize();

		for (randomArrOrder = 0; randomArrOrder < 10; randomArrOrder++)	//10���� �迭������
		{
			ranNum = random(30);	//�������� ���� ������ 10~40�������س��� 0~30���� ��������
			randomArr[randomArrOrder] = ranNum;	//���ڸ� �迭�� �������� ����
		}



		for (randomArrOrder = 0; randomArrOrder < 10; randomArrOrder++)	//arr[0]~arr[9]���� �������ڸ� arr[i]�� �ִ´�
		{
			/*checkLevel();*/


			for (FallingWall = 10; FallingWall < BOTTOM_WALL; FallingWall++)//y��ǥ 20���� �����ؼ� 40���� ������ 
			{

				if (FallingWall == BOTTOM_WALL - 1)	//���� y��ǥ�� j�������� �� Ŭ����
				{
					score++;
				}



				if (icharacter == 1)
				{
					gotoxy(plyx, plyy);
					printf("��");
					gotoxy(plyx, plyy + 1);
					printf("��");
					gotoxy(plyx, plyy + 2);
					printf("��");
				}
				else if (icharacter == 2)
				{
					gotoxy(plyx, plyy);
					printf("\"");
					gotoxy(plyx, plyy + 1);
					printf("U");
					gotoxy(plyx, plyy + 2);
					printf(" ");
				}

				if (GetAsyncKeyState(VK_LEFT) & 0x0001)
				{

					plyx--;
					if (plyx == 0)
						plyx = 1;

					gotoxy(plyx, plyy);
					//delay(0);
					printf("   ");
					gotoxy(plyx, plyy + 1);
					//delay(0);
					printf("   ");
					gotoxy(plyx, plyy + 2);
					//delay(0);
					printf("   ");
				}


				if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
				{
					plyx++;
					if (plyx == 50)
						plyx = 48;
					gotoxy(plyx - 2, plyy);
					//delay(0);
					printf("    ");
					gotoxy(plyx - 2, plyy + 1);
					//delay(0);
					printf("    ");
					gotoxy(plyx - 2, plyy + 2);
					//delay(0);
					printf("    ");

				}




				for (randomHallValue = LEFT_WALL; randomHallValue <= LEFT_WALL + randomArr[randomArrOrder]; randomHallValue++)
					// LEFT_WALL���� �����ؼ� LEFT_WALL���� �������� ���Ѹ�ŭ ������
				{
					gotoxy(randomHallValue, FallingWall);
					printf("=");


				}


				/*	makingFallingWall(randomHallValue, randomArr[randomArrOrder], randomArrOrder);*/




					// if (j == BOTTOM_WALL)	//���� y��ǥ�� j�������� �� Ŭ����
					//     clrscr();
				for (randomHallValue = LEFT_WALL + HALL_VALUE + randomArr[randomArrOrder]; randomHallValue <= RIGHT_WALL; randomHallValue++)
					//LEFT_WALL + ������ + 3(������ũ��)���� RIGHT_WALL���� ������
				{
					gotoxy(randomHallValue, FallingWall);
					printf("=");

				}
				delay(50);

				for (randomHallValue = LEFT_WALL; randomHallValue <= LEFT_WALL + randomArr[randomArrOrder]; randomHallValue++)
					// LEFT_WALL���� �����ؼ� LEFT_WALL���� �������� ���Ѹ�ŭ ������
				{
					gotoxy(randomHallValue, FallingWall);
					delay(0);
					printf(" ");


				}
				for (randomHallValue = LEFT_WALL + HALL_VALUE + randomArr[randomArrOrder]; randomHallValue <= RIGHT_WALL; randomHallValue++)
					//LEFT_WALL + ������ + 3(������ũ��)���� RIGHT_WALL���� ������
				{
					gotoxy(randomHallValue, FallingWall);
					delay(0);
					printf(" ");

				}

				/*clrscr();*/


			   /* clrscr();*/
				gotoxy(plyx, plyy);
				if (icharacter == 1)
				{
					gotoxy(plyx, plyy);
					printf("��");
					gotoxy(plyx, plyy + 1);
					printf("��");
					gotoxy(plyx, plyy + 2);
					printf("��");
					/*	if (plyx = LEFT_WALL + arr[i] || HALL_VALUE + LEFT_WALL + arr[i])
							return;*/
				}
				else if (icharacter == 2)
				{
					gotoxy(plyx, plyy);
					printf("\"");
					gotoxy(plyx, plyy + 1);
					printf("U");
					gotoxy(plyx, plyy + 2);
					printf(" ");

				}


				if (level == 1)
					delay(speed+30);

				else if (level == 2)
					delay(speed);
			


				if (BOTTOM_WALL - 3 == FallingWall)
				{
					for (randomHallValue = LEFT_WALL; randomHallValue <= LEFT_WALL + randomArr[randomArrOrder]; randomHallValue++)

					{
						if (randomHallValue == plyx)
						{
                            check = 1;
                            clrscr();
                            //getchar();
                            printf("GAME OVER!!");
                            //getchar();
                            delay(1000);
                            clrscr();
                            uesrNameInput(1);
                            return;

						}

					}
					for (randomHallValue = LEFT_WALL + HALL_VALUE + randomArr[randomArrOrder]; randomHallValue <= RIGHT_WALL; randomHallValue++)

					{
						if (randomHallValue == plyx)
						{

                            check = 1;
                            clrscr();
                            //getchar();
                            printf("GAME OVER!!");
                            //getchar();
                            delay(1000);
                            clrscr();
                            uesrNameInput(1);
							return;

						}

					}



					//return;

				}

				leftVerticalWall(3, 3, 49);	//x, from, to
				floorHorizontal(3, 3, 53);	//y, from, to
				rightVerticalWall(50, 3, 49);	//x, from, to
				scoreHorizontal(10, 7, 48);	//y, from, to	
				bottomHorizontal(48, 7, 48);
				inputScore(scoreXPoint, socoreYPoint, score);
				// delay(50);

			}

		}
			clrscr();
	}while (1);

}