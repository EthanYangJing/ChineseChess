#pragma once
#include <map>
#include <string>
#include "piece.h"
using namespace std;


class Board
{
public:
	static const int BOARD_WIDTH = 9;
	static const int BOARD_HEIGHT = 10;

	map<char, Piece*> pieces;
	char player = 'r';
	Piece *cells[BOARD_HEIGHT][BOARD_WIDTH];

	Board();
	~Board();

	bool isInside(char * position);
	bool isInside(int x, int y);
	bool isEmpty(char * position);
	bool isEmpty(int x, int y);
	bool update(Piece* Piece);
	Piece* updatePiece(char* oldPos, char* newPos);
	Piece *updatePiece(char key, char * newPos);
	bool backPiece(char key);
	Piece* getPiece(char * pos);
	Piece* getPiece(int x, int y);

	void dumpToFile(char move_side, int value);
	void display();
};

