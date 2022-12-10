#include <iostream>

using namespace std;

class AbstractGate{
protected:
    bool x,y;
public:
    // set() 함수, 매개변수 x,y
    void set(bool x, bool y){
        this->x = x;
        this->y = y;
    }
    // opreation() 함수 작성
    virtual bool opreation()=0;
};

// ANDGate class작성
class ANDGate : public AbstractGate{
public:
    virtual bool opreation()
    {
        // 둘다 true일때
        if(this->x && this->y){
            return true;
        }
        return false;
    }
};
int main(){
    ANDGate andGate;
    
    andGate.set(true,false);
    
    cout.setf(ios::boolalpha); // bool값을 true,false문자열로 출력함
    cout<<"실행결과: "<<andGate.opreation()<<endl;
    
    return 0;
}
