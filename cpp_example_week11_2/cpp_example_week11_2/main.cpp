#include <iostream>

using namespace std;

class Distance {
private:
  // 생성자 생성 개수
  static int cnt;
  // key값 거리, 인치 변수
  int key = 0;
  int feet = 0;
  int inch = 0;

public:
  // 생성자
  Distance() {
    // key값에 cnt넣기
    this->key = cnt++;
  };
  // 생성자, 거리,인치받기
  Distance(int feet, int inch) {
    this->key = cnt++;
    this->feet = feet;
    this->inch = inch;
  };
  // 연산자 중복 friends로 클래스 외부에서 구현하기
  friend Distance operator+(Distance d1, Distance d2);

  // feet 설정
  void getInfo() {
    cout << "d" << this->key << ".feet : " << this->feet;
    cout << ", d" << this->key << ".inch : " << this->inch << endl;
  }
  // 거리가져오기
  int getFeet() { return this->feet; }
  // 인치가져오기
  int getInch() { return this->inch; }
};
// 생성된 객체 개수를 세기 위한 cnt
int Distance::cnt = 1;

// 연산자 중복
Distance operator+(Distance d1, Distance d2) {
  // dis객체 생성
  Distance dis;
  // 거리 더하기
  dis.feet = d1.feet + d2.feet;
  // 인치 더하기
  dis.inch = d1.inch + d2.inch;
  return dis;
}

int main(void) {
  // d1~r2 객체 생성
  Distance d1(20, 40), d2(46, 51), d3(254, 450), d4(126, 244), r1(0, 0),
      r2(0, 0);

  // d1,d2정보 가져오기
  d1.getInfo();
  d2.getInfo();

  // 연산자 중복 => 객체 덧셈
  r1 = d1 + d2;

  // 결과값 출력
  cout << "두 개(d1, d2)의 거리의 합 : " << r1.getFeet() << " feet,  "
       << r1.getInch() << " inch" << endl
       << endl;

  // d3,d4정보 가져오기
  d3.getInfo();
  d4.getInfo();

  // 연산자 중복 => 객체 덧셈
  r2 = d3 + d4;

  // 결과값 출력
  cout << "두 개(d3, d4)의 거리의 합 : " << r2.getFeet() << " feet, "
       << r2.getInch() << " inch" << endl
       << endl;

  return 0;
}
