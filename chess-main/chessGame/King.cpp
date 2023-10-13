#include "King.h"

King::King(const char color, const char type, const int col, const int row) : Figure(color, type, col, row)
{
}

King::~King()
{
}

int King::isValidMove(Figure* board[8][8], const int cords, const char turn)
{
	//operation 6
	//checks valid move for king

	int x1 = Operations::getFirst(cords); int x2 = Operations::getThird(cords);
	int y1 = Operations::getSecond(cords);	int y2 = Operations::getfourth(cords);

	int xLower = x1 < x2 ? x1 : x2;
	int xBigger = x1 < x2 ? x2 : x1;
	int yLower = y1 < y2 ? y1 : y2;
	int yBigger = y1 < y2 ? y2 : y1;

	if (xBigger - xLower <= 1 && yBigger - yLower <= 1)
		return 0;
	return 6;
}