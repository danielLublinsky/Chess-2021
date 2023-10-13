#include "Bishop.h"

Bishop::Bishop(const char color, const char type, const int col, const int row) :  Figure(color, type, col, row)
{
}

Bishop::~Bishop()
{
}

int Bishop::isValidMove(Figure* board[8][8], const int cords, const char turn)
{
	//operation 6
	//checks valid move for bishop

	int x1 = Operations::getFirst(cords); int x2 = Operations::getThird(cords);
	int y1 = Operations::getSecond(cords);	int y2 = Operations::getfourth(cords);

	int xLower = x1 < x2 ? x1 : x2;
	int xBigger = x1 < x2 ? x2 : x1;
	int yLower = y1 < y2 ? y1 : y2;
	int yBigger = y1 < y2 ? y2 : y1;

	if (x1 == x2 || y1 == y2)
		return 6;

	if (xBigger - xLower != yBigger - yLower)
		return 6;

	if (x1 < x2)
	{
		if (y1 < y2)
		{
			while (y1 < y2 - 1)
			{
				y1++; x1++;
				if (board[y1][x1]->getType() != '#')
					return 6;
			}
		}
		else
		{
			while (y2 < y1 - 1)
			{
				y1--; x1++;
				if (board[y1][x1]->getType() != '#')
					return 6;
			}
		}
	}
	else
	{
		if (y1 < y2)
		{
			while (y1 < y2 - 1)
			{
				y1++; x1--;
				if (board[y1][x1]->getType() != '#')
					return 6;
			}
		}
		else
		{
			while (y2 < y1 - 1)
			{
				y1--; x1--;
				if (board[y1][x1]->getType() != '#')
					return 6;
			}
		}
	}
	return 0;
}


