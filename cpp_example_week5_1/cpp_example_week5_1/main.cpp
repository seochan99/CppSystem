#include <iostream>

using namespace std;

class TestResult{
private:
    int myS;
    int myN;
    string myName;
public:
    TestResult():myS(0),myN(0),myName("none"){}
    TestResult(int s, int n, string name){
        myS = s;
        myN = n;
        myName = name;
    }
    void printAll();
};



void TestResult::printAll(){
    cout << myN << '\n';
     cout << myName << '\n';
     cout << myS << '\n';
}


int main(void){
    
    int num,score;
    string name;
    TestResult *student[3];
    
    for(int i=0;i<3;i++)
    {
        cout << "학번 : ";
        cin >> num;
        cout << "이름 : ";
        cin >> name;
        cout << "점수 : ";
         cin >> score;
        // 동적할당
        student[i] = new TestResult(score,num,name);
    }
    
    student[0]->printAll();
    student[1]->printAll();
    student[2]->printAll();
}
