#include <iostream>

using namespace std;

int main(void)
{
    // 변수선언
    char op;
    int num1, num2;
    
    // 무한루프
    while(1)
    {
        cout<<"^ ";
        cin>>num1>>op>>num2;
        
        // operator 에 따른 조건문
        if(op == '+')
            cout<<num1<<" "<<op<<" "<<num2<<" = "<<num1+num2<<endl;
        else if(op == '-')
            cout<<num1<<" "<<op<<" "<<num2<<" = "<<num1-num2<<endl;
        else if(op == '*')
            cout<<num1<<" "<<op<<" "<<num2<<" = "<<num1*num2<<endl;
        else if(op == '/')
            cout<<num1<<" "<<op<<" "<<num2<<" = "<<num1/num2<<endl;
        else if(op == '%')
            cout<<num1<<" "<<op<<" "<<num2<<" = "<<num1%num2<<endl;
    }
    
    return 0;
}
