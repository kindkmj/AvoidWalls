#pragma once
#include <stdio.h>
#include "turboc.h"
#include <windows.h>
#include "creatingObstacles.h"
void creationUser(int x,int y)
{
    
    int preX = x;
    char ch;
        gotoxy(x, y);
        printf("ㅇ");
        gotoxy(x, y + 1);
        printf("ㅅ");
        gotoxy(x, y + 2);
        printf("ㅅ");
        // if (GetAsyncKeyState(VK_LEFT) & 0x0001)
    if(1)
        {
            preX = x;
            preX--;
            if (x == 0)
                x = 1;
            gotoxy(preX, y);
            delay(0);
            printf("          ");
            gotoxy(preX, y + 1);
            delay(0);
            printf("          ");
            gotoxy(preX, y + 2);
            delay(0);
            printf("          ");
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
        {
            preX = x;
            x++;
            if (x == 50)
                x = 48;
            gotoxy(preX, y);
            delay(0);
            printf("          ");
            gotoxy(preX, y + 1);
            delay(0);
            printf("          ");
            gotoxy(preX, y + 2);
            delay(0);
            printf("          ");
        }
}
