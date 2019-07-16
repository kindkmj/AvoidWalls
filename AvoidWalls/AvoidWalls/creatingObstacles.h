#pragma once
//void creatingObstacles();
void radomizeVal();
void inputScore(int x, int y,int score);
void scoreHorizontal(int y, int from, int to);
void floorHorizontal(int y, int from, int to);
void rightVerticalWall(int x, int from, int to);
void leftVerticalWall(int x, int from, int to);
void bottomHorizontal(int y, int from, int to);

void makingFallingWall(int randomHallValue, int randomArr[], int randomArrOrder);