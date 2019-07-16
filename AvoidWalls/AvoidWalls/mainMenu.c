#pragma once
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "creatingObstacles.h"
#include "turboc.h"
extern int icharacter;
extern int iPage;
extern int level;
extern int score;
extern userInfo* user;
int check = 0;
void uesrNameInput(int check)
{
    FILE* fp;
    user = (userInfo*)malloc(sizeof(userInfo) * 10);
    if (check == 1)
    {
        printf("이름을 입력해주세요. : ");
        getchar();
        fgets(user[0].name, sizeof(user[0].name), stdin);
        user[0].name[strlen(user[0].name) - 1] = '\0';
        user[0].score = score;
        fopen_s(&fp, "rank.txt", "w");
        // fwrite(&user[0].name, sizeof(user), 1, user);
        // fwrite(&user[0].score, sizeof(user), 1, user);
        fwrite(&user, sizeof(user), 1, fp);
        fclose(fp);
    }
    if (check == 2)
    {
        fopen_s(&fp, "rank.txt", "r");

        fread(&user, sizeof(user), 1, fp);
        fclose(fp);
    }
}
void initStaticValue()
{
    iPage = 0;
    icharacter = 0;
}
int uesrChoice()
{
    int iselectNum = 0;
	scanf_s("%d", &iselectNum);
    return iselectNum;
	
}

#pragma region 콘솔 화면 구성

int showMain()
{
    system("mode con: cols=80 lines=20");  //크기 설정 
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                         1 .    게임 시작                                   ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                         2 .    랭킹 확인                                   ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                         3 .    게임 설명                                   ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                         4 .    만 든 이                                    ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                         5 .    게임 종료                                   ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("                                >> : ");

    iPage = uesrChoice();
    return iPage;
}
void selectLevel()
{
    system("mode con: cols=80 lines=15");
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃             1. Easy Mode                                                   ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃             2. Hard Mode                                                   ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("                                >> : ");
}
void selectCharacter()
{
    system("mode con: cols=80 lines=15");
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃        (1)                     (2)                                         ┃\n");
    printf("┃         ㅇ                       \"                                         ┃\n");
    printf("┃         ㅅ                       U                                         ┃\n");
    printf("┃         ㅅ                                                                 ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("                                >> : ");

	
}

#pragma endregion

void startGame(int level, int characterSelect)
{
    system("mode con: cols=57 lines=52");
	if (level == 1)
	{
		printf("선택한 모드 = [Easy Mode]");
		delay(2000);
		setcursortype(NOCURSOR);
		clrscr();
		radomizeVal();
	}
	else if (level == 2)
	{
		printf("선택한 모드 = [Hard Mode]");
		delay(2000);
		setcursortype(NOCURSOR);
		clrscr();
		radomizeVal();
	}
}
void viewRankingCheck()
{
    if (check > 0)
    {
        system("mode con: cols=80 lines=18");
        printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("┃                                                                            ┃\n");
        printf("┃                                                                            ┃\n");
        printf("┃                                                                            ┃\n");
        printf("┃                                                                            ┃\n");
        printf("┃             1 %2d  %s                                                      \n", user[0].score, user[0].name);
        printf("┃                                                                            ┃\n");
        printf("┃                                                                            ┃\n");
        printf("┃                                                                            ┃\n");
        printf("┃                                                                            ┃\n");
        printf("┃                                                                            ┃\n");
        printf("┃                                                                            ┃\n");
        printf("┃                                                                            ┃\n");
        printf("┃                                                                            ┃\n");
        printf("┃                                                                            ┃\n");
        printf("┃                                                                            ┃\n");
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        getchar();
        system("pasue");
    }
    else
    {
        printf("게임 실행 이후 조회해 주세요.");
        check++;
        getchar();
        system("pasue");
    }
}
void descriptionGame()
{
    system("mode con: cols=80 lines=20");
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃          1. 화살표 왼쪽 키는 좌측                                          ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                         우측키는 우측으로 이동합니다.                      ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃             2. 위에서 내려오는 벽돌을 피합니다.                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                  3. 최선을 다해서 즐기시면 됩니다.                         ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    getchar();
    system("pasue");
  
}
void creator()
{
    system("mode con: cols=80 lines=20");
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃                                                                            ┃\n");
    printf("┃      만든이 .                                                              ┃\n");
    printf("┃          1. 류 민 규                                                       ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃		2. 정 찬 우 	  			                     ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                    3. 김 민 진                                             ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┃                                                                            ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    getchar();
    system("pasue");
}
void exitGame()
{
    
}
void initConsole()
{
    system("cls");
}

void selectNextPage(int iselectNume)
{
	
    initConsole();

    if (iselectNume == 1)
    {
        //난이도 선택하는 콘솔창 출력 이후 초기화
        selectLevel();



        level = uesrChoice();

        initConsole();
        // 캐릭터 선택하는 콘솔창 출력 이후 초기화
        selectCharacter();
        icharacter = uesrChoice();
        initConsole();
        //창 초기화 이후 게임화면 진행
        getchar();

        startGame(level, icharacter);

        initStaticValue();
    }

    else if (iselectNume == 2)
    {
        uesrNameInput(2);
        viewRankingCheck();
    }
    else if (iselectNume == 3)
    {
        descriptionGame();
    }
    else if (iselectNume == 4)
    {
        creator();
    }

    else if (iselectNume == 5)
    {
        exit(0);
    }

    
}