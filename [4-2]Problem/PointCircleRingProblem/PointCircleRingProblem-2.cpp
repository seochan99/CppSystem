// 1과 달라진점
// 모든 클래스에 생성자 정의하기
#include <iostream>
using namespace std;


// 좌표
class Point
{
private:
    int xpos, ypos;
    
public:
    
    //생성자
    Point(int x, int y):xpos(x),ypos(y)
    {
        //empty
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
    // 생성자
    Circle(int x, int y,int r):rad(r),center(x,y)
    {}
    
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
    // 생성자
    Ring(int inX, int inY, int inR, int outX, int outY, int outR):inCircle(inX,inY,inR), outCircle(outX,outY,outR){
    }
    void showRingInfo() const
    {
        cout<<"Inner Circle Info..."<<endl;
        inCircle.ShowCircleInfo();
        
        cout<<"Out Circle Info..."<<endl;
        outCircle.ShowCircleInfo();
    }
};

int main(void)
{
    Ring ring(1, 1, 4, 2, 2, 9);
    ring.showRingInfo();
    return 0;
}
