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

#define BOARD_SIZE 8

class Board
{
private:
	char _turn;  

public:
	Board(std::string board);  //C'tor
	~Board();  //D'tor

	void setBoard(const int cords);
	char getTurn() const;
	void setTurn(char val);   //todo : set turn in Game for Pawn
	void printBoard()const;
	int getKingCords(const char king) const;  //king = 'w': looking for the white king
	std::string getBoard();
	Figure* _board[BOARD_SIZE][BOARD_SIZE];
};