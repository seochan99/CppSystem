#ifndef Time_hpp
#define Time_hpp

#include <iostream>
#include <string>

using namespace std;



class Time {
private:
  int hour;
  int min;
  int sec;

public:
  void SetHour(int h); //시 설정
  void SetMin(int m); // 분 설정
  void SetSec(int s); // 초 설정
  void GetTime(); // 시간 출력
  int TimeToSec(); // 시간을 초로
};


#endif /* Time_hpp */
