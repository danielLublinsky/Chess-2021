#pragma once
#include "Figure.h"

class Empty : public Figure
{
public:
	Empty(const char color, const char type, const int col, const int row); //c'tor
	~Empty();  //d'tor

	
};

