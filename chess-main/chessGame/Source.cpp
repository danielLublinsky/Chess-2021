/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include <iostream>
#include <thread>
#include <string.h>

using std::cout;
using std::endl;
using std::string;


void main()
{
	srand(time_t(NULL));

	Pipe p;
	bool isConnect = p.connect();
	
	bool canMove = false;
	bool chess = false;
	bool selfCheck = false;
	int operation = 0;
	Board* board = new Board(START_BOARD);
	Game* game = new Game(board);
	int cords = 0;

	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}
	

	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE


	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR0"); // just example...
	
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)

		// YOUR CODE

		cords = Operations::stringToInt(msgFromGraphics);
		operation = game->isValidMove(cords);

		canMove = (operation == 0) ? true : false;
		if (canMove)
		{
			selfCheck = game->kingCheck(board->getTurn(), Operations::stringToInt(msgFromGraphics));
			if (selfCheck)
				operation = 4;
			else
				chess = game->eatKing(cords, board->getTurn());
		}
		if (chess && selfCheck == false)
			operation = 1;
		if (selfCheck == true)
			operation = 4;
		if (operation == 0) {
			selfCheck = false;
			chess = false;
		}
			
        // msgToGraphics should contain the result of the operation
		/******* JUST FOR EREZ DEBUGGING ******/
		//int r = rand() % 10; // just for debugging......
		msgToGraphics[0] = (char)(operation + '0');
		msgToGraphics[1] = 0;
		/******* JUST FOR EREZ DEBUGGING ******/

		canMove = false;

		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);
		if (operation == 0 || operation == 1) {
			board->setBoard(cords);
			char newTurn = board->getTurn() == 'w' ? 'b' : 'w';
			board->setTurn(newTurn);
		}

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}