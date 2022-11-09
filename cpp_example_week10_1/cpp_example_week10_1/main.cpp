#include <iostream>

using namespace std;

class F_test1{
    int a;
    friend class F_test2; // friend keyword
};

class F_test2{
public:
    void set(F_test1& F,int x){ //F_test1 referece
        F.a =x;
    }
    
    // F_test2는 F_test1 친구이므로 F_test1의 private member에 대한 접근이 가능하다.
    void printInfo(F_test1& F){
        cout<<"private - F_test1 a vlaue : "<<F.a<<endl;
    }
};

int main(void)
{
    F_test1 f1;
    F_test2 f2;
    
    f2.set(f1, 777);
    f2.printInfo(f1); 
    return 0;
}

