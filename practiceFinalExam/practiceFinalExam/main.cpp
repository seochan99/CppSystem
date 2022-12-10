#include <iostream>
using namespace std;

class Histogram{
    int cnt[26];
    string str;
    void makeHistro();
public:
    // 생성자 작성
    Histogram(string str="hi"){
        this->str = str;
    }
    // !연산자 함수 작성
    void operator!(){
        // 출력
        // 히스토그램 만들기
        cout<<"총 알파벳 수 : "<<str.length()<<endl;
        makeHistro();
        for(int i='a';i<='z';i++){
            cout<<char(i)<<" : ";
            for(int j=0;j<cnt[i-'a'];j++){
                cout<<"*";
            }
            cout<<endl;
        }
    }
    // a = 97
    // z = 122 
    // (3) << 연산자 함수 작성
    template <class T>
    Histogram& operator << (T s)
    {
        str+s;
        return *this;
    }
    
};

void Histogram::makeHistro(){
    for(int i=0;i<26;i++)
        cnt[i] = 0;
    int len = int(str.size());
    for(int i=0;i<len;i++)
    {
        if(isalpha(str[i])){
            char c = tolower(str[i]);
            cnt[c-'a']++;
        }
    }
}

int main(){
    Histogram song("People alway call it luck when you've acted more sensibly than tehy have.\n");
    song<<"My"<<"Universe."<<"-bts"; // 히스토그램에 문자열 추가
    song<<'y'<<'s'<<'l'; // 히스토그램에 문자 추가
    !song; //히스토그램 그리기
    return 0;
}
