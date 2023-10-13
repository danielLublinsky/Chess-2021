#include "Game.h"
#include <windows.h>

Game::Game(Board* board)
{
	this->_board = board;
}

Game::~Game()
{
}

int Game::isValidMove(const int cords)
{
	int x1 = Operations::getFirst(cords); int x2 = Operations::getThird(cords);
	int y1 = Operations::getSecond(cords);	int y2 = Operations::getfourth(cords);
	int ans = 0;
	ans = operation.sourceNotMyFigure(this->_board->_board, cords, this->_board->getTurn());
	if (ans == 0) {
		ans = operation.destIsMyFigure(this->_board->_board, cords, this->_board->getTurn());
		if (ans == 0) {
			ans = operation.locationCheck(cords);
			if (ans == 0) {
				ans = operation.sameLocationCheck(cords);
			}
		}
	}

	if(ans == 0)
		ans = this->_board->_board[y1][x1]->isValidMove(this->_board->_board, cords, this->_board->getTurn());
	
	return ans;
}

bool Game::eatKing(const int cords, const char turn)
{
	std::string boardStr = this->_board->getBoard();
	Board* boardCopy = new Board(boardStr);
	boardCopy->setTurn(turn);
	Game* copyGame = new Game(boardCopy);
	int src = Operations::getThird(cords) * 10 + Operations::getfourth(cords);
	if (copyGame->isValidMove(cords) == 0)
		copyGame->_board->setBoard(cords);
	else
		return false;
	char newTurn = turn == 'w' ? 'b' : 'w';
	int dest = boardCopy->getKingCords(newTurn);
	int cords2 = src * 100 + dest;

	bool canMove = copyGame->isValidMove(cords2) == 0 ? true : false;
	//true- chess
	//false- nothing
	return canMove;
}
int Game::kingCheck(const char turn, const int cords)
{
	std::string boardStr = this->_board->getBoard();
	Board* boardCopy = new Board(boardStr);
	boardCopy->setTurn(turn);
	Game* copyGame = new Game(boardCopy);
	int canEatKing = false;
	
	if (copyGame->isValidMove(cords) == 0)
		copyGame->_board->setBoard(cords);
	else
		return false;
	//char newTurn = turn == 'w' ? 'b' : 'w';
	int dest = boardCopy->getKingCords(turn);
	char newTurn = turn == 'w' ? 'b' : 'w';
	copyGame->_board->setTurn(newTurn);
	int check = 0;
	int cordsToKing;
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (copyGame->_board->_board[y][x]->getColor() == newTurn) {
				cordsToKing = x * 1000 + y * 100 + dest;
				canEatKing = copyGame->isValidMove(cordsToKing);
				if (canEatKing == 0)
					return true;
			}
		}
	}
	return false;
}