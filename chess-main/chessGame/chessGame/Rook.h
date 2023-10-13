#pragma once
#include "Figure.h"
class Rook : public Figure
{
private:
public:
	Rook(const char color, const char type, const int col, const int row); //c'tor
	~Rook();  //d'tor

};

