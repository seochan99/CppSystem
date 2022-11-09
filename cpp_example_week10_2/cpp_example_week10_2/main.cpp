#include <iostream>

using namespace std;

class Num{
    int num; // 입력한 글자 수
    friend class Pyramid;
};


class Pyramid{
    void getNum(Num& n){
        cin>>n.num;
    }
    
};

int main(void)
{
    // friends 사용
    
    // 입력한 글주수에 따라
    
    // 알파벳 피라미드 패턴 실행결과 표시
    
    return 0;
}
