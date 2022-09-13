#include <iostream>
// sort()를 위해 알고리즘 라이브러리 가져오기
#include <algorithm>

using namespace std;

// Number 클래스 생성
class Number {
public:
  // 값을 입력받기 위해 num을 public으로 선언함
  int num;
    
    //두 객체를 비교하려는것이지 상태를 변화시킬려는 것이아니기에 const 필수
  bool operator<(const Number &arr) const{
      // 들어온 숫자가 배열의 숫자보다 클때 true반환
    if (this->num < arr.num)
        return true;
      
      return false;
  }
};

int main(void) {
  // 객체 생성
  Number arr[10];
    arr[0].num = 1; arr[1].num = 56; arr[2].num = 15; arr[3].num = 99; arr[4].num = 65;
    arr[5].num = 33; arr[6].num = 21; arr[7].num = 47; arr[8].num = 72; arr[9].num = 5;

  // 객체 num 데이터 출력
  cout << "데이터 출력 : ";
  for (int i = 0; i < 10; i++) {
      cout<<arr[i].num<<" ";
  }
    cout<<endl;
  // 오름차순 : 앞의 값이 뒤의 값보다 크면 교환하여 앞에 값을 뒤로 이동
  // sort를 활용한 오름차순
  sort(arr, arr + 10);

  // 정렬된 배열 출력
  cout << "오름차순 정렬 :";
  //반복문
  for (int i = 0; i < 10; i++) {
    cout << arr[i].num << " ";
  }
  return 0;
}
