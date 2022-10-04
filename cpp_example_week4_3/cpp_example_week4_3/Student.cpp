#include "Student.hpp"

// 학번설정
void Student::SetNum(int n){
    num = n;
}

// 이름설정
void Student::SetName(string n){
    name = n;
}

// 점수 설정
void Student::SetScore(int s){
    score = s;
}

// 전체 출력
void Student::GetStudentInfo(){
    cout<<"이름 : "<<name<<endl;
    cout<<"학번 : "<<num<<endl;
    cout<<"전체 : "<<score<<endl;
    cout<<"점수 환산(%) : "<<(double)score/2<<endl;
}
