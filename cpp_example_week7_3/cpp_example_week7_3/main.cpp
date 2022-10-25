#include <iostream>
#include <cstring>

using namespace std;

class Factory{
private:
    char *name; // 저장 공간 확보가 필요한 동적할당 문자 배열
public:
    Factory(const char* name); // 생성자
    Factory(const Factory& f); // 복사생성자
    void getName();
    ~Factory(); // 소멸자
};
void Factory::getName(){
    cout<<"FactoryName is :"<<this->name<<endl;
}

// 생성자
Factory::Factory(const char* name){
    
    // 생성자
    int len = (unsigned int)strlen(name); // name길이
    this->name = new char[len+1]; // \0까지 고려해서 name문자열 공간 할당
    strcpy(this->name, name); // name에 문자열 복사
    cout<<"메모리 할당"<<endl;
}

//// 복사생성자
//Factory::Factory(const Factory& f){
//
//    int len = (unsigned int)strlen(f.name); // name의 문자개수
//    this->name = new char[len+1]; // name을 위한 공간 할당해주기
//    strcpy(this->name, f.name); // this->name에 f.name 문자열 복사
//    cout<<this->name<<" 1대 생산"<<endl;
//}

Factory::Factory(const Factory& f){
    int len =(unsigned int)strlen(f.name);
    // 동적할당
    this->name = new char[len];
    strcpy(this->name, f.name);
    cout<<this->name<<" 1대 생산"<<endl;

}
// 소멸자
Factory::~Factory(){
    cout<<"메모리 소멸"<<endl;
    
    // name이 동적할당되어있다면
    if(name)
        delete []name; // 할당해제 진행
}

int main(void)
{
    // Factory, "SAMSUNG" 주기
    Factory fac1 = Factory("SAMSUNG");
    Factory fac2(fac1);
    Factory fac3 = Factory("chan");
    Factory fac4(fac3);
    
    // 객체 포인터 활용
    Factory *f;
    f = &fac3;
    f->getName();
    
    
    return 0;
}
