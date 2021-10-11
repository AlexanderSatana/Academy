#pragma once
#include "chess_board.hpp"

class Loader {
	public:
		static ChessBoard LoadChessBoard(int arg_num, char* args[]);
};
