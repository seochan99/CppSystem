#include "Student.hpp"

int main(void)
{
    int studentNum;
    string studentName;
    int studentCode;
    int studentScore;
    
    cout<<"몇 명의 학생 정보를 입력할까요? : ";
    cin>>studentNum;
    Student stu[studentNum];
    cout<<endl;
    
    for(int i=0;i<studentNum;i++){
        
        cout<<i+1<<"번째 학생 정보를 입력하세요."<<endl;
        
        cout<<"이름 : ";
        cin>>studentName;
        stu[i].SetName(studentName);
        
        cout<<"학번 : ";
        cin>>studentCode;
        stu[i].SetNum(studentCode);
        
        cout<<"전체 점수(0~200) : ";
        cin>>studentScore;
        stu[i].SetScore(studentScore);
        cout<<endl;
    }
    
    cout<<"[전체 학생 정보 출력]\n"<<endl;
    for(int i=0;i<studentNum;i++){
        cout<<i+1<<"번째 학생 정보를 출력합니다."<<endl;
        stu[i].GetStudentInfo();
        cout<<endl;
    }
    
    
    return 0;
}
