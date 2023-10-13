#include "Board.h"

Board::Board(std::string board) 
{
	int count = 0;
	char color = ' ';
	this->_turn = 'w';
	int z = 0;
	int timeOut = -999;

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (board[count] <= 'Z' && board[count] >= 'A')
				color = 'w';
			else if (board[count] <= 'z' && board[count] >= 'a')
				color = 'b';
			else 
				color = '#';
			std::string s = board;
			s[count] = toupper(s[count]);

			switch (s[count])
			{
			case 'R':
				{Rook* r = new Rook(color, board[count], i, j);
				this->_board[i][j] = r;}
				break;
			case 'N':
				{Knite* n = new Knite(color, board[count], i, j);
				this->_board[i][j] = n; }
				break;
			case 'B':
			    {Bishop* b = new Bishop(color, board[count], i, j);
				this->_board[i][j] = b; }
				break;
			case 'K':
			    {King* k = new King(color, board[count], i, j);
				this->_board[i][j] = k; }
				break;
			case 'Q':
				{Queen* q = new Queen(color, board[count], i, j);
				this->_board[i][j] = q; }
				break;
			case 'P':
				{Pawn *p = new Pawn(color, board[count], i, j);
				this->_board[i][j] = p; }
				break;
			default:  //== '#'
				{Empty* e = new Empty(' ', '#', i, j);
				this->_board[i][j] = e; } //to add class for empty 
			}
			count++;
		}

	}
}

Board::~Board()
{
	// free dynamically allocated memory
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		delete[] this->_board[i];
	}
	// delete actual board
	delete this->_board;
}

void Board::setBoard(const int cords)
{
	int x1 = Operations::getFirst(cords); int x2 = Operations::getThird(cords);
	int y1 = Operations::getSecond(cords);	int y2 = Operations::getfourth(cords);
	this->_board[y2][x2] = this->_board[y1][x1];
	this->_board[y2][x2]->setCol(x2);
	this->_board[y2][x2]->setRow(y2);

	Empty* empty = new Empty(' ', '#', x1, y1);
	this->_board[y1][x1] = empty;
}

char Board::getTurn() const
{
	return this->_turn;
}

void Board::setTurn(char val)
{
	this->_turn = val;
}

void Board::printBoard() const
{
	int c = 8;
	std::cout << "   a b c d e f g h" << std::endl;
	std::cout << "  ----------------" << std::endl;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		std::cout << c;
		std::cout << "| ";
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			std::cout << this->_board[i][j]->getType();
			std::cout << " ";
		}
		std::cout << "|";
		std::cout << c--;
		std::cout << std::endl;
	}
	std::cout << "  ----------------" << std::endl;
	std::cout << "   a b c d e f g h" << std::endl;
}

int Board::getKingCords(const char king) const
{
	char type = ' ';

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			type = _board[i][j]->getType();
			if (type == 'k' && king == 'b')
				return j * 10 + i;
			else if (type == 'K' && king == 'w') {
				int x = 0;
				return j * 10 + i;
			}
		}
	}
}


std::string Board::getBoard()
{
	std::string string = "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0";
	int c = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			string[c] = this->_board[i][j]->getType();
			c++;
		}
	}
	return string;
}