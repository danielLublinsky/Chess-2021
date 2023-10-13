#pragma once

class Figure
{
protected:
	char _color;
	int _col;
	int _row;
	char _type;

public:
	Figure(const char color, const char type, const int col, const int row); //c'tor
	Figure();
	~Figure();  //d'tor

	//getters
	char getColor() const;  
	char getType() const;
	int getCol() const;
	char getRow() const;

	//setters
	void setCol(const int newCol);
	void setRow(const int newRow);
	void setType(const char newType);

	virtual int isValidMove(Figure* board[8][8], const int cords, const char turn) = 0;
};

