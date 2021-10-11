#include <limits>
#include <iostream>
#include "chess_board.hpp"
#include "../Canvas/i_canvas.hpp"


ChessBoard::ChessBoard(uint width, uint height) {
    if (width > std::numeric_limits<uint>::max())  width  = std::numeric_limits<uint>::max();
    if (height > std::numeric_limits<uint>::max()) height = std::numeric_limits<uint>::max();
    m_width     = width;
    m_height    = height;
}

void ChessBoard::Draw(const ICanvas& canvas) const 
{
    for (int h = 0; h < m_height; h++)
    {
        for (int w = 0; w < m_width; w++)
        {
            canvas << (h % 2 == w % 2 ? '*' : ' ');
        }
        canvas << '\n';
    }
}