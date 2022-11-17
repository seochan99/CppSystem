#include <iostream>

using namespace std;

class Box{
private:
    // 맴버 변수 선언 
    int width;
    int vertical;
    int height;
public:
    // 박스 생성자
    Box(int width, int vertical, int height)
    {
        this->width = width;
        this->vertical = vertical;
        this->height = height;
    }
    // 연산자 중복 + 사용하기
    Box operator+(int k){
        width = this->width + k;
        vertical = this->vertical + k;
        height = this->height + k;
        return *this;
    }
    // 박스부피 계산
    int calBoxSize(){
        return this->width * this->height * this->vertical;
    }
    // 가로 가져오기
    int getWidth(){
        return this->width;
    }
    // 높이 가져오기
    int getHeight(){
        return this->height;
    }
    // 세로 가져오기
    int getVertical(){
        return this->vertical;
    }
    
};

int main(int argc, const char * argv[]) {
    // box1, box2 생성
    Box b1(3,3,20),b2(13,10,12);
    
    // box3는 1,2의 크기 합 을 구한채 생성
    Box b3(b1.getWidth()+b2.getWidth(),b1.getVertical()+b2.getVertical(),b1.getHeight()+b2.getHeight());
    
    // 단일 연산자 중복
    // 가로 세로 높이 1cm씩 크게 만들어주기
    b1.operator+(1);
    b2.operator+(1);
    
    // 부피 계산결과 출력
    cout<<"Box1 부피는 : "<<b1.calBoxSize()<<"cm3"<<endl;
    cout<<"Box2 부피는 : "<<b2.calBoxSize()<<"cm3"<<endl;
    cout<<"Box3 부피는 : "<<b3.calBoxSize()<<"cm3"<<endl;
    
    return 0;
}
