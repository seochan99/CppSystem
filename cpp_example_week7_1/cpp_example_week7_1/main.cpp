#include <iostream>
#include <time.h>

using namespace std;

void nojinip(int *t){
    cout<<"선박 속도(항구 진입 전) : "<<(float)*t/3000<<"킬로미터(초)"<<endl;
}

void jinip(int *t)
{
    *t = 7000;
    cout<<"선박 속도(항구 진입 후) : "<<(float)*t/3000<<"킬로미터(초)"<<endl;
}


int main(void)
{
     
    int time = 17000;
    nojinip(&time);
    jinip(&time);
    return 0;
}

