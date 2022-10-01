#include <iostream>

// 치킨 가격 만원 상수 선언
#define PRICE 10000

// 치킨 개수 상수 선언
#define CHICKENSELLNUM 60

using namespace std;

// 치킨집 사장님
class ChickenSeller{
private:
    int chicken;
    int money;
    int buyChicken;
    int ballance;
    
public:
    ChickenSeller();
    void SellChicken(int);
    void GetInfoSeller();
};

// 치킨집 사장님 초기화, 치킨 : 60, 돈 : 0원, 구매자 치킨 : 0, 돈 : 10만원 초기화
ChickenSeller::ChickenSeller():chicken(CHICKENSELLNUM),money(0),buyChicken(0),ballance(100000){}


// 치킨 판매
void ChickenSeller::SellChicken(int ch){
    
    // 돈과 치킨이 충분할때 거래 성립
    if (ballance>=(PRICE*ch) && chicken>=ch){
        // 치킨 1개 빼주기
        chicken -= ch;
        // 돈 올려주기, 치킨 1마리 10,000원
        money += 10000*ch;
        
        //구매자 치킨 1개 올리고, 돈 빼기
        buyChicken += ch;
        ballance -= 10000*ch;
    }
    // 거래가 성립안될때
    else{
        // 잔액이 부족한 경우
        if(ballance<(PRICE*ch))
            cout<<"\n잔액이 부족해 구매를 하지못합니다. 현재 남은 잔액 : "<<ballance<<endl;
        // 판매 가능 치킨 수가 부족한 경우
        if(chicken<ch)
            cout<<"\n치킨 수가 부족해 판매를 진행하지 못합니다. 현재 남은 치킨 : "<<chicken<<endl;
    }
}

//치킨집 현황 출력
void ChickenSeller::GetInfoSeller(){
    cout<<"\n치킨 판매자 현황"<<endl;
    cout<<"남은 치킨 : "<<chicken<<endl;
    cout<<"판매 수익 : "<<money<<endl;
    
    cout<<"\n치킨 구매자 현황"<<endl;
    cout<<"현재 잔액 : "<<ballance<<endl;
    cout<<"치킨 개수 : "<<buyChicken<<endl;
}


int main(void)
{
    // 치킨 구매자 객체 생성
    ChickenSeller seller;
    int num;
    

        cout<<"구매하실 치킨의 개수를 입력해주세요 : ";
        cin>>num;
        // 치킨 판매
        seller.SellChicken(num);
        
        // 판매 정보 출력
        seller.GetInfoSeller();
    // 구매
  
    
    
    return 0;
}
