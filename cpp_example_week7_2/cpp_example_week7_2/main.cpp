#include <iostream>
#include <cstdlib>
#include <algorithm>

#define NUM 7

using namespace std;


void FirstPrintArr(int (&name)[]){
    for(int i=0;i<NUM;i++)
    {
        cout<<name[i];
    }
    cout<<endl;
    
}

void SecondPrintArr(int (&name)[]){
    // 역순으로 출력
    
    //int reverseArr[];
    
    // 첫번째가 0이면 true
    bool flag = name[0]==0 ? true : false;
    int cnt=0;
    
    // 0제거된 배열 저장
    int deleteZeroArr[7];
    
    // 0제거 알고리즘
    for(int i=0;i<NUM;i++)
    {
        
        // 0이고 flag가 true이면 출력안하고 continue
        if(name[i]==0&&flag==true){
            continue;
        }
        // 그 외.. 즉, 0이랑 true가 아니라면
        else{
            // flag는 false == 이제 0이 안이어짐
            flag=false;
            // deleteZeroArr에 현재 값 저장
            deleteZeroArr[cnt] = name[i];
            cnt++;
        }
    }
    
    // 역순으로 출력
    // cnt는 앞에 0제거 후의 카운팅
    // 그러므로 cnt-1부터 시작하면 0은 출력안함.
    for(int i=cnt-1;i>=0;i--)
    {
        cout<<deleteZeroArr[i];
    }
    cout<<endl;
    
    
}

int main(void)
{
    
    // 숫자 7개
    int minsu[NUM];
    int chulsu[NUM];
    
    // 난수 시드주기
    srand((unsigned int)time(NULL));
    
    for(int i = 0;i<NUM;i++)
    {
        // 매 순간 숫자다르게

        // 0~9
        minsu[i] = rand()%10;
        chulsu[i] = rand()%10;
    }
    
    cout<<"민수의 숫자 = ";
    FirstPrintArr(minsu);
    
    cout<<"철수의 숫자 = ";
    FirstPrintArr(chulsu);
    
    // 값 교환
    swap(minsu, chulsu);
    
    cout<<endl;

    cout<<"민수의 숫자 = ";
    SecondPrintArr(minsu);
    
    cout<<"철수의 숫자 = ";
    SecondPrintArr(chulsu);
    
    return 0;
}
