#include "Empty.h"

Empty::Empty(const char color, const char type, const int col, const int row) : Figure(color, type, col, row)
{
	this->_type = type;
}

Empty::~Empty()
{
}

int Empty::isValidMove(Figure* board[8][8], const int cords, const char turn)
{
	return 0;
}
