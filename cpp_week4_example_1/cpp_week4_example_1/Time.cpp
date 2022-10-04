
#include "Time.hpp"

// 셋팅메서드
void Time::SetHour(int h) { hour = h; }
void Time::SetMin(int m) { min = m; }
void Time::SetSec(int s) { sec = s; }

// 시간출력
void Time::GetTime() {

  // 시분초 문자열 변수 생성
  string hourString;
  string minString;
  string secString;

  // 시 10이하인지 체크
  if (hour < 10)
    hourString = "0" + to_string(hour);
  else
    hourString = to_string(hour);

  // 분 10이하인지 체크
  if (min < 10)
    minString = "0" + to_string(min);
  else
    minString = to_string(min);

  // 초 10이하인지 체크
  if (sec < 10)
    secString = "0" + to_string(sec);
  else
    secString = to_string(sec);

  // 출력
  cout << "입력한 시간 = " << hourString << ":" << minString << ":" << secString
       << endl;
}

// 시간을 초로
int Time::TimeToSec() {
  int result = 0;
  // 시는 3600, 분은 60, 초는 그대로
  result = hour * 3600;
  result += min * 60;
  result += sec;
  return result;
}
