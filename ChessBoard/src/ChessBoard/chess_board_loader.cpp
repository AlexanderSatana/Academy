#include <iostream>
#include <sstream>
#include "chess_board_loader.hpp"
#include "chess_board.hpp"

ChessBoard Loader::LoadChessBoard(int args_num, char* args[]) 
{
	if (args_num != 3) 
	{
		throw std::ios_base::failure("Expected board width and height");
	}
	
	std::stringstream width_stream(args[1]),
					  height_stream(args[2]);
	int32_t width,
			height;

	width_stream >> width;
	height_stream >> height;
	if (width <= 0 || height <= 0)
	{
		 throw std::ios_base::failure("Chess board's side cannot be negative");
	}

	return ChessBoard(width, height);
}
