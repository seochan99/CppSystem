#ifndef Rectangle_hpp
#define Rectangle_hpp

#include "Point.hpp"

// 사각형 클라스 선언 
class Rectangle
{
private:
    Point upLeft;
    Point lowRight;
public:
    Rectangle(const int &x1, const int &y1, const int &x2, const int &y2);
    void ShowRecInfo() const;
};

#endif /* Rectangle_hpp */
