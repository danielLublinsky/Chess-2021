#pragma once
#include "Figure.h"
#include <iostream>

class Operations
{
public:

	//gets digits from cords- general example- if the cords is 1234 then:
	static int getFirst(const int cords);  //return 1
	static int getSecond(const int cords); //return 2
	static int getThird(const int cords);  //return 3
	static int getfourth(const int cords); //return 4

	static int stringToInt(std::string cords);   //function gets string type and return it as int type

	//general tests valid for each figure
	int sourceNotMyFigure(Figure* board[8][8], const int cords, char turn); 
	int destIsMyFigure(Figure* board[8][8], const int cords, const char turn);
	int locationCheck(int cords);
	int sameLocationCheck(int cords);

	//specific tests for each figure 
	int rookMoveCheck(Figure* board[8][8], const int cords);                    //rook
	int kingMoveCheck(Figure* board[8][8], const int cords);                    //king
	int pawnMoveCheck(Figure* board[8][8], const int cords, const char turn);   //pawn
	int bishopMoveCheck(Figure* board[8][8], const int cords);                   //bishop
	int knighteMoveCheck(Figure* board[8][8], const int cords);                 //knite
	int queenMoveCheck(Figure* board[8][8], const int cords);                   //queen
};

