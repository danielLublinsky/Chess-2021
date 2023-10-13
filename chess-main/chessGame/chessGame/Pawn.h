#pragma once
#include "Figure.h"
class Pawn : public Figure
{
private:


public:
	Pawn(const char color, const char type, const int col, const int row); //c'tor
	~Pawn();  //d'tor

};

