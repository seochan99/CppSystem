#ifndef Student_hpp
#define Student_hpp

#include <string>
#include <iostream>

using namespace std;

// Student 객체 생성
class Student{
private:
    string name;
    int num;
    int score;
public:
    void SetName(string n);
    void SetNum(int n);
    void SetScore(int s);
    void GetStudentInfo();
};


#endif /* Student_hpp */
