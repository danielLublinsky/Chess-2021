#pragma once
#include "Figure.h"
#include "Operations.h"

class Knite : public Figure
{
private:

public:
	Knite(const char color, const char type, const int col, const int row); //c'tor
	~Knite();  //d'tor

	int isValidMove(Figure* board[8][8], const int cords, const char turn);
};

