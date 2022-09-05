#include <iostream>
using namespace std;

// 2->3
// 이니셜라이저 사용

class FruitSeller
{
    
private:
    const int APPLE_PRICE;
    int numOfApples;
    int myMoney;
    
public:
    FruitSeller(int price, int num, int money):APPLE_PRICE(price), numOfApples(num), myMoney(money) //생성자
    {
        // 이니셜라이저 이용으로 인해 본체는 비어졌음
    }
    
    int SaleApples(int money) // 사과팔기
    {
        int num = money/APPLE_PRICE;
        numOfApples-=num;
        myMoney+=money;
        return num;
    }
    
    void ShowSalesResult() const //판매 결과보기
    {
        cout<<"남은 사과 : "<<numOfApples<<endl;
        cout<<"판매 수익 : "<<myMoney<<endl<<endl;
    }
};

class FruitBuyer
{
private:
    int myMoney;
    int numOfApples;
public:
    FruitBuyer(int money):myMoney(money), numOfApples(0)
    {
        // 이니셜라이저 이용으로 인해 본체는 비어졌음
    }
    void BuyApples(FruitSeller &seller, int money){
        numOfApples+=seller.SaleApples(money);
        myMoney -= money;
    }
    void ShowBuyResult() const
    {
        cout<<"현재 잔액 : "<<myMoney<<endl;
        cout<<"사과 개수 : "<<numOfApples<<endl;
    }
};

int main(void){
    FruitSeller seller(1000,20,0);
    FruitBuyer buyer(5000);
    buyer.BuyApples(seller, 2000);
    
    cout<<"과일 판매자의 현황"<<endl;
    seller.ShowSalesResult();
    
    cout<<"과일 구매자의 현황"<<endl;
    buyer.ShowBuyResult();
    return 0;
}
