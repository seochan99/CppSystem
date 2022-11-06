#include <iostream>
#define PI 3.141592

using namespace std;

class Measure{
private:
    double rad; // 반지름
    double height; // 높이
    double width; // 너비
    double result;
    double line; // 선 한길이
public:
    // 메뉴 출력
    void static menu();
    
    // 일반 생성자
    Measure(){
    }
    
    // 생성자 원
    Measure(double rad){
        this->rad = rad; //반지름주기
    }
    
    // 생성자 직사각형, 삼각형
    Measure(double height, double width){
        this->height = height;
        this->width = width;
    }
    
    void SetHeight(double height){
        this->height = height;
    }
    
    void SetLine(double line){
        this->line = line;
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
    // 정사각형
    void getEquilateralRectangleArea(){
        cout<<"정사각형 면적은 : "<<line*line<<endl;
    }
    
    // 원뿔
    void getOnebbul(){
        cout<<"원뿔의 부피는 : "<<height*(rad*rad*PI)/3<<endl;
    }
    
    //구의 부피
    void GetCircleV(){
        cout<<"구의 부피는 : "<<(rad*rad*rad*PI)*4/3<<endl;;
    }
    //실린더 부피
    void GetSil(){
        cout<<"실린더의 부피는 : "<< height*(rad*rad*PI)<<endl;
    }
};



int main(){
    int choice=0;
    double radius;
    double width,height;
    double line;
    
    cout<<"면적 및 부피 계산기"<<endl<<endl;
    
    cout<<"1. 원의 면적"<<endl;
    cout<<"2. 직사각형의 면적"<<endl;
    cout<<"3. 삼각형 면적"<<endl;
    cout<<"4. 정사각형 면적"<<endl;
    cout<<"5. 원뿔의 부피"<<endl;
    cout<<"6. 구의 부피"<<endl;
    cout<<"7. 실린더 부피"<<endl<<endl;
    
    // 번호 입력받기
    cout<<"입력 : ";
    cin>>choice;
    
    cout<<endl;
    
    // 입력에 따라서
    // switch에서 변수 생성시 {} 감사야함
    switch (choice) {
        case 1: {//원의 면적
            
            // 반지름 입력받기
            cout<<"원의 반지름 입력 : ";
            cin>>radius;
            cout<<endl;
            
            // 원 동적생성, 반지름 값 1개 필요
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
            
            // 직사각형 동적생성, 높이, 너비 필요
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
            
            // 원 동적생성, 높이 너비 필요
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
            cin>>line;
            cout<<endl;
            
            // 정사각형 동적생성
            Measure *et = new Measure();
            et->SetLine(line);
            et->getEquilateralRectangleArea();
            // 할당해제
            delete et;
            break;
        }
        case 5: //원뿔의 부피 : 밑면의 넓이 * 높이 / 3
        {
            cout<<"원뿔의 반지름, 높이 입력 : ";
            cin>>radius>>height;
            cout<<endl;
            
            // 원 동적생성
            Measure *op = new Measure(radius);
            op->SetHeight(height);
            
            op->getOnebbul();
            // 할당해제
            delete op;
            break;
    }
        case 6:
        {
            //구의 부피 : 4/3 * 파이 * 반지름세제곱
                cout<<"구의 반지름 : ";
                cin>>radius;
                cout<<endl;
                
                // 원 동적생성
                Measure *cv = new Measure(radius);
                cv->GetCircleV();
                // 할당해제
                delete cv;
                break;
        }
        case 7: //실린더 부피 : 밑면의 널빙 * 높이
        {
            cout<<"실린더의 반지름, 높이 입력 : ";
            cin>>radius>>height;
            cout<<endl;
            
            // 원 동적생성
            Measure *sil = new Measure(radius);
            sil->SetHeight(height);
            
            sil->GetSil();
            // 할당해제
            delete sil;
            break;
        }
    }
    
    return 0;
}
