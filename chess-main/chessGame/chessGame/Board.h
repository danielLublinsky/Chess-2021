#pragma once
#include <iostream>
#include "Figure.h"
#include "Rook.h"
#include "Bishop.h"
#include "King.h"
#include "Knite.h"
#include "Pawn.h"
#include "Queen.h"
#include "Empty.h"

#define START_BOARD "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"
#define BOARD_SIZE 8

class Board
{
	//Figure* figure;
private:
	bool _check;
	//Figure* _board[BOARD_SIZE][BOARD_SIZE];
	//white starts
	char _turn; 

public:
	Board(std::string board);  //C'tor
	~Board();  //D'tor

	Figure getFigure(int row, int col);
	void setBoard(const int rS, const int cS, const int rD, const int cD);
	char getTurn() const;
	Figure** getBoard()const;
	void setTurn(char val);
	void printBoard()const;
	Figure* _board[BOARD_SIZE][BOARD_SIZE];
};

