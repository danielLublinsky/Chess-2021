#pragma once
#include <iostream>
#include "Board.h"
#include "Operations.h"
//rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1
#define START_BOARD "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"
#define BOARD_SIZE 8
class Game
{
private:
	Board* _board;
	Operations operation;

public:
	Game(Board* board);
	~Game();
	void game();
	int isValidMove(const int cords);
	//If you manage to eat the king in an ancient board then it will be chess
	bool eatKing(const int cords, const char turn);
	int kingCheck(const char turn, const int cords);
};

