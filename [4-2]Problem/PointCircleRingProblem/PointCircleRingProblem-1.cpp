#include <iostream>
using namespace std;


// 좌표
class Point
{
private:
    int xpos, ypos;
    
public:
    
    //초기화
    void Init(int x,int y)
    {
        xpos = x;
        ypos = y;
    }
    
    // 정보출력
    void ShowPointInfo() const
    {
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
    }
};

class Circle
{
private:
    int rad; // 반지름
    Point center; // 원의 중심
    
public:
    // 원 초기화
    void Init(int x, int y, int r)
    {
        rad = r;
        center.Init(x, y);
    }
    
    // 원 정보 출력
    void ShowCircleInfo() const
    {
        cout<<"radius : "<<rad<<endl; //반지름 출력
        center.ShowPointInfo(); // 원의 중심 출력
    }
};

class Ring
{
private:
    Circle inCircle;
    Circle outCircle;
public:
    void Init(int inX, int inY, int inR, int outX, int outY, int outR)
    {
        inCircle.Init(inX, inY, inR);
        outCircle.Init(outX, outY, outR);
    }
    void showRingInfo() const
    {
        cout<<"Inner Circle Info..."<<endl;
        inCircle.ShowCircleInfo();
        
        cout<<"Out Circle Info..."<<endl;
        outCircle.ShowCircleInfo();
    }
};

//int main(void)
//{
//    Ring ring;
//    ring.Init(1, 1, 4, 2, 2, 9);
//    ring.showRingInfo();
//    return 0;
//}
