#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char *name;
    int age;
public:
    // 생성자
    Person(char *myname,int myage):age(myage)
    {
        name = new char[strlen(myname)+1];
        strcpy(name, myname);
    }
    
    // 배열 생성시 필요한 생성자
    Person()
    {
        name = NULL;
        age = 0;
        cout<<"called Person()"<<endl;
    }
    
    //원하는 데이터로의 초기화를 목적으로 정의된 함수
    void SetPersonInfo(char * myName, int myAge)
    {
        name = myName;
        age = myAge;
    }
    
    void ShowPersonInfo() const
    {
        cout<<"Name : "<<name<<endl;
        cout<<"Age : "<<age<<endl;
    }
    ~Person()
    {
        delete []name;
        cout<<"called Destructor!"<<endl;
    }
};

//int main(void)
//{
//    // 배열 생성 시 Person(void) 호출
//    Person parr[3];
//
//    
//    char nameStr[100];
//    char * strPtr;
//    int age;
//    
//    for(int i=0;i<3;i++)
//    {
//        cout<<"Name : ";
//        cin>>nameStr;
//        
//        cout<<"Age : ";
//        cin>>age;
//        
//        strPtr = new char[strlen(nameStr)+1];
//        strcpy(strPtr, nameStr);
//        
//        parr[i].SetPersonInfo(strPtr, age);
//    }
//    
//    parr[0].ShowPersonInfo();
//    parr[1].ShowPersonInfo();
//    parr[2].ShowPersonInfo();
//    return 0;
//    
//}
