#pragma once

using uint = unsigned int;

class Envelope 
{
    public:
        Envelope(uint w, uint h);
        uint GetWidth() const;
        uint GetHeight() const;
        bool CanBePutIn(const Envelope& other) const;
        
    private:
        uint m_width;
        uint m_height;
};
