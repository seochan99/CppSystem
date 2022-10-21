#include <iostream>
#include <cstring>

using namespace std;

class Factory{
private:
    char *name; // 저장 공간 확보가 필요한 동적할당 문자 배열
    int nameLen;
    
public:
    // 모니터 이름을 동적 할당된 문자 배열에 저장
    Factory(){
        cout<<"메모리 할당"<<endl;
    }
    
    Factory(char* name){
        
        cout<<"메모리 할당"<<endl;
        
        // 널문자 삽입을 위한 +1
        nameLen = (unsigned int)strlen(name)+1;
        
        // 동적할당
        this->name = new char(nameLen);
        
        // 문자열 넣기
        strcpy(this->name, name);

    }
    
    // 디폴트 복사 생성자를 사용하였을때 문제 발생
    Factory(const Factory& f){
        
        // 출력해주고 동적할당 해제
        this->name = f.name;
        
        cout<<this->name<<" 1대 생산 !!"<<endl;
        
    }
    
    ~Factory()
    {
        cout<<"메모리 소멸"<<endl;
        delete []name;
    }
};

    

int main(void)
{
    // fac1을 동적할당, SAMSUNG이라는 문자가 동적할당 하여 유지되어야지 fac2에서 복사생성가능하기 때문
    Factory *fac1 = new Factory("SAMSUNG");
    Factory fac2(*fac1);

    
    delete fac1;
    
    
    
    

    
    return 0;
}
