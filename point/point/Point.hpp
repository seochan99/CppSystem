#ifndef __POINT_H_
#define __POINT_H_

// 포인트, 점 클라스 선언
class Point
{
private:
    int x;
    int y;
public:
    Point(const int &xpos, const int &ypos); // 생성자
    
    int GetX() const; // X좌표 가져오기 
    int GetY() const; // y좌표 가져오기
    
    bool SetX(int xpos); // x좌표 설정
    bool SetY(int ypos); // y좌표 설정 
};
#endif
