#include <iostream>

using namespace std;

class A {
    protected : int x;
public:
A() { x=0; }
A(int x) { this->x = x;
    cout<< "해당 객체의 x값 : "<<x<<endl;
}
    
};
class B : public A { int y;
public:
B(int x, int y) : A(x+5) { this->y=y; } };
class C : public B { int m;
public:
C(int x, int y, int z) : B(x, y) { m=x*y*z;
    cout<< "해당 객체의 x,y,z,m값 : "<<x<<y<<z<<m<<endl;
}
    void getXValue(){
        cout<<this->x<<endl;
    }
}

;


int main(int argc, const char * argv[]) {
    // insert code here...
    C c(3,5,2);
    c.getXValue();
    
    return 0;
}
