#pragma once
#include "Figure.h"
#include "Operations.h"
#include "Bishop.h"
#include "Rook.h"

class Queen : public Bishop, public Rook
{
private:

public:
	Queen(const char color, const char type, const int col, const int row); //c'tor
	~Queen();  //d'tor

	int isValidMove(Figure* board[8][8], const int cords, const char turn);
	
	
};
