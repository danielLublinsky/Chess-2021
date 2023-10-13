#include "Figure.h"

Figure::Figure(const char color, const char type, const int col, const int row)
{
	this->_color = color;
	this->_type = type;
	this->_col = col;
	this->_row = row;
	this->_firstMove = true;
}

Figure::Figure()
{
}

Figure::~Figure()
{
}

char Figure::getColor() const
{
	return this->_color;
}

char Figure::getType() const
{
	return this->_type;
}

int Figure::getCol() const
{
	return this->_col;
}

char Figure::getRow() const
{
	return this->_row;
}

bool Figure::isFirstMove() const
{
	return this->_firstMove;
}

void Figure::setCol(const int newCol)
{
	this->_col = newCol;
}

void Figure::setRow(const int newRow)
{
	this->_row = newRow;
}

void Figure::setType(const char newType)
{
	this->_type = newType;
}

void Figure::moved()
{
	this->_firstMove = false;
}
