#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string name;
    int studentNumber;
    int date;
    string introduce;
    
    
    
    // 입력
    getline(cin,name);
    cin>>studentNumber;
    cin>>date;
    
    // cin 은 \n을 처리하지 않고 버퍼에 남겨둠
    // 그래서 cin.ingonre을 안하면 getline에서 \n을 가져와서 처리함.
    // 그러므로 cin.ingnore()을 통해 맨 앞의 문자 하나를 지움으로서 \n을 날림.
    cin.ignore();
    getline(cin,introduce);
    
    //for문 이용, 10번 출력
    for(int i=0;i<10;i++)
    {
        cout<<name<<studentNumber<<date<<introduce<<endl;
    }
    return 0;
}
