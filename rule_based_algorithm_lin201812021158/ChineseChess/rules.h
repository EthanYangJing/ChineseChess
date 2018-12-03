#pragma once
#include <list>
#include "board.h"
class Rules
{
private:
	static char* pos;
	static Board* board;
	static char player;

private:
	static list<char*>* BRules();
	static list<char*>* MRules();
	static list<char*>* CRules();
	static list<char*>* JRules();
	static list<char*>* PRules();
	static list<char*>* XRules();
	static list<char*>* SRules();
public:
	Rules();
	~Rules();
	static list<char*>* getNextMove(char piece, char* pos, Board* board);
	


};

