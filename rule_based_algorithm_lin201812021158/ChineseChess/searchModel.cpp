#include <chrono>
#include <algorithm>

#include "searchModel.h"
#include "rules.h"
#include "evalModel.h"


char get_oppo_move_side(char move_side)
{
	switch (move_side)
	{
	case 'r':
		return 'b';
		break;
	case 'b':
		return 'r';
		break;
	default:
		break;

	}
}

SearchModel::SearchModel()
{
}


SearchModel::~SearchModel()
{
}
char SearchModel::hasWin() 
{
	/**
	* Judge has the game ended.
	* @return 'r' for RED wins, 'b' for BLACK wins, 'x' for game continues.
	* */
	bool isRedWin = board->pieces[macro_bJ0] == 0;
	bool isBlackWin = board->pieces[macro_rJ0] == 0;
	if (isRedWin) return 'r';
	else if (isBlackWin) return 'b';
	else return 'x';
}

bool compare_node_descend(AlphaBetaNode* left_node, AlphaBetaNode* right_node)
{
	if (left_node->value > right_node->value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool compare_node_ascend(AlphaBetaNode*  left_node, AlphaBetaNode*  right_node)
{
	if (left_node->value < right_node->value)
	{
		return true;
	}
	else
	{
		return false;
	}
}

list<AlphaBetaNode*>* SearchModel::generateMovesForAll(char move_side)
{
	list<AlphaBetaNode*>* moves = new list<AlphaBetaNode*>();
	for (auto& stringPieceEntry : board->pieces) {
		Piece* piece = stringPieceEntry.second;
		if (0 == piece)
		{
			continue;
		}
		if (piece->color != move_side) continue;

		char from_pos[2];
		from_pos[0] = piece->position[0];
		from_pos[1] = piece->position[1];

		for (auto& nxt : *Rules::getNextMove(piece->key, piece->position, board))
		{
			Piece* eaten = board->updatePiece(piece->key, nxt);
			// Eval board score
			EvalModel eval_model;
			int board_val = eval_model.eval(board, this->move_side);

			board->updatePiece(piece->key, from_pos);
			if (eaten != 0) 
			{
				board->pieces[eaten->key] = eaten;
				board->backPiece(eaten->key);
			}

			moves->push_back(new AlphaBetaNode(piece->key, piece->position, nxt, board_val));
		}
	}

	// Sort moves by board score
	if (this->move_side == move_side)
	{
		// Same side, we order the moves in descending order.
		// 'cos we prefer big values
		moves->sort(compare_node_descend);
	}
	else
	{
		// Not the same side, we order the moves in ascending order,
		// 'cos we prefer small values
		moves->sort(compare_node_ascend);
	}

	return moves;
}

int SearchModel::alphaBeta(int depth, int alpha, int beta, char move_side)
{
	/* Return evaluation if reaching leaf node or any side won.*/

	if (depth == 0
		|| hasWin() != 'x'
		)
	{
		EvalModel eval_model;
		
		int eval_val = eval_model.eval(board, this->move_side);
		board->dumpToFile(move_side, eval_val);
		return eval_val;
	}

	list<AlphaBetaNode*>* moves = generateMovesForAll(move_side);

	bool first_node = true;
	// Critical section?
	int nSearchedCount = 0;
	char oppo_move_side = get_oppo_move_side(move_side);
	for (auto& n : *moves)
	{
		++nSearchedCount;
		if (nSearchedCount > COERCE_LENGTH)
		{
			break;
		}
		Piece* eaten = board->updatePiece(n->piece, n->to);
		/* Is maximizing player? */
		int finalBeta = beta;
		int finalAlpha = alpha;
		int finalDepth = depth;
		int temp[1];

		int oppo_val = 0;
		if (first_node)
		{
			first_node = false;
			oppo_val = alphaBeta(depth - 1, alpha, beta, oppo_move_side);
		}
		else
		{
			if (this->move_side == move_side)
			{
				oppo_val = alphaBeta(depth - 1, alpha, alpha + 1, oppo_move_side);
			}
			else
			{
				oppo_val = alphaBeta(depth - 1, beta - 1, beta, oppo_move_side);
			}

			if (oppo_val > alpha && oppo_val < beta)
			{
				oppo_val = alphaBeta(depth - 1, alpha, beta, oppo_move_side);
			}
		}

		if (this->move_side == move_side)
		{
			alpha = max(alpha, oppo_val);
		}
		else
		{
			beta = min(beta, oppo_val);
		}

		board->updatePiece(n->piece, n->from);
		if (eaten != 0) {
			board->pieces[eaten->key] = eaten;
			board->backPiece(eaten->key);
		}

		delete n;

		/* Cut-off */
		if (beta <= alpha) break;
	}
	moves->clear();
	delete moves;

	return this->move_side == move_side ? alpha : beta;
}

AlphaBetaNode* SearchModel::search(Board* board, char move_side)
{
	this->move_side = move_side;
	
	this->board = board;
	if (board->pieces.size() < 28)
		DEPTH = 4;
	if (board->pieces.size() < 16)
		DEPTH = 4;
	if (board->pieces.size() < 10)
		DEPTH = 6;
	if (board->pieces.size() < 4)
		DEPTH = 6;
	else
		DEPTH = 4;

	AlphaBetaNode* best = 0;
	list<AlphaBetaNode*> *moves = generateMovesForAll(move_side);
	char oppo_move_side = get_oppo_move_side(move_side);
	int alpha = MIN_VALUE;
	int beta = MAX_VALUE;
	bool first_node = true;
	int nSearchedCount = 0;
	for (auto& n : *moves) {
		/* Move*/
		++nSearchedCount;
		if (nSearchedCount > COERCE_LENGTH)
		{
			break;
		}

		Piece* eaten = board->updatePiece(n->piece, n->to);

		n->value = alphaBeta(DEPTH, MIN_VALUE, MAX_VALUE, oppo_move_side);
		
		alpha = max(n->value, alpha);

		/* Back move*/
		board->updatePiece(n->piece, n->from);
		if (eaten != 0) {
			board->pieces[eaten->key] = eaten;
			board->backPiece(eaten->key);
		}

		/* Select a best move during searching to save time*/
		if (best == 0 || n->value >= best->value)
		{
			if (best != 0)
			{
				delete best;
			}
			best = n;
		}
		else
		{
			delete n;
		}		
	}

	moves->clear();
	delete moves;

	
	return best;
}
