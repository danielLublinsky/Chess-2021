#pragma once
#include "Figure.h"
#include <iostream>

class Operations
{
private:
	//if number = 1234 :


protected:

public:


	int static getFirst(const int cords);  //return 1
	int static getSecond(const int cords); //return 2
	int static getThird(const int cords);  //return 3
	int static getfourth(const int cords); //return 4

	int getInput();
	bool sourceNotMyFigure(Figure* board[8][8], const int cords, char turn);
	bool destIsMyFigure(Figure* board[8][8], const int cords, const char turn);
	bool locationCheck(int cords);
	bool sameLocationCheck(int cords);

	bool rookMoveCheck(Figure* board[8][8], const int cords);
	bool kingMoveCheck(Figure* board[8][8], const int cords);
	bool pawnMoveCheck(Figure* board[8][8], const int cords, const char turn);
};

