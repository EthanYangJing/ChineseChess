#include <algorithm>
#include "rules.h"

char* Rules::pos;
Board* Rules::board;
char Rules::player;

Rules::Rules()
{
}


Rules::~Rules()
{
}

list<char*>* Rules::getNextMove(char piece, char* pos, Board *board)
{
	Rules::pos = pos;
	Rules::board = board;
	Rules::player = Piece::GetSide(piece);
	switch (Piece::GetType(piece)) {
	case 'J':

		return JRules();
	case 'S':

		return SRules();
	case 'X':

		return XRules();
	case 'C':

		return CRules();
	case 'M':

		return MRules();
	case 'P':

		return PRules();
	case 'B':

		return BRules();
	default:
		return 0;
	}
}

list<char*>* Rules::MRules()
{
	list<char*>* moves = new list<char*>();
	char target[][2] = { { 1, -2 },{ 2, -1 },{ 2, 1 },{ 1, 2 },{ -1, 2 },{ -2, 1 },{ -2, -1 },{ -1, -2 } };
	char obstacle[][2] = { { 0, -1 },{ 1, 0 },{ 1, 0 },{ 0, 1 },{ 0, 1 },{ -1, 0 },{ -1, 0 },{ 0, -1 } };
	int target_len = sizeof(target) / sizeof(target[0]);
	for (int i = 0; i < target_len; i++) {
		char *e = new char[2]{pos[0] + target[i][0], pos[1] + target[i][1]};
		char *f = new char[2]{pos[0] + obstacle[i][0], pos[1] + obstacle[i][1]};
		if (!board->isInside(e)) continue;
		if (board->isEmpty(f)) {
			if (board->isEmpty(e)) moves->push_back(e);
			else if (board->getPiece(e)->color != player) moves->push_back(e);
		}
	}
	return moves;
}

list<char*>* Rules::CRules()
{
	list<char*>* moves = new list<char*>();
	char yOffsets[] = {1, 2, 3, 4, 5, 6, 7, 8};
	char xOffsets[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	for (auto offset : yOffsets) {
		char *rMove = new char[2]{pos[0], pos[1] + offset};
		if (board->isEmpty(rMove)) moves->push_back(rMove);
		else if (board->isInside(rMove) && board->getPiece(rMove)->color != player) {
			moves->push_back(rMove);
			break;
		}
		else break;
	}
	for (auto offset : yOffsets) {
		char *lMove = new char[2]{pos[0], pos[1] - offset};
		if (board->isEmpty(lMove)) moves->push_back(lMove);
		else if (board->isInside(lMove) && board->getPiece(lMove)->color != player) {
			moves->push_back(lMove);
			break;
		}
		else break;
	}
	for (auto offset : xOffsets) {
		char *uMove = new char[2]{pos[0] - offset, pos[1]};
		if (board->isEmpty(uMove)) moves->push_back(uMove);
		else if (board->isInside(uMove) && board->getPiece(uMove)->color != player) {
			moves->push_back(uMove);
			break;
		}
		else break;
	}
	for (auto offset : xOffsets) {
		char *dMove = new char[2]{pos[0] + offset, pos[1]};
		if (board->isEmpty(dMove)) moves->push_back(dMove);
		else if (board->isInside(dMove) && board->getPiece(dMove)->color != player) {
			moves->push_back(dMove);
			break;
		}
		else break;
	}
	return moves;
}

list<char*>* Rules::PRules()
{
	list<char*>* moves = new list<char*>();
	char yOffsets[] = {1, 2, 3, 4, 5, 6, 7, 8};
	char xOffsets[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	bool rr = false, ll = false, uu = false, dd = false;
	for (auto offset : yOffsets) {
		char *rMove = new char[2]{pos[0], pos[1] + offset};
		if (!board->isInside(rMove)) break;
		bool e = board->isEmpty(rMove);
		if (!rr) {
			if (e) moves->push_back(rMove);
			else rr = true;
		}
		else if (!e) {
			if (board->getPiece(rMove)->color != player)
			{
				moves->push_back(rMove);
			}
			break;
		}
	}
	for (auto offset : yOffsets) {
		char *lMove = new char[2]{pos[0], pos[1] - offset};
		if (!board->isInside(lMove)) break;
		bool e = board->isEmpty(lMove);
		if (!ll) {
			if (e) moves->push_back(lMove);
			else ll = true;
		}
		else if (!e) {
			if (board->getPiece(lMove)->color != player) 
			{
				moves->push_back(lMove);
			}
			break;
		}
	}
	for (auto offset : xOffsets) {
		char *uMove = new char[2]{pos[0] - offset, pos[1]};
		if (!board->isInside(uMove)) break;
		bool e = board->isEmpty(uMove);
		if (!uu) {
			if (e) moves->push_back(uMove);
			else uu = true;
		}
		else if (!e) {
			if (board->getPiece(uMove)->color != player)
			{
				moves->push_back(uMove);
			}
			break;
		}
	}
	for (auto offset : xOffsets) {
		char *dMove = new char[2]{pos[0] + offset, pos[1]};
		if (!board->isInside(dMove)) break;
		bool e = board->isEmpty(dMove);
		if (!dd) {
			if (e) moves->push_back(dMove);
			else dd = true;
		}
		else if (!e) {
			if (board->getPiece(dMove)->color != player)
			{
				moves->push_back(dMove);
			}
			break;
		}
	}
	return moves;
}

list<char*>* Rules::XRules()
{
	list<char*>* moves = new list<char*>();
	char target[][2] = { { -2, -2 },{ 2, -2 },{ -2, 2 },{ 2, 2 } };
	char obstacle[][2] = { { -1, -1 },{ 1, -1 },{ -1, 1 },{ 1, 1 } };
	int target_len = sizeof(target) / sizeof(target[0]);
	for (int i = 0; i < target_len; i++) {
		char *e = new char[2]{pos[0] + target[i][0], pos[1] + target[i][1]};
		char *f = new char[2]{pos[0] + obstacle[i][0], pos[1] + obstacle[i][1]};
		if (!board->isInside(e) || (e[0] > 4 && player == 'b') || (e[0] < 5 && player == 'r')) continue;
		if (board->isEmpty(f)) {
			if (board->isEmpty(e)) moves->push_back(e);
			else if (board->getPiece(e)->color != player) moves->push_back(e);
		}
	}
	return moves;
}

list<char*>* Rules::SRules()
{
	list<char*>* moves = new list<char*>();

	char target[][2] = { { -1, -1 },{ 1, 1 },{ -1, 1 },{ 1, -1 } };
	for (auto& aTarget : target) {
		char *e = new char[2]{pos[0] + aTarget[0], pos[1] + aTarget[1]};
		if (!board->isInside(e) || ((e[0] > 2 || e[1] < 3 || e[1] > 5) && player == 'b') || ((e[0] < 7 || e[1] < 3 || e[1] > 5) && player == 'r'))
			continue;
		if (board->isEmpty(e)) moves->push_back(e);
		else if (board->getPiece(e)->color != player) moves->push_back(e);
	}
	return moves;
}

list<char*>* Rules::JRules()
{
	list<char*>* moves = new list<char*>();

	/* 3*3 block */
	char target[][2] = { { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 } };
	for (auto& aTarget : target) {
		char *e = new char[2]{pos[0] + aTarget[0], pos[1] + aTarget[1]};
		if (!board->isInside(e) || ((e[0] > 2 || e[1] < 3 || e[1] > 5) && player == 'b') || ((e[0] < 7 || e[1] < 3 || e[1] > 5) && player == 'r'))
			continue;
		if (board->isEmpty(e)) moves->push_back(e);
		else if (board->getPiece(e)->color != player) moves->push_back(e);
	}
	/* opposite 'J' */
	bool flag = true;
	char *oppoBoss = 0;
	if (player == 'r')
	{
		if (board->pieces[macro_bJ0] == 0)
		{
			oppoBoss = 0;
		}
		else
		{
			oppoBoss = board->pieces[macro_bJ0]->position;
		}
	}
	else
	{
		if (board->pieces[macro_rJ0] == 0)
		{
			oppoBoss = 0;
		}
		else
		{
			oppoBoss = board->pieces[macro_rJ0]->position;
		}

	}
	 
	if (oppoBoss != 0 && oppoBoss[1] == pos[1]) 
	{
		for (int i = min(oppoBoss[0], pos[0]) + 1; i < max(oppoBoss[0], pos[0]); i++) 
		{
			if (board->getPiece(i, pos[1]) != 0) 
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			moves->push_back(oppoBoss);
		}
	}
	return moves;
}

list<char*>* Rules::BRules()
{
	list<char*>* moves = new list<char*>();
	char targetU[][2] = { { 0, 1 },{ 0, -1 },{ -1, 0 } };
	char targetD[][2] = { { 0, 1 },{ 0, -1 },{ 1, 0 } };
	if (player == 'r') {
		if (pos[0] > 4) {
			char *e = new char[2]{pos[0] - 1, pos[1]};
			if (board->isEmpty(e)) moves->push_back(e);
			else if (board->getPiece(e)->color != player) moves->push_back(e);
		}
		else {
			for (auto& aTarget : targetU) {
				char *e = new char[2]{pos[0] + aTarget[0], pos[1] + aTarget[1]};
				if (!board->isInside(e)) continue;
				if (board->isEmpty(e)) moves->push_back(e);
				else if (board->getPiece(e)->color != player) moves->push_back(e);
			}
		}
	}
	if (player == 'b') {
		if (pos[0] < 5) {
			char *e = new char[2]{pos[0] + 1, pos[1]};
			if (board->isEmpty(e)) moves->push_back(e);
			else if (board->getPiece(e)->color != player) moves->push_back(e);
		}
		else {
			for (auto& aTarget : targetD) {
				char *e = new char[2]{pos[0] + aTarget[0], pos[1] + aTarget[1]};
				if (!board->isInside(e)) continue;
				if (board->isEmpty(e)) moves->push_back(e);
				else if (board->getPiece(e)->color != player) moves->push_back(e);
			}
		}
	}

	return moves;
}
