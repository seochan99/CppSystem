#include <iostream>

using namespace std;

class Test{
    int num1;
    static int a;
public:
    Test(){
        this->num1 = 10;
    }
    static void P(){
        cout<<a<<endl;
    }
    
    void printVal(){
        cout<<"일반 맴버 변수 : "<<num1<<endl;
        cout<<"static member var : "<<a<<endl;
        cout<<"------------------------"<<endl;
    }
    
    void setStatic(int x){
        this->a = x;
    }
    void setNum(int x){
        this->num1 = x;
    }
};


// static member initialize
int Test::a = 0;

int main(void)
{
    Test::P();
    
    Test t1;
    Test t2;
    
    t1.printVal();
    t2.printVal();
    
    t1.setStatic(100);
    t2.setNum(22);
    
    t1.printVal();
    t2.printVal();
    return 0;
}

