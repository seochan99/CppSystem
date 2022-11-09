#include <iostream>

using namespace std;
class F_test1; // 전방 선언
class F_test2{
public:
    void printInfo(F_test1& F);
};


class F_test1{
    int a;
public:
    F_test1(int a2=0) :a(a2){}
    friend void F_test2::printInfo(F_test1& F); // friend keyword
};

void F_test2::printInfo(F_test1& F){
    cout<<"private - F_test1 a vlaue : "<<F.a<<endl;
}

int main(void)
{
    F_test1 f1;
    F_test2 f2;

    f2.printInfo(f1);
    return 0;
}

