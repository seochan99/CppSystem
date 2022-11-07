#include <iostream>

using namespace std;

class Car{
private:
    int speed;
    int gear;
    string color;
    int id;
    static int cnt;
public:
    Car(int speed=0,int gear=1,string color = "White")
    {
        this->speed = speed;
        this->gear = gear;
        this->color = color;
        cnt++;
        this->id = cnt;
    }
    
    static int getNumberOfCars(){
        return cnt;
    }
};

int Car::cnt = 0;

int main(void)
{
    Car a = Car(100,2,"Red");
    Car b = Car(100,2,"black");
    Car c = Car(100,2,"yellow");
    Car d = Car();
    
    cout<<"지금까지 생성된 자동차 수 : "<<Car::getNumberOfCars()<<endl;
    
    return 0;
}
