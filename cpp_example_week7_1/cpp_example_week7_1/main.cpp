#include <iostream>
#include <time.h>

using namespace std;

void nojinip(int *t){
    // 진입 전 속도/3000 km/s로 들어간다.
    // int형 t를 float형으로 변환해주자.
    cout<<"선박 속도(항구 진입 전) : "<<(float)*t/3000<<"킬로미터(초)"<<endl;
}

void jinip(int *t){
    // 진입 후 (기존 속도 - 10000) 나누기 3000 km/s로 간다.
    // int형 t를 float형으로 변환해주자.
    cout<<"선박 속도(항구 진입 후) : "<<((float)*t-10000)/3000<<"킬로미터(초)"<<endl;
}


int main(void)
{
    int time = 17000; // 속도
    nojinip(&time); // 진입전
    jinip(&time); // 진입후
    return 0;
}

