#pragma once
#include "Figure.h"

class Queen : public Figure
{
private:


public:
	Queen(const char color, const char type, const int col, const int row); //c'tor
	~Queen();  //d'tor

};
