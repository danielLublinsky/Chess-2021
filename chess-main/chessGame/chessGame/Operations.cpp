#include "Operations.h"

int Operations::getFirst(const int cords)
{
	if (cords / 1000 < 1)
		return 0;
	return cords / 1000;
}

int Operations::getSecond(const int cords)
{
	return cords / 100 % 10;
}

int Operations::getThird(const int cords)
{
	return cords / 10 % 10;
}

int Operations::getfourth(const int cords)
{
	return cords % 10;
}

int Operations::getInput()
{
	char x1; char x2;
	int y1; int y2;
	std::cout << "Enter figure you want to move:";
	std::cin >> x1 >> y1 >> x2 >> y2;
	x1 = x1 - '0';
	x2 = x2 - '0';
	y1 = 9 - y1;
	y2 = 9 - y2;
	std::cout << (atoi(&x1) * 1000 + y1 * 100 + atoi(&x2) * 10 + y2);
	return (atoi(&x1) * 1000 + y1 * 100 + atoi(&x2) * 10 + y2) - 1111;
}

bool Operations::sourceNotMyFigure(Figure* board[8][8], const int cords, char turn)
{
	//operation 2

	if ((board[Operations::getSecond(cords)][Operations::getFirst(cords)]->getType() == '#'))
		return false;

	//if figure is black and the user is playing the white or empty squre
	if ((board[Operations::getSecond(cords)][Operations::getFirst(cords)]->getType() >= 'A' &&
		board[Operations::getSecond(cords)][Operations::getFirst(cords)]->getType() <= 'Z' && turn == 'b'))
	{
		return false;
	}

	//if figure is white and the user is playing the black
	if (board[Operations::getSecond(cords)][Operations::getFirst(cords)]->getType() >= 'a' &&
		board[Operations::getSecond(cords)][Operations::getFirst(cords)]->getType() <= 'z' && turn == 'w')
	{
		return false;
	}
	return true;
}

bool Operations::destIsMyFigure(Figure* board[8][8], const int cords, const char turn)
{
	//operation 2

	//if figure is black and the user is playing the white

	if ((board[Operations::getfourth(cords)][Operations::getThird(cords)]->getType() >= 'A' &&
		board[Operations::getfourth(cords)][Operations::getThird(cords)]->getType() <= 'Z' && turn == 'w'))
	{
		return false;
	}
	//if figure is white and the user is playing the black
	if (board[Operations::getfourth(cords)][Operations::getThird(cords)]->getType() >= 'a' &&
		board[Operations::getfourth(cords)][Operations::getThird(cords)]->getType() <= 'z' && turn == 'b')
	{
		return false;
	}
	return true;
}

bool destIsMyFigure(const Figure* board[8][8], const int cords, const bool turn)
{
	//operation 3

	//if figure is black and the user moved to destination squre with black figure
	if ((board[Operations::getfourth(cords)][Operations::getThird(cords)]->getType() >= 'A' &&
		board[Operations::getfourth(cords)][Operations::getThird(cords)]->getType() <= 'Z' && turn == 'w'))
	{
		return false;
	}
	//if figure is white and the user is playing the black
	if (board[Operations::getfourth(cords)][Operations::getThird(cords)]->getType() >= 'a' &&
		board[Operations::getfourth(cords)][Operations::getThird(cords)]->getType() <= 'z' && turn == 'b')
	{
		return false;
	}
}

bool Operations::locationCheck(int cords)
{
	//operation 5
	
	int x1 = Operations::getFirst(cords); int x2 = Operations::getThird(cords);
	int y1 = Operations::getSecond(cords);	int y2 = Operations::getfourth(cords);
	if (x1 > 7 || x1 < 0 || y1 > 7 || y1 < 0 || x2 > 7 || x2 < 0 || y2 > 7 || y2 < 0)
		return false;
	return true;
}
bool Operations::sameLocationCheck(int cords)
{
	//operation 7

	if (Operations::getFirst(cords) == Operations::getThird(cords) 
		&& Operations::getSecond(cords) == Operations::getfourth(cords))
		return false;
	return true;
}
bool Operations::rookMoveCheck(Figure* board[8][8], const int cords)
{
	//checks valid move for Rook

	int x1 = Operations::getFirst(cords); int x2 = Operations::getThird(cords);
	int y1 = Operations::getSecond(cords);	int y2 = Operations::getfourth(cords);

	int xLower = x1 < x2 ? x1 : x2;
	int xBigger = x1 < x2 ? x2 : x1;
	int yLower = y1 < y2 ? y1 : y2;
	int yBigger = y1 < y2 ? y2 : y1;
	yLower++;
	xLower++;
	if (x1 != x1 && y1 != y2)
		return false;

	if (x1 != x2 && y1 != y2) //Rook cant move in slant
		return false;
	if (x1 == x2)
	{
		if(yLower == yBigger)
			return true;
		while (yLower < yBigger)
		{
			if (yLower == yBigger)
			{
				return true;
			}
			if (board[yLower + 1][x2]->getType() != '#')
			{
				return false;
			}
			yLower++;
		}
	}
	else
	{
		if (xLower == xBigger)
			return true;
		while (xLower < xBigger)
		{
			if (board[y1][xLower]->getType() != '#')
			{
				return false;
			}
			if (xLower + 1 == xBigger)
			{
				return true;
			}
			xLower++;
		}
	}
	return true;
}

bool Operations::kingMoveCheck(Figure* board[8][8], const int cords)
{
	//checks valid move for king

	int x1 = Operations::getFirst(cords); int x2 = Operations::getThird(cords);
	int y1 = Operations::getSecond(cords);	int y2 = Operations::getfourth(cords);

	int xLower = x1 < x2 ? x1 : x2;
	int xBigger = x1 < x2 ? x2 : x1;
	int yLower = y1 < y2 ? y1 : y2;
	int yBigger = y1 < y2 ? y2 : y1;

	return xBigger - xLower <= 1 && yBigger - yLower <= 1;
}

bool Operations::pawnMoveCheck(Figure* board[8][8], const int cords, char turn)
{
	//checks valid move for pawn

	int x1 = Operations::getFirst(cords); int x2 = Operations::getThird(cords);
	int y1 = Operations::getSecond(cords);	int y2 = Operations::getfourth(cords);
	bool firstMove = board[y1][x1]->isFirstMove();

	int xLower = x1 < x2 ? x1 : x2;
	int xBigger = x1 < x2 ? x2 : x1;
	int yLower = y1 < y2 ? y1 : y2;
	int yBigger = y1 < y2 ? y2 : y1;

	if (turn == 'w' && y2 > y1) //pawn cant move back
		return false;
	else if (turn == 'b' && y2 < y1)
		return false;
	//pawn can jump 2 squre just once- in his first move
	if (firstMove == true && yBigger - yLower == 2 && x1 == x2) 
		return true;
	if (yBigger - yLower == 1 && x1 == x2)
		return true;
	if (std::pow((x1 - x2), 2) == 1 && std::pow((y1 - y2), 2) == 1 && (board[y2][x2]->getType() != '#'))
		return true;
	return false;
}


