#include <iostream>
using namespace std;

int main(){
    char strBuf[100];
    // (1) get()
    cin.get(strBuf,100);
    
    cout<<strBuf<<endl;
    // (2)
    cout<<"get() func : "<<strlen(strBuf)<<"뮨자 읽음 "<<endl<<endl;
    
    cin.ignore(); // 입력 버퍼 비우기

    
    // (4) getline() 사용
    cin.getline(strBuf, 100);
    
    cout<<strBuf<<endl;
    cout<<"getline() func : "<<strlen(strBuf)<<"뮨자 읽음 "<<endl<<endl;
    // Enter키까지 읽으므로 get()보다 하나 ccount가 많음
    
}
