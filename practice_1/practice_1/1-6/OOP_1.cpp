#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

// 계좌개설
// 입금
// 출금
// 전체 출력
// 프로그램 종료
// -> 반복문 -> 메뉴판
// 고객정보 배열 저장

void ShowMenu(void); //메뉴 출력
void MakeAccount(void); // 계좌 개설
void DepositMoney(void); // 입금
void WithdrawMoney(void); // 출금
void ShowAllAccInfo(void); // 잔액 조회

// 열거형
// 만들기 = 1, 입금, 출금, 조회, 나가기
enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct
{
    int accID; // 계좌번호
    int balance; // 잔액
    char cusName[NAME_LEN]; // 고객이름
}Account;

Account accArr[100]; // Account 저장을 위한 배열
int accNum = 0; // 저장된 Account 수

// main
int main(void){
    int choice;
    
    while (1) {
        ShowMenu(); // 메뉴 출력
        cout<<"선택 : ";
        cin>>choice;
        cout<<endl;
        
        switch (choice) {
            case MAKE:
                MakeAccount();
                break;
            case DEPOSIT:
                DepositMoney();
                break;
            case WITHDRAW:
                WithdrawMoney();
                break;
            case INQUIRE:
                ShowAllAccInfo();
                break;
            case EXIT:
                return 0;
            default:
                cout<<"1~5의 숫자를 입력해주세요."<<endl;
        }
    }
    return 0;
}

// 메뉴 출력

void ShowMenu(void)
{
    cout<<"---- 메뉴 ----"<<endl;
    cout<<"1. 계좌개설"<<endl;
    cout<<"2. 입금"<<endl;
    cout<<"3. 출금"<<endl;
    cout<<"4. 계좌정보 전체 출력"<<endl;
    cout<<"5. 종료"<<endl;
}

// 계좌 개설하기
void MakeAccount(void){
    int id;
    char name[NAME_LEN];
    int balance;
    
    cout<<"[계좌개설]"<<endl;
    cout<<"계좌 ID : ";cin>>id;
    cout<<"이 름 : ";cin>>name;
    cout<<"입금액 : ";cin>>balance;
    cout<<endl;
    
    accArr[accNum].accID = id; //0번째에 ID 저장
    accArr[accNum].balance = balance;
    strcpy(accArr[accNum].cusName, name); //이름 넣기
    accNum++; // 고객 숫자 증가시키기
}

void DepositMoney(void)
{
    int money;
    int id;
    cout<<"[입 금]"<<endl;
    cout<<"계좌 ID : "; cin>>id;
    cout<<"입금액 : "; cin>>money;
    
    // 반복문 돌기
    for(int i=0;i<accNum;i++){
        // 만약 계좌번호와 입력한 id가 같다면
        // 잔액증가시키고 return
        if(accArr[i].accID == id){
            accArr[i].balance += money;
            cout<<"입금완료\n\n";
            return;;
        }
    }
}

// 출금
void WithdrawMoney(void)
{
    int money;
    int id;
    cout<<"[출 금]"<<endl;
    cout<<"계좌 ID : "; cin>>id;
    cout<<"출금액 : "; cin>>money;
    
    // 반복문 돌기
    for(int i=0;i<accNum;i++){
        // 만약 계좌번호와 입력한 id가 같다면
        // 잔액감소시키고 return
        if(accArr[i].accID == id){
            //잔액이 부족하면
            if(accArr[i].balance < money)
            {
                cout<<"잔액부족\n\n";
                return;
            }
            
            accArr[i].balance -= money;
            cout<<"출금완료\n\n";
            return;;
        }
    }
}

// 모든 계좌 정보 출력
void ShowAllAccInfo(void)
{
    for(int i=0;i<accNum;i++)
    {
        cout<<"계좌 ID : "<<accArr[i].accID<<endl;
        cout<<"이 름 : "<<accArr[i].cusName<<endl;
        cout<<"잔 액 : "<<accArr[i].balance<<endl;
    }
}
