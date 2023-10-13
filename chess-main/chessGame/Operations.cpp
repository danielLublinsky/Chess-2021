#include "Operations.h"
#include "Pawn.h"

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

int Operations::stringToInt(std::string cords)
{
	char x1 = cords[0] - '0';
	char x2 = cords[2] - '0';
	int y1 = 9 - (cords[1] - '0');
	int y2 = 9 - (cords[3] - '0');

	return atoi(&x1) * 1000 + y1 * 100 + atoi(&x2) * 10 + y2 - 1111;
}

int Operations::sourceNotMyFigure(Figure* board[8][8], const int cords, char turn)
{
	//operation 2

	if ((board[Operations::getSecond(cords)][Operations::getFirst(cords)]->getType() == '#'))
		return 2;

	//if figure is black and the user is playing the white or empty squre
	if ((board[Operations::getSecond(cords)][Operations::getFirst(cords)]->getType() >= 'A' &&
		board[Operations::getSecond(cords)][Operations::getFirst(cords)]->getType() <= 'Z' && turn == 'b'))
	{
		return 2;
	}

	//if figure is white and the user is playing the black
	if (board[Operations::getSecond(cords)][Operations::getFirst(cords)]->getType() >= 'a' &&
		board[Operations::getSecond(cords)][Operations::getFirst(cords)]->getType() <= 'z' && turn == 'w')
	{
		return 2;
	}
	return 0;
}

int Operations::destIsMyFigure(Figure* board[8][8], const int cords, const char turn)
{
	//operation 3

	//if figure is black and the user is playing the white

	if ((board[Operations::getfourth(cords)][Operations::getThird(cords)]->getType() >= 'A' &&
		board[Operations::getfourth(cords)][Operations::getThird(cords)]->getType() <= 'Z' && turn == 'w'))
	{
		return 3;
	}
	//if figure is white and the user is playing the black
	if (board[Operations::getfourth(cords)][Operations::getThird(cords)]->getType() >= 'a' &&
		board[Operations::getfourth(cords)][Operations::getThird(cords)]->getType() <= 'z' && turn == 'b')
	{
		return 3;
	}
	return 0;
}

int Operations::locationCheck(int cords)
{
	//operation 5
	
	int x1 = Operations::getFirst(cords); int x2 = Operations::getThird(cords);
	int y1 = Operations::getSecond(cords);	int y2 = Operations::getfourth(cords);
	if (x1 > 7 || x1 < 0 || y1 > 7 || y1 < 0 || x2 > 7 || x2 < 0 || y2 > 7 || y2 < 0)
		return 5;
	return 0;
}
int Operations::sameLocationCheck(int cords)
{
	//operation 7

	if (Operations::getFirst(cords) == Operations::getThird(cords) 
		&& Operations::getSecond(cords) == Operations::getfourth(cords))
		return 7;
	return 0;
}