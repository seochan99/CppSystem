
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
    hourString = hour < 10 ? "0" + to_string(hour) : to_string(hour);

    // 분 10이하인지 체크
    minString = min < 10 ? "0" + to_string(min) : to_string(min);

    // 초 10이하인지 체크
    secString = sec < 10 ? "0" + to_string(sec) : to_string(sec);

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
