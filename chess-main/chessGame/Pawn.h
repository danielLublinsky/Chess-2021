#pragma once
#include "Figure.h"
#include "Operations.h"

class Pawn : public Figure
{
private:
	bool _firstMove;

public:
	Pawn(const char color, const char type, const int col, const int row); //c'tor
	~Pawn();  //d'tor

	void moved();   //if pawn moved- the next move will not be is first move
	int isValidMove(Figure* board[8][8], const int cords, const char turn);
	bool getFistMove();
};

