#pragma once
#include <string>
using namespace std;

class AlphaBetaNode
{
public:
	char piece;
	char from[2];
	char to[2];
	int value;

public:
	AlphaBetaNode();
	AlphaBetaNode(char piece, char* from, char* to, int value);
	~AlphaBetaNode();
};

