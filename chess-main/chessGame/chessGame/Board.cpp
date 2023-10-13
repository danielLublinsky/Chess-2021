#include "Board.h"

Board::Board(std::string board) 
{
	int count = 0;
	char color = ' ';
	this->_turn = 'w';

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (board[count] <= 'Z' && board[count] >= 'A')
				color = 'b';
			else if (board[count] <= 'z' && board[count] >= 'a')
				color = 'w';
			else
				color = '#';
			//std::string s = board;
			//s[count] = toupper(s[count]);
			
			Figure* a = new Figure(color, board[count], i, j);
			this->_board[i][j] = a;
			//std::cout << a->getType();
			/*switch (s[count])
			{
			case 'R':
				{Figure* r = new Figure(color, s[count], i, j); 
				this->_board[i][j] = r; }
				break;
			case 'N':
				{Knite* n = new Knite(color, s[count], i, j); 
				this->_board[i][j] = n; }
				break;
			case 'B':
			    {Bishop* b = new Bishop(color, s[count], i, j); 
				this->_board[i][j] = b; }
				break;
			case 'K':
			    {King* k = new King(color, s[count], i, j);
				this->_board[i][j] = k; }
				break;
			case 'Q':
				{Queen* q = new Queen(color, s[count], i, j);
				this->_board[i][j] = q; }
				break;
			case 'P':
				{Pawn *p = new Pawn(color, s[count], i, j);
				this->_board[i][j] = p; }
				break;
			default:  //== '#'
				{Empty* e = new Empty(' ', '#', i, j);
				this->_board[i][j] = e; } //to add class for empty 
			}*/
			count++;
		}
	}
	//for (int i = BOARD_SIZE - 2; i < BOARD_SIZE; i++)  //convert to last lines to lower letters
	//{
	//	for (int j = 0; j < BOARD_SIZE; j++)
	//	{
	//		this->_board[i][j]->setType(tolower(this->_board[i][j]->getType()));
	//	}
	//}
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


Figure Board::getFigure(int row, int col)
{
	return *this->_board[col][row];
}

void Board::setBoard(const int rS, const int cS, const int rD, const int cD)
{
	
	this->_board[cD][rD] = this->_board[cS][rS];
	this->_board[cD][rD]->setCol(cD);
	this->_board[cD][rD]->setRow(rD);

	Empty* empty = new Empty(' ', '#', cS, rS);
	this->_board[cS][rS] = empty;
}



char Board::getTurn() const
{
	return this->_turn;
}

/*Figure** Board::getBoard() const
{
	//return &(this->_board);
	return _board;
}*/

void Board::setTurn(char val)
{
	this->_turn = val;
}

void Board::printBoard() const
{
	int c = 9;
	std::cout << "   a b c d e f g h" << std::endl;
	std::cout << "  ----------------" << std::endl;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
//<<<<<<< HEAD
//=======
		c--;
//>>>>>>> dc8c1544eb97643135218703cb6715e75da6c4fc
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
