#include <iostream>
#include <string>

using namespace std;

void swap(string lat,int len){
    cout<<"원본 문자열 : "<<lat<<endl;
    
    // 역순 출력
    cout<<"역순 문자열 : ";
    // len값을 가지고 와 문자열 뒤부터 출력을 진행함
    for(int i=len;i>0;i--)
    {
        cout<<lat[i];
    }
    cout<<endl;
    
}

int main(void)
{
    string latter = "Lorem Ipsum is simply dummy text of the printing and typesetting industry.";
    int len;
    
    len = latter.length();
    
    // 출력함수 실행
    swap(latter,len);
    
    return 0;

}
