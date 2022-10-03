#include "Student.hpp"

void Student::SetNum(int n){
    num = n;
}

void Student::SetName(string n){
    name = n;
}

void Student::SetScore(int s){
    score = s;
}

void Student::GetStudentInfo(){
    cout<<"이름 : "<<name<<endl;
    cout<<"학번 : "<<num<<endl;
    cout<<"전체 : "<<score<<endl;
    cout<<"점수 환산(%) : "<<(double)score/2<<endl;
}
