#include <iostream>
#include <string>
#include <cmath>

// 원주율, 경계선 설정
#define PI 3.141592
#define BOUND 765

// 부피 : 4/3 pi r^3
using namespace std;


// 구 클래스
class Sphere{
private:
    // 반지름
    int radius;
public:
    // 생성자
    Sphere(){
        cout<<"구 객체 생성";
    }
    // 구 반지름 this를 통해 설정
    void SetRadius(int radius){
        this->radius = radius;
    }
    // 구 반지름 가져오기
    int GetRadius(){
        return radius;
    }
    // 소멸자
    ~Sphere(){
        cout<<"구 객체 소멸";
    }
    
};

int main(void)
{
    // 객체포인터 생성
    Sphere *sp[5];
    
    int r;
    int cnt =0;
    
    // 동적할당 진행
    for(int i=0;i<5;i++)
    {
        sp[i] = new Sphere();
        cout<<i+1<<endl;
    }
    
    cout<<endl;
    
    // 구 반지름 입력 받기
    for(int i=0;i<5;i++)
    {
        cout<<"구 "<<i+1<<"의 반지름 >> ";
        cin>>r;
        sp[i]->SetRadius(r);
        
        // 구의 부피가 BOUND보다 크다면 cnt++
        if(4/3*PI*pow(sp[i]->GetRadius(), 3) > BOUND)
            cnt++;
    }
    
    cout<<endl;
    
    // 결과 출력
    cout<<"구의 부피가 765cm3 이상인 큰 구는 "<<cnt<<"개 입니다."<<endl;
    cout<<"구의 부피가 765cm3 이하인 작은 구는 "<<5-cnt<<"개 입니다."<<endl;
    
    
    cout<<endl;
    
    // 객체 할당 해제
    for(int i=4;i>=0;i--)
    {
        delete sp[i];
        cout<<i+1<<endl;
    }
    
    return 0;
}
