#pragma once
#include "struct.h"
void startGame(int level,int characterSelect); //레벨과 캐릭터를 입력받은뒤 실행
void viewRankingCheck(); //랭킹을 보여주는 화면
void descriptionGame(); // 게임설명을 보여주는 화면
void creator(); //만든이 보여주는 화면
void exitGame(); //게임종료
int uesrChoice(); //유저 선택
void initConsole(); //화면 초기화
int showMain(); //메인메뉴 보여줌
void selectNextPage(int iselectNume); //페이지 설정창
void initStaticValue(); //전역변수 값 초기화 