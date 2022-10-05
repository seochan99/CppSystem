#include <iostream>

using namespace std;


int main(void){
    int num;
    
    // 정수입력받기 
    cout<<"정수를 얼마나 입력 받을까요? : ";
    cin>>num;

    //배열 동적할당
    int *arr = new int[num];
    
    // 입력 받기
    for(int i=0;i<num;i++){
        cout<<"정수 입력 : ";
        cin>>arr[i];
    }
    
    cout<<"정수 출력 : ";
    //반복문으로 배열 출력하기
    for(int i=0;i<num;i++){
        // 마지막 , 안찍히게
        if(i==num-1)
            cout<<arr[i]<<endl;
        else
            cout<<arr[i]<<", ";
    }
    //해제
    delete [] arr;
    return 0;

}
