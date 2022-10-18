#include <iostream>
#include <string>

using namespace std;

void swap(string lat, int len)
{
    
    cout<<"원본 문자열 : "<<lat;
    // 문자열 체크
    for(int i=0;i<len;i++)
    {
        // 만약 소문자라면
        if(islower(lat[i]))
            // 대문자로
            lat[i]=toupper(lat[i]);
        // 그외에는
        else
            // 소문자로
            lat[i]=towlower(lat[i]);
    }
    // 변경된 문자열 출력
    cout<<", 대소문자 변경-> "<<lat<<endl;
    
}

int main(void)
{
    
    // 반복문 진행
    while (1) {
        // 문자열 선언 및 초기화
        string latter;
        cin>>latter;
        
        // 문자열 길이
        int len = latter.length();
        
        // 출력함수
        swap(latter,len);
    }
    return 0;
}
