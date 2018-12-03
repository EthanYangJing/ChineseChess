#pragma once
#include <string>
#include <list>
using namespace std;
#define macro_bJ0 ((0x00 << 4) | (0x00 << 1) | 0x00)
#define macro_bS0 ((0x00 << 4) | (0x01 << 1) | 0x00)
#define macro_bS1 ((0x01 << 4) | (0x01 << 1) | 0x00)
#define macro_bX0 ((0x00 << 4) | (0x02 << 1) | 0x00)
#define macro_bX1 ((0x01 << 4) | (0x02 << 1) | 0x00)
#define macro_bM0 ((0x00 << 4) | (0x03 << 1) | 0x00)
#define macro_bM1 ((0x01 << 4) | (0x03 << 1) | 0x00)
#define macro_bC0 ((0x00 << 4) | (0x04 << 1) | 0x00)
#define macro_bC1 ((0x01 << 4) | (0x04 << 1) | 0x00)
#define macro_bP0 ((0x00 << 4) | (0x05 << 1) | 0x00)
#define macro_bP1 ((0x01 << 4) | (0x05 << 1) | 0x00)
#define macro_bB0 ((0x00 << 4) | (0x06 << 1) | 0x00)
#define macro_bB1 ((0x01 << 4) | (0x06 << 1) | 0x00)
#define macro_bB2 ((0x02 << 4) | (0x06 << 1) | 0x00)
#define macro_bB3 ((0x03 << 4) | (0x06 << 1) | 0x00)
#define macro_bB4 ((0x04 << 4) | (0x06 << 1) | 0x00)

#define macro_rJ0 ((0x00 << 4) | (0x00 << 1) | 0x01)
#define macro_rS0 ((0x00 << 4) | (0x01 << 1) | 0x01)
#define macro_rS1 ((0x01 << 4) | (0x01 << 1) | 0x01)
#define macro_rX0 ((0x00 << 4) | (0x02 << 1) | 0x01)
#define macro_rX1 ((0x01 << 4) | (0x02 << 1) | 0x01)
#define macro_rM0 ((0x00 << 4) | (0x03 << 1) | 0x01)
#define macro_rM1 ((0x01 << 4) | (0x03 << 1) | 0x01)
#define macro_rC0 ((0x00 << 4) | (0x04 << 1) | 0x01)
#define macro_rC1 ((0x01 << 4) | (0x04 << 1) | 0x01)
#define macro_rP0 ((0x00 << 4) | (0x05 << 1) | 0x01)
#define macro_rP1 ((0x01 << 4) | (0x05 << 1) | 0x01)
#define macro_rB0 ((0x00 << 4) | (0x06 << 1) | 0x01)
#define macro_rB1 ((0x01 << 4) | (0x06 << 1) | 0x01)
#define macro_rB2 ((0x02 << 4) | (0x06 << 1) | 0x01)
#define macro_rB3 ((0x03 << 4) | (0x06 << 1) | 0x01)
#define macro_rB4 ((0x04 << 4) | (0x06 << 1) | 0x01)

class Piece
{
public:
	char key;
	char color;
	char character;
	char index;
	char position[2];
	list<int*> moves;
	
public:
	Piece();
	Piece(char name, int * position);


	~Piece();

	void Init(char name, int * position);
	static char GetObjIdx(char name)
	{
		char bit_val = (name >> 4) & 0x07;

		return bit_val;
	}
	static char GetType(char name)
	{
		char bit_val = (name >> 1) & 0x07;
		char character = 'J';
		switch (bit_val)
		{
		case 0:
			character = 'J';
			break;
		case 1:
			character = 'S';
			break;
		case 2:
			character = 'X';
			break;
		case 3:
			character = 'M';
			break;
		case 4:
			character = 'C';
			break;
		case 5:
			character = 'P';
			break;
		case 6:
			character = 'B';
			break;
		default:
			break;
		}
		return character;
	}

	static char GetSide(char name)
	{
		char color = 0;
		if ((name & 0x01) == 0x01)
		{
			color = 'r';
		}
		else
		{
			color = 'b';
		}

		return color;
	}
};

