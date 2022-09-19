#include <iostream>
#include <string>

using namespace std;

// Car 선언부
class Car{
public:
    string brand="Chan's Car";
    int speed = 180;
    int gear = 4;
    string color = "Gray";
    
    void speedUp();
    void speedDown();
    void colorTrans(string changeColor);
};

// Car 구현부
void Car::speedUp(){
    speed+=15;
};

void Car::speedDown(){
    speed-=10;
};

void Car::colorTrans(string changeColor){
    color = changeColor;
};

int main(void)
{
    Car car;
    cout<<"현재 속도는"<<car.speed<<", 기어는"<<car.gear<<", 현재 자동차 색상은 "<<car.color<<", 현재 자동차 브랜드는 "<<car.brand<<endl;
    car.speedUp();
    cout<<"속도 speedUp() 호출 : "<<car.speed<<endl;
    
    car.speedDown();
    cout<<"속도 speedDown() 호출 : "<<car.speed<<endl;
    
    car.colorTrans("Black");
    cout<<"자동차 색상 변경 colorTrans() 호출 : "<<car.color<<"으로 변경"<<endl;
    
    return 0;
}
