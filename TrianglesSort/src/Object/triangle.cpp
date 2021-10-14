#include <math.h>
#include "triangle.hpp"

Triangle::Triangle(std::string name, float a, float b, float c) 
        : m_name(name), m_a(a), m_b(b), m_c(c)
{
    float p = (a + b + c) / 2;
    m_square = std::sqrt(p * (p - a) * (p - b) * (p - c));
}

const float Triangle::Hash() const 
{
    return GetSquare();
}

const float Triangle::GetSquare() const
{
    return m_square;
}

const std::string Triangle::ToString() const
{
    std::ostringstream name_to_return;
    name_to_return  << "[Triangle "
                    << m_name << "]: "
                    << m_square << " cm";
                    
    return name_to_return.str();
}

bool CheckForTriangleParameters(
        std::string& name, 
        float& a, 
        float& b, 
        float& c)
{
    return name.size() > 0 && a > 0 && b > 0 && c > 0;
}