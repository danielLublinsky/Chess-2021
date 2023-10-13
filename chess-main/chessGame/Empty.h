#pragma once
#include "Figure.h"
#include "Operations.h"

class Empty : public Figure
{
private:

public:
	Empty(const char color, const char type, const int col, const int row); //c'tor
	~Empty();  //d'tor

	int isValidMove(Figure* board[8][8], const int cords, const char turn);
};

