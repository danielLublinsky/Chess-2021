#include "Pawn.h"

Pawn::Pawn(const char color, const char type, const int col, const int row) : Figure(color, type, col, row)
{
	this->_firstMove = true;
}

Pawn::~Pawn()
{
}

bool Pawn::getFistMove() 
{
	return this->_firstMove;
}

void Pawn::moved()
{
	this->_firstMove = false;
}

int Pawn::isValidMove(Figure* board[8][8], const int cords, const char turns)
{
	//checks valid move for pawn

	int x1 = Operations::getFirst(cords); int x2 = Operations::getThird(cords);
	int y1 = Operations::getSecond(cords);	int y2 = Operations::getfourth(cords);

	int xLower = x1 < x2 ? x1 : x2;
	int xBigger = x1 < x2 ? x2 : x1;
	int yLower = y1 < y2 ? y1 : y2;
	int yBigger = y1 < y2 ? y2 : y1;

	//int valreturn;

	if (turns == 'w' && y2 > y1) //pawn cant move back
		return 6;
	else if (turns == 'b' && y2 < y1)
		return 6;
	//pawn can jump 2 squre just once- in his first move
	if (_firstMove == true && yBigger - yLower == 2 && x1 == x2 && board[y2][x2]->getType() == '#') {
		this->moved();
		return 0;
	}
	if (yBigger - yLower == 1 && x1 == x2 && board[y2][x2]->getType() == '#') {
		this->moved();
		return 0;
	}
	if (std::pow((x1 - x2), 2) == 1 && std::pow((y1 - y2), 2) == 1 && (board[y2][x2]->getType() != '#')) {
		this->moved();
		return 0;
	}
	return 6;
}