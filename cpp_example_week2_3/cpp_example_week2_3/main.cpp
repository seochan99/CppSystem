#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    // 문자열 선언
    string result;
    int stringLength;
    
    
    //문자열 입력
    cout<<"문자열을 입력하세요 : ";
    getline(cin, result);
    
    // 문자열 길이 length를 통해 가져오기
    stringLength = result.length();
    
     // 문자열  뒤집어서 출력
    cout<<"반대로 출력 : ";
    for(int i= stringLength-1;i>=0;i--)
    {
        cout<<result[i];
    }
    cout<<endl;
    
    
        
    return 0;
}
