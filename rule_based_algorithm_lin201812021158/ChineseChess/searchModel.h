#pragma once
#include <list>
#include "board.h"
#include "alphaBetaNode.h"

class SearchModel
{
private:
	const int MAX_VALUE = 1000000;
	const int MIN_VALUE = -1000000;

	const int COERCE_LENGTH = 50;
	int DEPTH = 2;
	Board* board;

	char move_side;

public:
	SearchModel();
	~SearchModel();
	char hasWin();
	list<AlphaBetaNode*>* generateMovesForAll(char move_side);
	int alphaBeta(int depth, int alpha, int beta, char move_side);
	AlphaBetaNode* search(Board* board, char move_side);
};

