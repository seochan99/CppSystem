#include <iostream>

using namespace std;

// Number 클래스 작성하기
class Number{
private:
    int start = 656; //시작 점
    int end = 789; // 끝 점
    int total = 0; // 총합
    friend class Cal; // Cal freind 선언
};

// Cal 클래스 작성하기
class Cal{
public:
    // calNum method, freind Number 참조해서 가져오기
    void calNum(Number& N){
        for(int i=N.start;i<N.end;i++)
        {
            // i가 7로 나눠떨어지는 i 출력하기
            if(i%7 == 0){
                cout<<"7로 나누어진 숫자는 "<<i<<endl;
                // 7로 나눠떨어지는 수 total에 저장
                N.total+=i;
            }
        }
        // total 출력
        cout<<"7로 나눌 수 있는 모든 수의 합은 "<<N.total<<endl;
    }
};

int main(void)
{
    // Cal클래스 c 인스턴스 생성
    Cal c;
    // Number 클래스 n 인스턴스 생성
    Number n;
    
    // c Method calNum 불러오기
    c.calNum(n);
    
    return 0;
}
