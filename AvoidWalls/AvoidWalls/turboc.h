
#ifndef TURBOC_HEADER
#define TURBOC_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void clrscr();
void gotoxy(int x, int y);
int wherex();
int wherey();
void setcursortype(CURSOR_TYPE c);

#define delay(n) Sleep(n)							// n/1000초만큼 시간 지연
#define randomize() srand((unsigned)time(NULL))		// 난수 발생기 초기화
#define random(n) (rand() % (n))					//0~n까지의 난수 발생

#endif // TURBOC_HEADER
