#include "Piece.h"

Piece::Piece()
{
}
void Piece::Init(char name, int * position)
{
	this->position[0] = position[0];
	this->position[1] = position[1];
	this->key = name;
	this->color = GetSide(name);

	this->character = GetType(name);

	this->index = GetObjIdx(name);

	this->position[0] = position[0];
	this->position[1] = position[1];
}

Piece::Piece(char name, int * position)
{
	Init(name, position);
}

Piece::~Piece()
{
}
