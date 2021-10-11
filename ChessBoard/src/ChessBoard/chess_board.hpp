#pragma once
#include "i_drawable.hpp"
#include "../Canvas/i_canvas.hpp"

using uint = unsigned int;

class ChessBoard : public IDrawable
{
    public:
        ChessBoard() = delete;
        ChessBoard(uint, uint);
        ~ChessBoard() = default;
        void Draw(const ICanvas& canvas) const override;

    private:
        uint m_width,
            m_height;
};