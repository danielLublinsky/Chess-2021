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
	Game();
	~Game();
	void game();
	bool isValidMove(const int cords);
};

