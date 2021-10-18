#pragma once
#include <string>
#include "object.hpp"


class Triangle : public IObject
{
    public:
        Triangle() = delete;
        Triangle(std::string,  float, float, float);
        ~Triangle() = default;
        bool operator<(const IObject& other) const ;
        bool operator<(const Triangle& other) const;
        float Hash() const override;
        float GetSquare() const;
        std::string ToString() const override;
        
    private:
        float   m_a;
        float   m_b;
        float   m_c;
        float   m_square;
        std::string m_name;
};

bool CheckForTriangleParameters(std::string&, float&, float&, float&);