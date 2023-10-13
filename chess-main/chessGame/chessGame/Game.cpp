#include "Game.h"
#include <windows.h>

Game::Game()
{
	this->_board = new Board(START_BOARD);
}

Game::~Game()
{
}
void Game::game()
{
	
	bool canMove = false;

	while (true)
	{
		system("CLS");
		std::string turnNow = this->_board->getTurn() == 'w' ? "--White turn!--" : "--Black turn!--";
		std::cout << turnNow << std::endl << std::endl;
		this->_board->printBoard();
		int cords = operation.getInput();
		canMove = isValidMove(cords);
		
		if (canMove)
		{
			char newTurn = this->_board->getTurn() == 'w' ? 'b' : 'w'; //new turn
			this->_board->setTurn(newTurn);
			this->_board->setBoard(Operations::getFirst(cords), Operations::getSecond(cords), Operations::getThird(cords), Operations::getfourth(cords));
			canMove = false;
		}
	}
}

bool Game::isValidMove(const int cords)
{
	char type = this->_board->_board[operation.getSecond(cords)][operation.getFirst(cords)]->getType();
	bool ans = false;
	ans = operation.sourceNotMyFigure(this->_board->_board, cords, this->_board->getTurn());
	if (ans) {
		ans = operation.destIsMyFigure(this->_board->_board, cords, this->_board->getTurn());
		if (ans) {
			ans = operation.locationCheck(cords);
			if (ans) {
				ans = operation.sameLocationCheck(cords);
			}
		}
	}
	if (ans == true &&  (type == 'r' || type == 'R'))
	{
		ans = operation.rookMoveCheck(this->_board->_board, cords);
	}
	if (ans == true && (type == 'k' || type == 'K'))
		ans = operation.kingMoveCheck(this->_board->_board, cords);
	if (ans == true && (type == 'p' || type == 'P')) {
		ans = operation.pawnMoveCheck(this->_board->_board, cords, this->_board->getTurn());
		if(ans)
			this->_board->_board[operation.getSecond(cords)][operation.getFirst(cords)]->moved();
	}
	return ans;
}
