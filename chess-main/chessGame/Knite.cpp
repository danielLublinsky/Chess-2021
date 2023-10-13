#include "Knite.h"

Knite::Knite(const char color, const char type, const int col, const int row) : Figure(color, type, col, row)
{
}

Knite::~Knite()
{
}

int Knite::isValidMove(Figure* board[8][8], const int cords, const char turn)
{
	//operation 6
	//checks valid move for knight

	int x1 = Operations::getFirst(cords); int x2 = Operations::getThird(cords);
	int y1 = Operations::getSecond(cords);	int y2 = Operations::getfourth(cords);

	int xLower = x1 < x2 ? x1 : x2;
	int xBigger = x1 < x2 ? x2 : x1;
	int yLower = y1 < y2 ? y1 : y2;
	int yBigger = y1 < y2 ? y2 : y1;

	if ((yBigger - yLower == 2 && xBigger - xLower == 1) ||
		(xBigger - xLower == 2 && yBigger - yLower == 1))
		return 0;
	return 6;
}