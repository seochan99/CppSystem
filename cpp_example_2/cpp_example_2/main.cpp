#include <iostream>

using namespace std;

int main(void)
{
    
    // 배열 선언
    int arr[10];
    int temp=0;
    
    // 배열 입력받기
    cout<<"데이터 출력 : ";
    for(int i=0;i<10;i++)
    {
        cin>>arr[i];
    }
        
    
    // 정렬 진행되기 전 데이터 출력
//    cout<<"데이터 출력 :";
//    for(int i=0;i<10;i++)
//    {
//        cout<<arr[i]<<" ";
//
//    }
    
    // 배열 오름차순 : 앞의 값이 뒤의 값보다 크면 교환하여 앞에 값을 뒤로 이동
    // 이때 값 이동을 위한 임시 저장소가 필요함 -> temp 변수 생성
    for(int i=0;i<9;i++){
          for(int j=i+1;j<10;j++){
              if(arr[i]>arr[j]){
                  temp=arr[i];
                  arr[i]=arr[j];
                  arr[j]=temp;
              }
          }
      }
    
    // 정렬된 배열 출력
    cout<<"오름차순 정렬 :";
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<" ";
    
    }
    return 0;
}
