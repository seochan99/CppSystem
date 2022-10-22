#include <iostream>
#include <cstdlib>
#include <algorithm>

#define NUM 7 //숫자 7개

using namespace std;

// 처음 숫자 내용 출력함수
void FirstPrintArr(int (&name)[]){
    for(int i=0;i<NUM;i++)
    {
        cout<<name[i];
    }
    cout<<endl;
    
}

// 0제거, 역순출력
void SecondPrintArr(int (&name)[]){
    // 역순으로 출력
    
    // 배열 첫번째 요소가 0이면 flag는 true, 아니면 false
    bool flag = name[0]==0 ? true : false;
    
    // 0을 제거한 배열 길이 카운팅을 위한 변수 cnt
    int cnt=0;
    
    // 0제거된 배열 저장, 배열 최대 크기 NUM
    int deleteZeroArr[NUM];
    
    // 0제거 숫자 넣는 알고리즘
    for(int i=0;i<NUM;i++)
    {
        // name[i]가 0이고 flag가 true이면 continue
        // 만약 name문자 배열이 00123이라면
        // i가 0일때 name[0] = 0이고, flag는 true 이므로 continue
        // i가 1일때 name[1] = 0이고, flag는 true 이므로 continue
        // i가 2일때 name[2] = 1이므로 아래 else 실행, flag = false됨
        // flag가 true로 바뀔일은 이제 없으므로 이후부터 아래 else문 계속 실행
        if(name[i]==0&&flag==true){
            continue;
        }
        // 그 외.. 즉, 0이랑 true가 아니라면
        else{
            // flag는 false == 이제 0이 안이어짐
            flag=false;
            
            // deleteZeroArr에 현재 값 저장
            deleteZeroArr[cnt] = name[i];
            
            // 0을 제거한 배열 길이 수 올려주기
            cnt++;
        }
    }
    
    // 역순으로 출력
    // cnt는 앞에 0제거 후의 카운팅
    // 그러므로 cnt-1부터 시작하면 0은 출력안함.
    // 예를들어 00123456이 0이 제거되어 아래와 같이
    // deleteZeroarr[NUM]에 {1,2,3,4,5,6,0,0}이 저장됨 (배열에 값을 안채워준 값은 0이 들어감)
    // 그러면 cnt는 6임
    // 그러므로 deleteZeroArr[5]부터 0까지 출력
    for(int i=cnt-1;i>=0;i--)
    {
        cout<<deleteZeroArr[i];
    }
    cout<<endl;
    
    
}

int main(void)
{
    
    // 숫자 7개 배열 생성
    int minsu[NUM];
    int chulsu[NUM];
    
    // 난수 시드주기
    srand((unsigned int)time(NULL));
    
    //
    for(int i = 0;i<NUM;i++)
    {
        minsu[i] = rand()%10; // 0~9
        chulsu[i] = rand()%10; // 0~9
    }
    
    // 민수, 철수 초기 숫자 출력
    cout<<"민수의 숫자 = ";
    FirstPrintArr(minsu);
    
    cout<<"철수의 숫자 = ";
    FirstPrintArr(chulsu);
    
    // 값 교환 Alogrithm Library의 swap을 통해 진행
    swap(minsu, chulsu);
    
    cout<<endl;

    // 0제거, 역순 출력진행
    cout<<"민수의 숫자 = ";
    SecondPrintArr(minsu);
    
    cout<<"철수의 숫자 = ";
    SecondPrintArr(chulsu);
    
    return 0;
}
