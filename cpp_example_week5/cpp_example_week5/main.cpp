#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Circle{
private:
    int x; // x좌표
    int y; // y좌표
    int radius; // 원 반지름 r
public:
    // 생성자
    Circle(){};
    Circle(int xPos,int yPos, int r):x(xPos),y(yPos),radius(r){}
    
    
    // 출력 맴버함수
    void print(){
        cout<<"반지름 : "<<radius<<" @("<<x<<", "<<y<<")"<<endl;
    }
    
    ~Circle(){};
};

int main(void)
{
    // 배열선언
    Circle *c = new Circle[10];
    
    //seed값 현재시간으로
    srand((unsigned int)time(NULL));
    
    // 객체 생성자로 초기화, 출력
    for(int i=0;i<10;i++)
    {
        c[i]=Circle(rand() % 501,rand() % 301,rand() % 101);
        c[i].print();
    }
    
    // 할당해제
    delete [] c;
    
    return 0;
}

