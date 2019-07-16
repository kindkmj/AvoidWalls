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


#define LEFT_WALL 7	//내려오는 벽의 왼쪽 시작 x좌표.(테두리에서 띄운 좌표) 
#define RIGHT_WALL 47	//내려오는 벽의 오른쪽 끝나는 x좌표. 
#define BOTTOM_WALL 45	//내려오는 벽이 바닥에 닿으면 없어지는 값
#define HALL_VALUE 5	//내려오는 벽 구멍크기


void makingFallingWall(int randomHallValue, int randomArr[],int randomArrOrder)
{
	int FallingWall = 0;
	
	 

	for (randomHallValue = LEFT_WALL; randomHallValue <= LEFT_WALL + randomArr[randomArrOrder]; randomHallValue++)
		gotoxy(randomHallValue, FallingWall);
	gotoxy(randomHallValue, FallingWall);
	printf("=");
}






void leftVerticalWall(int statingPointY, int startingPoint, int endPoint)	//왼쪽 세로벽 DrawHeightWall 1 이라는함수명
{

	int drawingWalls = 0;
    for (drawingWalls = startingPoint; drawingWalls <= endPoint; drawingWalls++)	//i에서부터 i까지 벽을 그림
    {
        gotoxy(statingPointY, drawingWalls);
        if (drawingWalls == startingPoint)      printf(" ");	//벽의 모서리 부분은 공백처리. 다른벽이랑 겹쳐서 오류날까봐 띄워놓음
        else if (drawingWalls == endPoint)   printf(" ");

        else         printf("|↘|");		//모서리가 아니면 이걸 프린트

    }
}
void rightVerticalWall(int rightVerticalWall, int startingPoint, int endPoint)	//오른쪽 세로벽 DrawHeightWall 2 이라는함수명
{
    int drawingWalls = 0;
    for (drawingWalls = startingPoint; drawingWalls <= endPoint; drawingWalls++)
    {
        gotoxy(rightVerticalWall, drawingWalls);
        if (drawingWalls == startingPoint)      printf(" ");
        else if (drawingWalls == endPoint)   printf(" ");
        else         printf("|↙|");
    }
}

void floorHorizontal(int ywall, int startingPoint, int endPoint)	//위쪽 가로벽 DrawWidthWall 1이라는함수명
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

void scoreHorizontal(int ywall, int startingPoint, int endPoint)	////점수란 가로벽 DrawWidthWall 2이라는함수명
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
void bottomHorizontal(int ywall, int startingPoint, int endpoint)	////밑바닥 가로벽 DrawWidthWall 3이라는함수명
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
void inputScore(int scoreXPoint, int socoreYPoint,int inputScore) //점수입력란
{
    scoreXPoint = 20, socoreYPoint = 7;	//이쯤이 위에 상단좌표
    gotoxy(scoreXPoint, socoreYPoint);
    printf("점수 %d", inputScore);	//점수란
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

		for (randomArrOrder = 0; randomArrOrder < 10; randomArrOrder++)	//10개의 배열을받음
		{
			ranNum = random(30);	//내려오는 벽의 범위를 10~40디파인해놔서 0~30까지 랜덤숫자
			randomArr[randomArrOrder] = ranNum;	//숫자를 배열에 차곡차곡 저장
		}



		for (randomArrOrder = 0; randomArrOrder < 10; randomArrOrder++)	//arr[0]~arr[9]까지 랜덤숫자를 arr[i]에 넣는다
		{
			/*checkLevel();*/


			for (FallingWall = 10; FallingWall < BOTTOM_WALL; FallingWall++)//y좌표 20에서 시작해서 40까지 내려옴 
			{

				if (FallingWall == BOTTOM_WALL - 1)	//벽의 y좌표가 j까지가면 벽 클리어
				{
					score++;
				}



				if (icharacter == 1)
				{
					gotoxy(plyx, plyy);
					printf("ㅇ");
					gotoxy(plyx, plyy + 1);
					printf("ㅅ");
					gotoxy(plyx, plyy + 2);
					printf("ㅅ");
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
					// LEFT_WALL에서 시작해서 LEFT_WALL에서 랜덤값을 더한만큼 벽생성
				{
					gotoxy(randomHallValue, FallingWall);
					printf("=");


				}


				/*	makingFallingWall(randomHallValue, randomArr[randomArrOrder], randomArrOrder);*/




					// if (j == BOTTOM_WALL)	//벽의 y좌표가 j까지가면 벽 클리어
					//     clrscr();
				for (randomHallValue = LEFT_WALL + HALL_VALUE + randomArr[randomArrOrder]; randomHallValue <= RIGHT_WALL; randomHallValue++)
					//LEFT_WALL + 랜덤값 + 3(구멍의크기)에서 RIGHT_WALL까지 벽생성
				{
					gotoxy(randomHallValue, FallingWall);
					printf("=");

				}
				delay(50);

				for (randomHallValue = LEFT_WALL; randomHallValue <= LEFT_WALL + randomArr[randomArrOrder]; randomHallValue++)
					// LEFT_WALL에서 시작해서 LEFT_WALL에서 랜덤값을 더한만큼 벽생성
				{
					gotoxy(randomHallValue, FallingWall);
					delay(0);
					printf(" ");


				}
				for (randomHallValue = LEFT_WALL + HALL_VALUE + randomArr[randomArrOrder]; randomHallValue <= RIGHT_WALL; randomHallValue++)
					//LEFT_WALL + 랜덤값 + 3(구멍의크기)에서 RIGHT_WALL까지 벽생성
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
					printf("ㅇ");
					gotoxy(plyx, plyy + 1);
					printf("ㅅ");
					gotoxy(plyx, plyy + 2);
					printf("ㅅ");
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