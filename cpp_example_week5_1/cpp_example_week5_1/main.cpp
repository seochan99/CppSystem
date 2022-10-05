#include <iostream>

using namespace std;

class Box{
private:
    double length;
    double breadth;
    double height;
public:
    Box(double l = 2.0, double b = 2.0, double h = 2.0){
        cout<<"Constructor Called. "<<endl;
        length = l;
        breadth = b;
        height = h;
    }
    double Volume(){
        return length*breadth*height;
    }
};

int main(void){
    Box Box1(3.3,1.2,1.5);
    Box Box2(2.3,5.2,7.5);
    
    Box *b1;
    Box *b2;
    
    b1 = &Box1;
    b2 = &Box2;
    
    cout<<"VOlume Of Box1"<<b1->Volume()<<endl;
    cout<<"VOlume Of Box2"<<b2->Volume()<<endl;

}
