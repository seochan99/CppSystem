#include <iostream>
#include <string>

using namespace std;

class BankClient {
private:
  string name;
  int accountNumber;
  int balance;

public:
  // 생성자
  BankClient(string n, int acc, int bal)
      : name(n), accountNumber(acc), balance(bal) {}
  //
  void getBankClient() {
    cout << "\n예금주 : " << name << endl;
    cout << "전화번호 : " << accountNumber << endl;
    cout << "잔액 : " << balance << endl << endl;
  }

  // 출금
  void withdraw(int money) {
    if (money > balance)
      cout << "잔액부족! 현재 잔액 : " << balance << endl<<endl;
    else {
      balance -= money;
      cout << "출금 완료! 현재 잔액 : " << balance << endl<<endl;
    }
  }

  // 입금
  void deposit(int money) {
    balance += money;
    cout << "입금 완료! 현재 잔액 : " << balance << endl<<endl;
  }

  // 소멸자
  ~BankClient() { cout << name << "객체가 소멸되었습니다." << endl; }
};

int main() {
  int opt = 10;
  int money = 0;
  //객체 생성
  BankClient bc("Alice", 20221002, 100000);

  while (1) {
    cout << "*******은행프로그램*******" << endl;
    cout << "1. 입금                " << endl;
    cout << "2. 출금                " << endl;
    cout << "3. 계좌정보 확인         " << endl;
    cout << "0. 프로그램 종료         " << endl;
    cout << "원하시는 번호를 눌러주세요. " << endl;
    cout << "**************************" << endl;

    cin >> opt;
    if (opt == 1) {
      cout << "\n입금하실 금액을 입력해주세요 : ";
      cin >> money;
      cout << endl;
      // 입금
      bc.deposit(money);
    } else if (opt == 2) {
      cout << "\n출금하실 금액을 입력해주세요 : ";
      cin >> money;
      cout << endl;
      // 입금
      bc.withdraw(money);
    } else if (opt == 3) {
      bc.getBankClient();
    } else if (opt == 0) {
      cout << "프로그램이 종료됩니다." << endl;
      break;
    } else {
      cout << "\n메뉴에 있는 숫자를 입력해주시길 바랍니다.\n" << endl;
    }
  }
}
