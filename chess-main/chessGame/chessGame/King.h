#pragma once
#include "Figure.h"
class King : public Figure
{
private:
public:
	King(const char color, const char type, const int col, const int row); //c'tor
	~King();  //d'tor

};
