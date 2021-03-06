// ChineseChess.cpp: 定义控制台应用程序的入口点。
//
//#define TEST_MOVE
#define USE_UCCI

#include <Windows.h>
#include <chrono>
#include <iostream>
#include <time.h>
#include <regex>

#include "board.h"
#include "searchModel.h"

map<char, int> g_piece_count;

#if  !defined(TEST_MOVE)
void init_board(Board* board)
{
	board->pieces[macro_bC0] = new Piece(macro_bC0, new int[2]{ 0, 0 });
	board->pieces[macro_bM0] = new Piece(macro_bM0, new int[2]{ 0, 1 });
	board->pieces[macro_bX0] = new Piece(macro_bX0, new int[2]{ 0, 2 });
	board->pieces[macro_bS0] = new Piece(macro_bS0, new int[2]{ 0, 3 });
	board->pieces[macro_bJ0] = new Piece(macro_bJ0, new int[2]{ 0, 4 });
	board->pieces[macro_bS1] = new Piece(macro_bS1, new int[2]{ 0, 5 });
	board->pieces[macro_bX1] = new Piece(macro_bX1, new int[2]{ 0, 6 });
	board->pieces[macro_bM1] = new Piece(macro_bM1, new int[2]{ 0, 7 });
	board->pieces[macro_bC1] = new Piece(macro_bC1, new int[2]{ 0, 8 });
	board->pieces[macro_bP0] = new Piece(macro_bP0, new int[2]{ 2, 1 });
	board->pieces[macro_bP1] = new Piece(macro_bP1, new int[2]{ 2, 7 });
	board->pieces[macro_bB0] = new Piece(macro_bB0, new int[2]{ 3, 0 });
	board->pieces[macro_bB1] = new Piece(macro_bB1, new int[2]{ 3, 2 });
	board->pieces[macro_bB2] = new Piece(macro_bB2, new int[2]{ 3, 4 });
	board->pieces[macro_bB3] = new Piece(macro_bB3, new int[2]{ 3, 6 });
	board->pieces[macro_bB4] = new Piece(macro_bB4, new int[2]{ 3, 8 });

	board->pieces[macro_rC0] = new Piece(macro_rC0, new int[2]{ 9, 0 });
	board->pieces[macro_rM0] = new Piece(macro_rM0, new int[2]{ 9, 1 });
	board->pieces[macro_rX0] = new Piece(macro_rX0, new int[2]{ 9, 2 });
	board->pieces[macro_rS0] = new Piece(macro_rS0, new int[2]{ 9, 3 });
	board->pieces[macro_rJ0] = new Piece(macro_rJ0, new int[2]{ 9, 4 });
	board->pieces[macro_rS1] = new Piece(macro_rS1, new int[2]{ 9, 5 });
	board->pieces[macro_rX1] = new Piece(macro_rX1, new int[2]{ 9, 6 });
	board->pieces[macro_rM1] = new Piece(macro_rM1, new int[2]{ 9, 7 });
	board->pieces[macro_rC1] = new Piece(macro_rC1, new int[2]{ 9, 8 });
	board->pieces[macro_rP0] = new Piece(macro_rP0, new int[2]{ 7, 1 });
	board->pieces[macro_rP1] = new Piece(macro_rP1, new int[2]{ 7, 7 });
	board->pieces[macro_rB0] = new Piece(macro_rB0, new int[2]{ 6, 0 });
	board->pieces[macro_rB1] = new Piece(macro_rB1, new int[2]{ 6, 2 });
	board->pieces[macro_rB2] = new Piece(macro_rB2, new int[2]{ 6, 4 });
	board->pieces[macro_rB3] = new Piece(macro_rB3, new int[2]{ 6, 6 });
	board->pieces[macro_rB4] = new Piece(macro_rB4, new int[2]{ 6, 8 });

	for (auto & piece : board->pieces)
	{
		board->update(piece.second);
	}
}

#else
void init_board(Board* board)
{
	/*
	board->pieces[macro_bC0] = new Piece(macro_bC0, new int[2]{ 0, 0 });
	board->pieces[macro_bM0] = new Piece(macro_bM0, new int[2]{ 0, 1 });
	board->pieces[macro_bX0] = new Piece(macro_bX0, new int[2]{ 0, 2 });
	board->pieces[macro_bS0] = new Piece(macro_bS0, new int[2]{ 0, 3 });
	board->pieces[macro_bJ0] = new Piece(macro_bJ0, new int[2]{ 0, 4 });
	board->pieces[macro_bS1] = new Piece(macro_bS1, new int[2]{ 0, 5 });
	board->pieces[macro_bX1] = new Piece(macro_bX1, new int[2]{ 0, 6 });
	board->pieces[macro_bM1] = new Piece(macro_bM1, new int[2]{ 0, 7 });
	board->pieces[macro_bC1] = new Piece(macro_bC1, new int[2]{ 0, 8 });
	board->pieces[macro_bP0] = new Piece(macro_bP0, new int[2]{ 2, 4 });
	board->pieces[macro_bP1] = new Piece(macro_bP1, new int[2]{ 2, 7 });
	board->pieces[macro_bB0] = new Piece(macro_bB0, new int[2]{ 3, 0 });
	board->pieces[macro_bB1] = new Piece(macro_bB1, new int[2]{ 3, 2 });
	board->pieces[macro_bB2] = new Piece(macro_bB2, new int[2]{ 3, 4 });
	board->pieces[macro_bB3] = new Piece(macro_bB3, new int[2]{ 3, 6 });
	board->pieces[macro_bB4] = new Piece(macro_bB4, new int[2]{ 3, 8 });

	board->pieces[macro_rC0] = new Piece(macro_rC0, new int[2]{ 9, 0 });
	board->pieces[macro_rM0] = new Piece(macro_rM0, new int[2]{ 9, 1 });
	board->pieces[macro_rX0] = new Piece(macro_rX0, new int[2]{ 9, 2 });
	board->pieces[macro_rS0] = new Piece(macro_rS0, new int[2]{ 9, 3 });
	board->pieces[macro_rJ0] = new Piece(macro_rJ0, new int[2]{ 9, 4 });
	board->pieces[macro_rS1] = new Piece(macro_rS1, new int[2]{ 9, 5 });
	board->pieces[macro_rX1] = new Piece(macro_rX1, new int[2]{ 9, 6 });
	board->pieces[macro_rM1] = new Piece(macro_rM1, new int[2]{ 9, 7 });
	board->pieces[macro_rC1] = new Piece(macro_rC1, new int[2]{ 9, 8 });
	board->pieces[macro_rP0] = new Piece(macro_rP0, new int[2]{ 7, 1 });
	board->pieces[macro_rP1] = new Piece(macro_rP1, new int[2]{ 7, 3 });
	board->pieces[macro_rB0] = new Piece(macro_rB0, new int[2]{ 6, 0 });
	board->pieces[macro_rB1] = new Piece(macro_rB1, new int[2]{ 6, 2 });
	board->pieces[macro_rB2] = new Piece(macro_rB2, new int[2]{ 6, 4 });
	board->pieces[macro_rB3] = new Piece(macro_rB3, new int[2]{ 6, 6 });
	board->pieces[macro_rB4] = new Piece(macro_rB4, new int[2]{ 6, 8 });
	*/
	board->pieces[macro_bC0] = new Piece(macro_bC0, new int[2]{ 0, 0 });
	board->pieces[macro_bM0] = new Piece(macro_bM0, new int[2]{ 0, 1 });
	board->pieces[macro_bX0] = new Piece(macro_bX0, new int[2]{ 0, 2 });
	board->pieces[macro_bS0] = new Piece(macro_bS0, new int[2]{ 0, 3 });
	board->pieces[macro_bJ0] = new Piece(macro_bJ0, new int[2]{ 0, 4 });
	board->pieces[macro_bS1] = new Piece(macro_bS1, new int[2]{ 0, 5 });
	board->pieces[macro_bX1] = new Piece(macro_bX1, new int[2]{ 0, 6 });
	board->pieces[macro_bM1] = new Piece(macro_bM1, new int[2]{ 0, 7 });
	board->pieces[macro_bC1] = new Piece(macro_bC1, new int[2]{ 0, 8 });
	board->pieces[macro_bP0] = new Piece(macro_bP0, new int[2]{ 2, 3 });
	board->pieces[macro_bP1] = new Piece(macro_bP1, new int[2]{ 2, 7 });
	board->pieces[macro_bB0] = new Piece(macro_bB0, new int[2]{ 3, 0 });
	board->pieces[macro_bB1] = new Piece(macro_bB1, new int[2]{ 3, 2 });
	board->pieces[macro_bB2] = new Piece(macro_bB2, new int[2]{ 3, 4 });
	board->pieces[macro_bB3] = new Piece(macro_bB3, new int[2]{ 3, 6 });
	board->pieces[macro_bB4] = new Piece(macro_bB4, new int[2]{ 3, 8 });

	board->pieces[macro_rC0] = new Piece(macro_rC0, new int[2]{ 9, 0 });
	board->pieces[macro_rM0] = new Piece(macro_rM0, new int[2]{ 9, 1 });
	board->pieces[macro_rX0] = new Piece(macro_rX0, new int[2]{ 9, 2 });
	board->pieces[macro_rS0] = new Piece(macro_rS0, new int[2]{ 9, 3 });
	board->pieces[macro_rJ0] = new Piece(macro_rJ0, new int[2]{ 9, 4 });
	board->pieces[macro_rS1] = new Piece(macro_rS1, new int[2]{ 9, 5 });
	board->pieces[macro_rX1] = new Piece(macro_rX1, new int[2]{ 9, 6 });
	board->pieces[macro_rM1] = new Piece(macro_rM1, new int[2]{ 9, 7 });
	board->pieces[macro_rC1] = new Piece(macro_rC1, new int[2]{ 9, 8 });
	board->pieces[macro_rP0] = new Piece(macro_rP0, new int[2]{ 7, 1 });
	board->pieces[macro_rP1] = new Piece(macro_rP1, new int[2]{ 7, 4 });
	board->pieces[macro_rB0] = new Piece(macro_rB0, new int[2]{ 6, 0 });
	board->pieces[macro_rB1] = new Piece(macro_rB1, new int[2]{ 6, 2 });
	board->pieces[macro_rB2] = new Piece(macro_rB2, new int[2]{ 6, 4 });
	board->pieces[macro_rB3] = new Piece(macro_rB3, new int[2]{ 6, 6 });
	board->pieces[macro_rB4] = new Piece(macro_rB4, new int[2]{ 6, 8 });

	for (auto & piece : board->pieces)
	{
		board->update(piece.second);
	}
}
#endif

unsigned long get_current_time()
{
	unsigned long startTime =
		std::chrono::system_clock::now().time_since_epoch() /
		std::chrono::milliseconds(1);

	return startTime;
}

char get_control_val()
{
	char control_val = 'a';
	FILE * pFile = 0;
	fopen_s(&pFile, "d:\\control.txt", "rb");
	if (0 != pFile)
	{
		fread(&control_val, 1, 1, pFile);
		fclose(pFile);
		pFile = 0;
	}

	return control_val;
}
void get_pos_from_str(string str_pos, char * pos)
{
	pos[1] = str_pos[0] - 'a';
	pos[0] = str_pos[1] - '0';
	pos[0] = 9 - pos[0];
}

string set_pos_to_str(char * pos)
{
	string pos_str;
	pos_str = "a1";
	pos_str[1] = '0' + (9 - pos[0]);
	pos_str[0] = 'a' + pos[1];
	return pos_str;
}

// We get move positions
vector<string> parse_position(string s, char& move_side)
{
	vector<string> moves;
	std::regex word_regex("(\\S+)");
	auto words_begin =
		std::sregex_iterator(s.begin(), s.end(), word_regex);
	auto words_end = std::sregex_iterator();

	bool start_get_move = false;
	int next_segs = 0;
	if (s.find("position startpos") != string::npos)
	{
		moves.push_back("");
		for (std::sregex_iterator i = words_begin; i != words_end; ++i)
		{
			std::smatch match = *i;
			std::string match_str = match.str();
			if (start_get_move)
			{
				if (0 == next_segs)
				{
					moves.push_back(match_str);
				}
				else
				{
					--next_segs;
				}				
			}

			if (match_str == "moves")
			{
				start_get_move = true;
				next_segs = 0;
			}
		}
	}
	else if (s.find("position fen") != string::npos)
	{
		for (std::sregex_iterator i = words_begin; i != words_end; ++i)
		{
			std::smatch match = *i;
			std::string match_str = match.str();
			if (start_get_move)
			{
				if (0 == next_segs)
				{
					moves.push_back(match_str);
					start_get_move = false;
				}
				else
				{
					moves.push_back(match_str);
				}
			}

			if (match_str == "fen")
			{
				start_get_move = true;
				next_segs = 0;
			}

			if (match_str == "moves")
			{
				start_get_move = true;
				next_segs = 1;
			}

			if (match_str == "w")
			{
				move_side = 'r';
			}

			if (match_str == "b")
			{
				move_side = 'b';
			}
		}
	}

	return moves;
}

char make_piece_name(char side, char piece_desc, char orig_piece)
{
	char side_idx = 0; // 0 for black 1 for red
	char piece_idx = 0; // 
	if (side == 'r')
	{
		side_idx = 1;
	}
	else
	{
		side_idx = 0;
	}

	switch (piece_desc)
	{
	case 'k':
		piece_idx = 0;
		break;
	case 'a':
		piece_idx = 1;
		break;
	case 'b':
		piece_idx = 2;
		break;
	case 'n':
		piece_idx = 3;
		break;
	case 'r':
		piece_idx = 4;
		break;
	case 'c':
		piece_idx = 5;
		break;
	case 'p':
		piece_idx = 6;
		break;
	default:
		break;
	}


	char piece_count = 0;
	map<char, int>::iterator it = g_piece_count.find(orig_piece);

	if (it != g_piece_count.end())
	{
		// piece_count
		piece_count = g_piece_count[orig_piece];
	}
	else
	{
		piece_count = 0;		
	}
	char piece_name = ((piece_count << 4) | (piece_idx << 1) | side_idx);
	g_piece_count[orig_piece] = piece_count + 1;
	
	return piece_name;
}

list<Piece*> get_pos_from_fen(string line_desc, int line_idx, Board * board)
{
	// Lower case is black, while upper case is red
	// We assume fen describe the board from top to bottom
	// 
	list<Piece*> moves;
	int idx = 0;
	int total_len = line_desc.length();
	int col_idx = 0;
	for (idx = 0; idx < total_len; ++idx)
	{
		if (line_desc[idx] >= '0' && line_desc[idx] <= '9')
		{
			col_idx += (line_desc[idx] - '0');
		}
		else if (line_desc[idx] >= 'a' && line_desc[idx] <= 'z')
		{
			char piece_name = make_piece_name('b', line_desc[idx], line_desc[idx]);
			Piece * new_move = new Piece(piece_name, new int[2]{ line_idx, col_idx });
			board->update(new_move);
			col_idx += 1;
		}
		else if (line_desc[idx] >= 'A' && line_desc[idx] <= 'Z')
		{
			char piece_desc = line_desc[idx] - 'A' + 'a';
			char piece_name = make_piece_name('r', piece_desc, line_desc[idx]);
			Piece * new_move = new Piece(piece_name, new int[2]{ line_idx, col_idx });
			board->update(new_move);
			col_idx += 1;
		}
	}	

	return moves;
}

void get_startup_pos(string s, Board * board)
{
	s += "/";

	std::regex word_regex("([a-zA-Z0-9]+)\/");
	auto words_begin =
		std::sregex_iterator(s.begin(), s.end(), word_regex);
	auto words_end = std::sregex_iterator();
	int line_idx = 0;
	g_piece_count.clear();

	for (std::sregex_iterator i = words_begin; i != words_end; ++i)
	{		
		std::smatch match = *i;
		std::string match_str = match.str();
		int len = match_str.length();
		string line_desc = match_str.substr(0, len - 1);
		get_pos_from_fen(line_desc, line_idx, board);
		
		++line_idx;
	}
}

void update_board_with_move(Board * board, string move_str)
{
	string move_start_str = move_str.substr(0, 2);
	string move_end_str = move_str.substr(2, 2);
	char start_pos[2];
	char end_pos[2];
	get_pos_from_str(move_start_str, start_pos);
	get_pos_from_str(move_end_str, end_pos);
	board->updatePiece(start_pos, end_pos);
}

Board * make_scene(string s)
{
	Board * board = new Board();
	char move_side = 'r';
	vector<string> li = parse_position(s, move_side);

	bool is_first = true;
	int move_count_after_startpos = 0;
	bool from_startpos = false;
	for (auto str : li)
	{
		if (is_first)
		{
			if (str != "")
			{
				get_startup_pos(str, board);
			}
			else
			{
				init_board(board);
				from_startpos = true;
			}

			is_first = false;
		}
		else
		{
			++move_count_after_startpos;
			update_board_with_move(board, str);
		}
	}

	bool change_move_side = false;

	if (0 == (move_count_after_startpos % 2))
	{
		change_move_side = false;			
	}
	else
	{
		change_move_side = true;			
	}

	if (change_move_side)
	{
		if ('r' == move_side)
		{
			move_side = 'b';
		}
		else
		{
			move_side = 'r';
		}
	}


	board->player = move_side;
	return board;
}

void test_regex()
{
	// 
	//string s = "position startpos moves b2e2";
	string s = "position fen 9/9/3k5/9/9/9/4R4/3A5/4K4/8r w - - 0 1 moves i0i1 e1e0 i1i0 e0e1 i0i1 e1e0 i1i0 e0e1 i0i1";
	//string s = "position fen 1r2kab1r/2c1a4/n1c1b1n2/4p2N1/p1p6/1C4P2/P1P1P4/2N1B3C/4A4/1RBAK2R1 w - - 0 1 moves h6i4 i9h9 i4h6 h9i9";
	//string s = "position fen 9/9/3k5/9/9/9/4R4/3A5/8r/4K4 b - -0 1";

	Board * board = 0;
	board = make_scene(s);
	
	SearchModel S;
	S.search(board, 'r');

	board->display();
}

int main()
{
	//test_regex();
	SearchModel searchModel;

#if defined(USE_UCCI)
#if defined(DEBUG_UCCI)
	while (true)
	{
		char control_val = get_control_val();
		if (control_val == 'b')
		{
			break;
		}

		Sleep(1000);
	}
#endif
	Board *pBoard = 0;
	string strInput;
	char output_buffer[1024] = { 0 };
	while (true)
	{
		std::getline(cin, strInput);
		if (strInput == "ucci")
		{
			cout << "id name Tencent Poker Chinese Chess AI Engine 1.0" << endl;
			cout << "id copyright 1998-2018 www.tencent.com" << endl;
			cout << "id author Yang Jing" << endl;
			cout << "ucciok" << endl;
		}
		else if (strInput == "isready")
		{
			cout << "readyok" << endl;
		}
		else if (strInput == "quit")
		{
			cout << "bye" << endl;
			exit(0);
		}
		else if (strInput.find("position") == 0)
		{
			if (pBoard != 0)
			{
				delete pBoard;
				pBoard = 0;
			}

			pBoard = make_scene(strInput);

		}
		else if (strInput.find("setoption") == 0)
		{
			int b = 10;
			//	cout << "xx" << endl;
		}
		else if (strInput.find("go") == 0)
		{
			int b = 10;
			//	cout << "xx" << endl;

			AlphaBetaNode* result = searchModel.search(pBoard, pBoard->player);
			string start_pos_str = set_pos_to_str(result->from);
			string end_pos_str = set_pos_to_str(result->to);
			sprintf_s(output_buffer, sizeof(output_buffer), "bestmove %s", (start_pos_str + end_pos_str).c_str());
			cout << output_buffer << endl;
		}

		// cout << "received:" << strInput << endl;
		continue;
	}

#endif
	// Test regex
	//test_regex();
	//return 0;
	
	
	Board board;
	init_board(&board);
	char move_side = 'b'; // true for red, and false for black
	board.player = move_side;

	while (true)
	{
		unsigned long start_time = get_current_time();

		AlphaBetaNode* result = searchModel.search(&board, board.player);

	

		// Apply move choice to board
		board.updatePiece(result->piece, result->to);
		delete result;
		printf("--------------after AI move--------------\n");
		board.display();

		int start_pos[2];
		int end_pos[2];
		cin >> start_pos[0];
		cin >> start_pos[1];
		cin >> end_pos[0];
		cin >> end_pos[1];
		printf("--------------after player move--------------\n");
		int a = 10;
		Piece * move_piece = board.cells[start_pos[0]][start_pos[1]];
		char end_pos_s[2];
		end_pos_s[0] = end_pos[0];
		end_pos_s[1] = end_pos[1];
		board.updatePiece(move_piece->key, end_pos_s);

	}

    return 0;
}

