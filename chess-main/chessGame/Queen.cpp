#include "Queen.h"

Queen::Queen(const char color, const char type, const int col, const int row) : Bishop(color, type, col, row), Rook(color, type, col, row), Figure(color, type, col, row)
{
}

Queen::~Queen()
{
}

int Queen::isValidMove(Figure* board[8][8], const int cords, const char turn)
{
	//operation 6
	//checks valid move for queen

	int x1 = Operations::getFirst(cords); int x2 = Operations::getThird(cords);
	int y1 = Operations::getSecond(cords);	int y2 = Operations::getfourth(cords);

	Rook r = *new Rook(board[y1][x1]->getColor(), board[y1][x1]->getType(), y1, x1);
	Bishop b = *new Bishop(board[y1][x1]->getColor(), board[y1][x1]->getType(), y1, x1);
	if (r.isValidMove(board, cords, turn) == 0 || b.isValidMove(board, cords, turn) == 0)
		return 0;
	return 1;
}