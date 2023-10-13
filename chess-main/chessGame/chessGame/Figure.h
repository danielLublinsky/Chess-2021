#pragma once

class Figure
{
protected:
	char _color;
    char _type;
	int _col;
	int _row;
	bool _firstMove;

public:
	Figure(const char color, const char type, const int col, const int row); //c'tor
	Figure();
	~Figure();  //d'tor

	//getters
	char getColor() const;  
	char getType() const;
	int getCol() const;
	char getRow() const;
	bool isFirstMove()const;

	//setters
	void setCol(const int newCol);
	void setRow(const int newRow);
	void setType(const char newType);
	void moved();

};

