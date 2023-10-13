#pragma once
#include "Figure.h"
#include "Operations.h"
class Bishop : virtual public Figure
{
private:

public:
	Bishop(const char color, const char type, const int col, const int row); //c'tor
	~Bishop();  //d'tor

	int isValidMove(Figure* board[8][8], const int cords, const char turn);
};
