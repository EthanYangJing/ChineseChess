#pragma once
#include "board.h"

class EvalModel
{
private:
	float sumRed = 0;
	float sumBlack = 0;

	float staticValue = 0;
	float positionIndex = 0;
	int mobilityIndex = 0;

public:
	EvalModel();
	~EvalModel();

	int eval(Board* board, char player);
	int * evalPieceValue(Board * board);
	int evalPiecePosition(int p, char* pos);
};

