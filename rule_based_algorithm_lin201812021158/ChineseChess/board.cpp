#include "Board.h"



Board::Board()
{
	
}


Board::~Board()
{
}


bool Board::isInside(char* position) {
	return isInside(position[0], position[1]);
}

bool Board::isInside(int x, int y) {
	return !(x < 0 || x >= BOARD_HEIGHT
		|| y < 0 || y >= BOARD_WIDTH);
}

bool Board::isEmpty(char* position) {
	return isEmpty(position[0], position[1]);
}

bool Board::isEmpty(int x, int y) {
	return isInside(x, y) && (cells[x][y] == 0);
}

void Board::dumpToFile(char move_side, int value)
{
	return;
	string total_buffer;
	
	total_buffer = "x:   0    1    2    3    4    5    6    7    8  \n";
	for (int ida = 0; ida < BOARD_HEIGHT; ida++)
	{
		char buffer[10] = { 0 };
		sprintf_s(buffer, 10, "%d: ", ida);
		total_buffer += buffer;
		string output_str = buffer;
		for (int idb = 0; idb < BOARD_WIDTH; idb++)
		{
			Piece * piece = cells[ida][idb];
			if (0 == piece)
			{
				output_str += "  +  ";
			}
			else
			{
				char buffer[1024] = { 0 };
				sprintf_s(buffer, 1024, " %c-%c ", piece->character, piece->color);
				output_str += buffer;
			}
		}
		output_str += "\n";		
		total_buffer += output_str;
	}
	total_buffer += "\n";
	char buffer[256] = { 0 };
	sprintf_s(buffer, 256, "current move_side:%c value:%d\n", move_side, value);
	total_buffer += buffer;
	total_buffer += "+++++++++++++++++++++++++++++++++++++++++\n";
	FILE * file = 0;
	fopen_s(&file, "d:\\board_eval.txt", "ab");
	if (0 != file)
	{
		fwrite(total_buffer.c_str(), 1, total_buffer.length(), file);
		fclose(file);
		file = 0;
	}
}

void Board::display()
{
	printf("x:   0    1    2    3    4    5    6    7    8  \n");
	for (int ida = 0; ida < BOARD_HEIGHT; ida++)
	{
		char buffer[10] = { 0 };
		sprintf_s(buffer, 10, "%d: ", ida);
		string output_str = buffer;
		for (int idb = 0; idb < BOARD_WIDTH; idb++)
		{
			Piece * piece = cells[ida][idb];
			if (0 == piece)
			{
				output_str += "  +  ";
			}
			else
			{
				char buffer[1024] = { 0 };
				sprintf_s(buffer, 1024, " %c-%c ", piece->character, piece->color);
				output_str += buffer;
			}
		}
		output_str += "\n";
		printf(output_str.c_str());
	}
	
	printf("\n");
}


bool Board::update(Piece* piece) {
	char* pos = piece->position;
	pieces[piece->key] = piece;
	cells[pos[0]][pos[1]] = piece;
	return true;
}
Piece* Board::updatePiece(char* oldPos, char* newPos)
{
	Piece *inOldPos = getPiece(oldPos);
	Piece *inNewPos = getPiece(newPos);
	if (inNewPos != 0)
		pieces.erase(inNewPos->key);
	/* Clear original slot and updatePiece new slot.*/
	char* origPos = inOldPos->position;
	cells[origPos[0]][origPos[1]] = 0;
	cells[newPos[0]][newPos[1]] = inOldPos;
	inOldPos->position[0] = newPos[0];
	inOldPos->position[1] = newPos[1];

	return inNewPos;
}

Piece* Board::updatePiece(char key, char* newPos) {
	Piece *orig = pieces[key];
	Piece *inNewPos = getPiece(newPos);
	/* If the new slot has been taken by another piece, then it will be killed.*/
	if (inNewPos != 0)
		pieces.erase(inNewPos->key);
	/* Clear original slot and updatePiece new slot.*/
	char* origPos = orig->position;
	cells[origPos[0]][origPos[1]] = 0;
	cells[newPos[0]][newPos[1]] = orig;
	orig->position[0] = newPos[0];
	orig->position[1] = newPos[1];
	player = (player == 'r') ? 'b' : 'r';
	return inNewPos;
}

bool Board::backPiece(char key) {
	char* origPos = pieces[key]->position;
	cells[origPos[0]][origPos[1]] = pieces[key];
	return true;
}

Piece* Board::getPiece(char* pos) {
	return getPiece(pos[0], pos[1]);
}

Piece* Board::getPiece(int x, int y) {
	return cells[x][y];
}
