#pragma once
#include "Figure.h"
#include "Operations.h"

class King :  public Figure
{
private:

public:
	King(const char color, const char type, const int col, const int row); //c'tor
	~King();  //d'tor

	int isValidMove(Figure* board[8][8], const int cords, const char turn);
};
