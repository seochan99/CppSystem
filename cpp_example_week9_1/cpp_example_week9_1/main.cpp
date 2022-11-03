#include <iostream>
#include <cmath> // sqrt, pow
#define PI 3.141592

using namespace std;

class Measure{
private:
    double rad; // 반지름
    double height; // 높이
    double width; // 너비
    double result;
    double line;
public:
    // 메뉴 출력
    void static menu();
    
    // 생성자 원, 정사각형
    Measure(double rad){
        this->rad = rad; //반지름주기
    }
    
    // 생성자 원뿔, 직사각형, 삼각형
    Measure(double radius=0, double height=0, double width=0){
        this->radius = radius;
        this->height = height;
        this->width = width;
    }
    
    
    
    // 원 면적
    void getCircleArea(){
        cout<<"원의 면적은 : "<<rad*rad*PI<<endl;
    }
    
    // 직삼각형 면적
    void getRectangleArea(){
        cout<<"직삼각형의 면적은 : "<<width*height<<endl;
    }
    
    // 삼각형 면적
    void getTriangleArea(){
        cout<<"삼각형의 면적은 : "<<width*height/2<<endl;
    }
    
    void getEquilateralRectangleArea(){
        cout<<"정삼각형 면적은 : "<<rad*rad<<endl;
    }
    
    void getOnebbul(){
        cout<<"원뿔의 부피는 : "<<height
    }
    
};



int main(){
    int choice=0;
    double radius;
    double width,height;
    
    // 번호 입력받기
    cout<<"입력 : ";
    cin>>choice;
    
    cout<<endl;
    
    // 입력에 따라서
    // switch에서 변수 생성시 {} 감사야함
    switch (choice) {
        case 1: {//원의 면적
            
            // 반지름 입력받기
            cout<<"반지름 입력 : ";
            cin>>radius;
            cout<<endl;
            
            // 원 동적생성
            Measure *c = new Measure(radius);
            c->getCircleArea();
            
            // 할당해제
            delete c;
            break;
        }
        case 2: {//직사각형 면적
            // 높이, 너비
            cout<<"직사각형의 높이, 너비 입력 : ";
            cin>>height>>width;
            cout<<endl;
            
            // 직사각형 동적생성
            Measure *r = new Measure(height,width);
            r->getRectangleArea();
            
            // 할당해제
            delete r;
            break;
        }
        case 3: {
            //삼각형 면적
            // 높이, 너비
            cout<<"삼각형의 높이, 너비 입력 : ";
            cin>>height>>width;
            cout<<endl;
            
            // 원 동적생성
            Measure *t = new Measure(height,width);
            t->getTriangleArea();
            
            // 할당해제
            delete t;
            
            break;
        }
        case 4:
        {
            // 정사각형 면적
            cout<<"정사각형 한 변의 길이 입력 : ";
            cin>>radius;
            cout<<endl;
            
            // 원 동적생성
            Measure *et = new Measure(radius);
            et->getEquilateralRectangleArea();
            // 할당해제
            delete et;
            break;
    }
        case 5: //원뿔의 부피 : 밑면의 넓이 * 높이 / 3
            cout<<"반지름, 높이 입력 : ";
            cin>>radius>>height;
            cout<<endl;
            
            // 원 동적생성
            Measure *c = new Measure(radius,height);
            et->getEquilateralRectangleArea();
            // 할당해제
            delete et;
            break;
            break;
            
        case 6: //구의 부피 : 4/3 * 파이 * 반지름세제곱
            
            break;
        case 7: //실린더 부피 : 밑면의 널빙 * 높이
            
            break;
    }
    
    // 반지름 입력
    
    // 높이 입력
    
    return 0;
}
