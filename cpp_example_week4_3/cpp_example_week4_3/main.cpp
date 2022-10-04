#include "Student.hpp"

int main(void)
{
    int studentNum;
    string studentName;
    int studentCode;
    int studentScore;
    
    // 학생정보 입력받기
    cout<<"몇 명의 학생 정보를 입력할까요? : ";
    cin>>studentNum;
    
    // 학생 객체 생성, studentNum만큼
    Student stu[studentNum];
    cout<<endl;
    
    // 반복문 돌기
    for(int i=0;i<studentNum;i++){
        
        cout<<i+1<<"번째 학생 정보를 입력하세요."<<endl;
        
        // 이름, 학번, 점수 입력받기
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
    
    // 전체 학생 정보출력 
    cout<<"[전체 학생 정보 출력]\n"<<endl;
    for(int i=0;i<studentNum;i++){
        cout<<i+1<<"번째 학생 정보를 출력합니다."<<endl;
        stu[i].GetStudentInfo();
        cout<<endl;
    }
    
    
    return 0;
}
