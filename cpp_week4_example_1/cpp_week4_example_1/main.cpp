#include "Time.hpp"

int main() {
    
    // 변수설정
  int hour, min, sec;
    
    // 객체 생성
  Time t1;
    
  cout << "시간을 입력해주세요 : " << endl;

  cout << "몇 시?";
  cin >> hour;
  t1.SetHour(hour);

  cout << "몇 분?";
  cin >> min;
  t1.SetMin(min);

  cout << "몇 초?";
  cin >> sec;
  t1.SetSec(sec);

  t1.GetTime();
  cout << "시간을 초로 변환 = " << t1.TimeToSec() << endl;
}
