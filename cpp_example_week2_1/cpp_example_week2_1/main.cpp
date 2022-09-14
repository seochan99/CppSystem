#include <iostream>
using namespace std;

int gcd(int a, int b) {
    
    // 나머지 변수 선언
    int namerge;
    
    // 유클리드 호제법 알고리즘
    // b가 0이 될때까지 반복 진행
    while (b != 0) {
        namerge = a % b;
        a = b;
        b = namerge;
    }
    return a;
}

int main()
{
    int num1, num2;
    
    cout<<"두 수를 입력하세요 :";
    cin >> num1 >> num2;
    
    cout <<"두 수의 최대공약수 : "<< gcd(num1, num2)<< endl;
    
    // 최소 공배수 공식 LCD(a,b) = (a*b)/GCD(a,b) 사용
    cout << "두 수의 최소공배수 : " << (num1*num2)/gcd(num1, num2) << endl;
}
