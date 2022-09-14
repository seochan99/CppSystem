#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    // 문자열 선언
    string result;
    
    //문자열 입력
    getline(cin, result);
    
    // 문자열 뒤집기
    reverse(result.begin(), result.end());
    
    // 문자열 출력
    cout<<result<<endl;
    return 0;
}
