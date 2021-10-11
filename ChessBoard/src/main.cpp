#include <string>
#include <exception>
#include <iostream>
#include "ChessBoard/chess_board_loader.hpp"
#include "ChessBoard/chess_board.hpp"
#include "Canvas/standard_ouput.hpp"


int main(int arg_num, char *args[]) 
{
    try 
    {
        auto chess_board = Loader::LoadChessBoard(arg_num, args);
        chess_board.Draw(StandartOutput());
    } 
    catch (const std::exception& exc) 
    {
        std::cout << exc.what() << std::endl;
        //TODO: show usage
    }
}
