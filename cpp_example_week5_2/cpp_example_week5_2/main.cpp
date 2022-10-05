#include <iostream>

using namespace std;


class Student{
private:
    string name;
    int code;
    string status;
public:
    // 생성자
    Student(string n,int c):name(n),code(c){
        cout<<name<<" 출석 체크를 시작합니다."<<endl;
    }
    
    
    // 출결체크 method
    void CheckStudent(){
        cout<<"이름 : "<<name<<endl;
        cout<<"학번 : "<<code<<endl;
        cout<<"출결(출석, 지각, 결석) : ";
        cin>>status;
        cout<<endl;
    }
    
    
    
    // 소멸자
    ~Student(){
        cout<<name<<" 출석 체크가 완료되었습니다."<<endl;
    }
    
};

int main(void){
    Student *stu[3];
    string stat;
    
    // 동적 할당
    stu[0] = new Student("김철수",2022654321);
    stu[1] = new Student("이유리",2019112221);
    stu[2] = new Student("이훈이",2015200221);
    
    // 출석 체크
    cout<<"\n-----------------------\n"<<endl;
    stu[0]->CheckStudent();
    stu[1]->CheckStudent();
    stu[2]->CheckStudent();
    cout<<"-----------------------"<<endl;
    
    for(int i=0;i<3;i++){
        delete stu[i];
    }
    
    
    return 0;
}
