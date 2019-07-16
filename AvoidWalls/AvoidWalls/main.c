#pragma once
#include <stdio.h>
#include "mainMenu.h"
#include <stdlib.h>

int icharacter = 0; //캐릭터 선택
int iPage = 0;	//메인메뉴 페이지 선택값
int radomValue[10] = { 0 };	//랜덤값 받는 10개의 배열
int randomArrOrder = 0;
int plyx = 25;
int plyy = 45;
int score = 0;
int level = 0;
int speed = 0;
userInfo* user = NULL;
void main()

{
    system("mode con: cols=80 lines=20");  //크기 설정 
    while (1)
    {
        //콘솔창 초기화
        initConsole();
        // 전역변수 iLevel 에 showmain을 통해서 첫 화면을 보여준뒤 선택값을 iLevel에 저장함.
        iPage = showMain();
		getchar();
        //전역변수에 저장된 ilevel을 토대로 다음페이지 호출
        selectNextPage(iPage);
    }

}
