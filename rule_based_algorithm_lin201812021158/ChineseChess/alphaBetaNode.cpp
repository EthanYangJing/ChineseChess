#include "alphaBetaNode.h"



AlphaBetaNode::AlphaBetaNode()
{
}
AlphaBetaNode::AlphaBetaNode(char piece, char* from, char* to, int value) {
	this->piece = piece;
	this->from[0] = from[0];
	this->from[1] = from[1];
	this->to[0] = to[0];
	this->to[1] = to[1];
	this->value = value;
}

AlphaBetaNode::~AlphaBetaNode()
{
}
