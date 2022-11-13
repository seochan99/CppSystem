#include <iostream>

using namespace std;

class Num{
    int num; // 입력한 글자 수
    friend class Pyramid;
};


class Pyramid{
public:

    // 숫자 입력받는 method
    void getNum(Num& n){
        cout<<"글자수를 입력하세요(26이하의 숫자) : ";
        cin>>n.num;
    }
    
    // pyramid 출력 method
    void printPyramid(Num& n){
        // 첫번째 반복문 i가 n.num만큼 반복
        for (int i = 1; i <= n.num; i++) {
            
            // 공백 출력 반복문 j가 n.num-i될때까지 공백 두개씩 출력
            for (int j = 1; j <= n.num - i; j++) {
                // 공백 2개씩 출력
                cout<<"  ";
            }
            // 알파벳 출력 반복문
            // 홀수개씩 출력하기
            for (int j = 1; j <= i * 2 - 1; j++) {
                // 아스키코드로 알파벳 출력하기 위해 char형변환 시켜주기.
                // 삼항연산 j-i가 0보다 크면 j-i, 아니라면 -1(j-i)를 65+i-1에 빼줌
                char ch(65 + i - 1 - (j - i > 0 ? j - i : -1 * (j - i)));
                cout<<ch<<" ";
            }
            
            cout<<endl;
        }
    }
    
};

int main(void)
{
    // Num 인스턴스 n생성
    Num n;
    
    // Pyramid 인스턴스 p생성
    Pyramid p;
    
    // 숫자 입력받기
    p.getNum(n);
    
    // 피라미드 출력
    p.printPyramid(n);
    
    
    return 0;
}
