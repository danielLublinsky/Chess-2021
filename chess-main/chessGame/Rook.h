#pragma once
#include "Figure.h"
#include "Operations.h"

class Rook : virtual public Figure
{
public:
	Rook(const char color, const char type, const int col, const int row); //c'tor
	~Rook();  //d'tor

	int isValidMove(Figure* board[8][8], const int cords, const char turn);
};

