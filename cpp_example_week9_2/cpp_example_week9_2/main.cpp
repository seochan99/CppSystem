#include <iostream>
using namespace std;
class Car{
public:
    static int cnt; // 차 수량 static으로 저장하기 
    string name;
    // static member var
    // 차랑 변호
    // 차량 이름
    // 표시
    // 생성된 객체 수
    
    //생성자
    Car(){
        cnt++; // 차 수량 올리기
    }
    
    void getCar(){
        cout<<"차랑 변호 : "<<this->name;
        
    }
};

int Car::cnt = 0;

int main(void)
{
    
    
    return 0;
}
