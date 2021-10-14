#pragma once
#include <string>
#include "object.hpp"


class Triangle : public Object
{
    public:
        Triangle() = delete;
        Triangle(std::string,  float, float, float);
        ~Triangle() = default;
        const bool operator<(const Object& other) const ;
        const bool operator<(const Triangle& other) const;
        const float Hash() const override;
        const float GetSquare() const;
        const std::string ToString() const override;
        
    private:
        float   m_a;
        float   m_b;
        float   m_c;
        float   m_square;
        std::string m_name;
};

bool CheckForTriangleParameters(std::string&, float&, float&, float&);