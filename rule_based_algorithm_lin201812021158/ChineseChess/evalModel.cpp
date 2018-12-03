#include "evalModel.h"
#if false
int jPosition[][9] = {
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 5, 6, 5, 0, 0, 0 },
{ 0, 0, 0, 7, 8, 7, 0, 0, 0 },
{ 0, 0, 0, 8,10, 8, 0, 0, 0 },
};

int sPosition[][9] = {
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 6, 0, 6, 0, 0, 0 },
{ 0, 0, 0, 0,10, 0, 0, 0, 0 },
{ 0, 0, 0, 9, 0, 9, 0, 0, 0 },
};

int xPosition[][9] = {
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 8, 0, 0, 0, 8, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 7, 0, 0, 0,10, 0, 0, 0, 7 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 9, 0, 0, 0, 9, 0, 0 },
};

int pPosition[][9] = {
{ 9, 9,10, 4, 4, 4,10, 9, 9 },
{ 8, 8, 7, 5, 3, 5, 7, 8, 8 },
{ 8, 8, 7, 6, 7, 6, 7, 8, 8 },
{ 8, 8, 7, 7, 9, 7, 7, 8, 8 },
{ 8, 8, 7, 7, 9, 7, 7, 8, 8 },
{ 8, 8, 8, 8,10, 8, 8, 8, 8 },
{ 8, 8, 9, 8,10, 8, 9, 8, 8 },
{ 8, 8, 9, 7,10, 7, 9, 8, 8 },
{ 8, 8, 9, 5, 5, 5, 9, 8, 8 },
{ 5, 8, 8, 4, 4, 4, 8, 8, 5 },
};
int mPosition[][9] = {
{ 5, 7, 7, 5, 4, 5, 7, 7, 5 },
{ 7, 9,10, 6, 6, 6,10, 9, 7 },
{ 7, 8, 9,10, 7,10, 9, 8, 7 },
{ 7, 8, 9, 9,10, 8, 8, 8, 7 },
{ 7, 8, 8, 9,10, 8, 8, 8, 7 },
{ 7, 8, 8, 8, 8, 8, 8, 8, 7 },
{ 7, 8, 8, 8, 8, 8, 8, 8, 7 },
{ 7, 8, 8, 7, 5, 7, 8, 8, 7 },
{ 6, 8, 8, 5, 4, 5, 8, 8, 6 },
{ 5, 7, 4, 4, 4, 4, 4, 7, 5 },
};
int cPosition[][9] = {
{ 9, 9, 8, 7, 7, 7, 8, 9, 9 },
{ 9, 9, 9, 8, 8, 8, 9, 9, 9 },
{ 8, 9, 9, 9, 9, 9, 9, 9, 9 },
{ 10,10,10, 9,10, 9,10,10,10 },
{ 9, 9, 9, 9,10, 9, 9, 9, 9 },
{ 8, 8, 8, 9,10, 9, 8, 8, 8 },
{ 8, 8, 8, 9,10, 9, 8, 8, 8 },
{ 7, 8, 8, 7, 8, 7, 8, 8, 7 },
{ 7, 7, 7, 6, 5, 6, 7, 7, 7 },
{ 5, 7, 8, 5, 4, 5, 7, 7, 5 },
};
int bPosition[][9] = {
{ 4, 5, 5, 6, 6, 6, 5, 5, 4 },
{ 5, 6, 6, 7, 7, 7, 6, 6, 5 },
{ 7, 8, 8, 8, 8, 8, 8, 8, 7 },
{ 8, 9, 9, 9, 9, 9, 9, 9, 8 },
{ 9,10,10,10,10,10,10,10, 9 },
{ 7, 0, 8, 0,10, 0, 8, 0, 7 },
{ 4, 0, 5, 0, 5, 0, 5, 0, 4 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

// 将机动性          0，1，2，3，4
int Jmobility[5] = { 0, 0, 0, 0, 0 };

// 士机动性          0，1，2，3，4
int Smobility[5] = { 0, 0, 0, 0, 0 };

// 象机动性          0，1，2，3，4
int Xmobility[5] = { 0, 0, 0, 0, 0 };

// 马机动性          0，1，2，3，4，5，6，7，8
int Mmobility[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// 车机动性          0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17
int Cmobility[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// 炮机动性          0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17
int Pmobility[18] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// 兵机动性          0，1，2，3
int Bmobility[4] = { 0, 0, 0, 0 };
#else

int jPosition[][9] = {
    //	1	,	2	,	3	,	4	,	5	,	6	,	7	,	8	,	9	
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	-200	,	-300	,	-200	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	-50	,	-30	,	-50	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	-20	,	0	,	-20	,	0	,	0	,	0 },
    //	9	,	8	,	7	,	6	,	5	,	4	,	3	,	2	,	1	
};

int sPosition[][9] = {
    //	1	,	2	,	3	,	4	,	5	,	6	,	7	,	8	,	9	
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	10	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    //	9	,	8	,	7	,	6	,	5	,	4	,	3	,	2	,	1	
};

int xPosition[][9] = {
    //	1	,	2	,	3	,	4	,	5	,	6	,	7	,	8	,	9	
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	-5	,	0	,	0	,	0	,	-5	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { -10	,	0	,	0	,	0	,	10	,	0	,	0	,	0	,	-10 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    //	9	,	8	,	7	,	6	,	5	,	4	,	3	,	2	,	1	
};

int mPosition[][9] = {
    //	1	,	2	,	3	,	4	,	5	,	6	,	7	,	8	,	9	
    { 35	,	30	,	30	,	25	,	33	,	25	,	30	,	30	,	35 },
    { 25	,	25	,	50	,	25	,	33	,	25	,	50	,	25	,	25 },
    { 40	,	38	,	40	,	40	,	40	,	40	,	40	,	38	,	40 },
    { 20	,	45	,	30	,	45	,	25	,	45	,	30	,	45	,	20 },
    { 25	,	32	,	30	,	35	,	30	,	35	,	30	,	32	,	25 },
    { 33	,	30	,	35	,	33	,	35	,	33	,	35	,	30	,	33 },
    { 20	,	20	,	25	,	20	,	30	,	20	,	25	,	20	,	20 },
    { 12	,	18	,	15	,	20	,	10	,	20	,	15	,	18	,	12 },
    { 0	,	3	,	10	,	12	,	-30	,	12	,	6	,	3	,	0 },
    { 0	,	-5	,	0	,	0	,	-30	,	0	,	0	,	-5	,	0 },
    //	9	,	8	,	7	,	6	,	5	,	4	,	3	,	2	,	1	
};

int cPosition[][9] = {
    //	1	,	2	,	3	,	4	,	5	,	6	,	7	,	8	,	9	
    { 24	,	24	,	20	,	30	,	60	,	30	,	20	,	24	,	24 },
    { 25	,	30	,	24	,	35	,	100	,	35	,	24	,	30	,	25 },
    { 20	,	20	,	20	,	30	,	30	,	30	,	20	,	20	,	20 },
    { 25	,	27	,	27	,	35	,	33	,	35	,	27	,	27	,	25 },
    { 20	,	27	,	15	,	35	,	33	,	35	,	15	,	27	,	20 },
    { 20	,	27	,	24	,	35	,	33	,	35	,	24	,	27	,	20 },
    { 10	,	16	,	15	,	24	,	24	,	24	,	15	,	16	,	10 },
    { 0	,	15	,	5	,	24	,	15	,	24	,	5	,	15	,	0 },
    { 15	,	10	,	15	,	25	,	0	,	25	,	15	,	10	,	15 },
    { -15	,	16	,	10	,	24	,	0	,	24	,	10	,	16	,	-15 },
    //	9	,	8	,	7	,	6	,	5	,	4	,	3	,	2	,	1	
};

int pPosition[][9] = {
    //	1	,	2	,	3	,	4	,	5	,	6	,	7	,	8	,	9	
    { 100	,	80	,	50	,	-20	,	-25	,	-20	,	50	,	80	,	100 },
    { 0	,	0	,	0	,	0	,	-30	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	-15	,	0	,	0	,	0	,	-15	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	50	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { -15	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	-15 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	20	,	15	,	40	,	15	,	20	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    //	9	,	8	,	7	,	6	,	5	,	4	,	3	,	2	,	1	
};

int bPosition[][9] = {
    //	1	,	2	,	3	,	4	,	5	,	6	,	7	,	8	,	9	
    { 0	,	5	,	10	,	15	,	20	,	15	,	10	,	5	,	0 },
    { 30	,	60	,	90	,	130	,	200	,	130	,	90	,	60	,	30 },
    { 24	,	45	,	70	,	100	,	130	,	100	,	70	,	45	,	24 },
    { 15	,	33	,	50	,	55	,	65	,	55	,	50	,	33	,	15 },
    { 10	,	20	,	30	,	30	,	33	,	30	,	30	,	20	,	10 },
    { 5	,	0	,	15	,	0	,	10	,	0	,	15	,	0	,	5 },
    { 0	,	0	,	-5	,	0	,	15	,	0	,	-5	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    { 0	,	0	,	0	,	0	,	0	,	0	,	0	,	0	,	0 },
    //	9	,	8	,	7	,	6	,	5	,	4	,	3	,	2	,	1	
};

// 将机动性          0，1，2，3，4
int Jmobility[5] = { 0, 0, 0, 0, 0 };

// 士机动性          0，1，2，3，4
int Smobility[5] = { 0, 0, 0, 0, 0 };

// 象机动性          0，1，2，3，4
int Xmobility[5] = { 0, 0, 0, 0, 0 };

// 马机动性          0，1，2，3，4，5，6，7，8
int Mmobility[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// 车机动性          0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17
int Cmobility[18] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// 炮机动性          0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17
int Pmobility[18] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// 兵机动性          0，1，2，3
int Bmobility[4] = { 0, 0, 0, 0};


#endif

EvalModel::EvalModel()
{
}


EvalModel::~EvalModel()
{
}

int EvalModel::eval(Board* board, char player)
{
	int allPieces[7] = evalPieceValue(board);
	for (auto& stringPieceEntry : board->pieces) {
		Piece* piece = stringPieceEntry.second;
		if (0 == piece)
		{
			continue;
		}
		/* The table in PiecePosition is for red player in default. To eval black player, needs to perform a mirror transformation. */
		char reversePosition[] = {board->BOARD_HEIGHT - 1 - piece->position[0], piece->position[1]};
		mobilityIndex = piece->moves.size();
		switch (piece->character) {
		case 'J':
			staticValue = evalPieceValue(0, board);
			if (piece->color == 'r') {
				//positionIndex = evalPiecePosition(0, piece->position);
				sumRed += staticValue + positionIndex + Jmobility[mobilityIndex];
			}
			else {
				//positionIndex = evalPiecePosition(0, reversePosition);
				sumBlack += staticValue + positionIndex + Jmobility[mobilityIndex];
			}
			break;
		case 'S':
			staticValue = evalPieceValue(1, board);
			if (piece->color == 'r') {
				positionIndex = evalPiecePosition(1, piece->position);
				sumRed += staticValue + positionIndex + Smobility[mobilityIndex];
			}
			else {
				positionIndex = evalPiecePosition(1, reversePosition);
				sumBlack += staticValue + positionIndex + Smobility[mobilityIndex];
			}
			break;
		case 'X':
			staticValue = evalPieceValue(2, board);
			if (piece->color == 'r') {
				positionIndex = evalPiecePosition(2, piece->position);
				sumRed += staticValue + positionIndex + Xmobility[mobilityIndex];
			}
			else {
				positionIndex = evalPiecePosition(2, reversePosition);
				sumBlack += staticValue + positionIndex + Xmobility[mobilityIndex];
			}
			break;
		case 'M':
			staticValue = evalPieceValue(3, board);
			if (piece->color == 'r') {
				positionIndex = evalPiecePosition(3, piece->position);
				sumRed += staticValue + positionIndex + Mmobility[mobilityIndex];
			}
			else {
				positionIndex = evalPiecePosition(3, reversePosition);
				sumBlack += staticValue + positionIndex + Mmobility[mobilityIndex];
			}
			break;
		case 'C':
			staticValue = evalPieceValue(4, board);
			if (piece->color == 'r') {
				positionIndex = evalPiecePosition(4, piece->position);
				sumRed += staticValue + positionIndex + Cmobility[mobilityIndex];
			}
			else {
				positionIndex = evalPiecePosition(4, reversePosition);
				sumBlack += staticValue + positionIndex + Cmobility[mobilityIndex];
			}
			break;
		case 'P':
			staticValue = evalPieceValue(5, board);
			if (piece->color == 'r') {
				positionIndex = evalPiecePosition(5, piece->position);
				sumRed += staticValue + positionIndex + Pmobility[mobilityIndex];
			}
			else {
				positionIndex = evalPiecePosition(5, reversePosition);
				sumBlack += staticValue + positionIndex + Pmobility[mobilityIndex];
			}
			break;
		case 'B':
			staticValue = evalPieceValue(6, board);
			if (piece->color == 'r') {
				positionIndex = evalPiecePosition(6, piece->position);
				sumRed += staticValue + positionIndex + Bmobility[mobilityIndex];
			}
			else {
				positionIndex = evalPiecePosition(6, reversePosition);
				sumBlack += staticValue + positionIndex + Bmobility[mobilityIndex];
			}
			break;
		}
	}
	//float D = sumBlack - sumRed;;
	//System.out.println(D);
	switch (player) {
	case 'r':
		return (int)(sumRed - sumBlack);
	case 'b':
		return (int)(sumBlack - sumRed);
	default:
		return -1;

	}
}


int* EvalModel::evalPieceValue(Board* board)
{
	int CMP = 0;
	if (board->cells)
	for (auto& colomn : board->cells) {
		for (auto& piece : colomn) {
			
			if ((piece->character == 'C') || (piece->character == 'M') || (piece->character == 'P')) {
				CMP++;
			}
		}
	}
	int *pieceValue;
	/* J | S| X | M | C | P | B*/
    if (false/*判定开局的条件*/)
    {
        //开局固有价值分
        int temp[] = { 50000, 180, 200, 450, 1000, 480, 70 };
        pieceValue = temp;
    }
	else if (CMP <= 6) 
    {
        //残局固有价值分
		int temp[] =  {50000, 190, 210, 550, 1000, 500, 200};
		pieceValue = temp;
	}
	else
    {
        //中局固有价值分
		int temp[] =  {50000, 220, 250, 450, 1000, 500, 70};
		pieceValue = temp;
	}
	return pieceValue;
}

int EvalModel::evalPiecePosition(int p, char* pos)
{
	switch (p)
	{
	case 0:
	{
		return jPosition[pos[0]][pos[1]];
		break;
	}
	case 1:
	{
		return sPosition[pos[0]][pos[1]];
		break;
	}
	case 2:
	{
		return xPosition[pos[0]][pos[1]];
		break;
	}
	case 3:
	{
		return mPosition[pos[0]][pos[1]];
		break;
	}
	case 4:
	{
		return cPosition[pos[0]][pos[1]];
		break;
	}
	case 5:
	{
		return pPosition[pos[0]][pos[1]];
		break;
	}
	case 6:
	{
		return bPosition[pos[0]][pos[1]];
		break;
	}
	default:
	{
		break;
	}

	}

	return -1;
}