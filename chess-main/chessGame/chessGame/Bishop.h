#pragma once
#include "Figure.h"
class Bishop : public Figure
{
private:


public:
	Bishop(const char color, const char type, const int col, const int row); //c'tor
	~Bishop();  //d'tor

};
