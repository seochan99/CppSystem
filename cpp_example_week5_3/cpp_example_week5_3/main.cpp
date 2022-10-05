#include <iostream>

using namespace std;

class Books{
private:
    string name;
    int price;
public:
    Books(){}
    // 책정보 입력받기
    void SetBook(){
        cout<<"제목 : ";
        cin>>name;
        cout<<"가격 : ";
        cin>>price;
    }
    
    // 책 출력
    void GetBook(){
        cout<<"제목 : "<<name<<endl;
        cout<<"가격 : "<<price<<endl;
    }
    // 소멸자
    ~Books(){}
    
};

int main(void){
    Books *book[3];

    for(int i=0;i<3;i++){
        cout<<"책 "<<i+1<<"번 제목 및 가격 입력"<<endl;
        // 책 동적할당
        book[i] = new Books();
        book[i]->SetBook();
    }
    
    cout<<endl;
    
    for(int i=0;i<3;i++){
        cout<<"책 "<<i+1<<endl;
        book[i]->GetBook();
    }
    
    for(int i=0;i<3;i++){
        delete book[i];
    }
    
    
    return 0;
}
