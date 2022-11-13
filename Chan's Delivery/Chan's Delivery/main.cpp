#include <iostream>
#include <list>

using namespace std;
#define MEMBERNUM 100;

// 로그인 여부 깃발 전역으로 저장
bool flagLogin=false;

// id 중복 검사용 서버
//class Server{
//    bool IsOverlapped(const string &id);
//};

// 회원 클래스
class Member{
private:
    string id; // 회원 아이디
    string password; // 회원 비밀번호
    int rank = 1; // 등급, 1부터 시작
    int point = 0; // 포인트, 0부터 시작
    string key; // 비밀번호 변경 및 탈퇴시 인증키
public:
    
    // 회원 생성자 호출 시 id, password 가진상태로 시작
    Member(string id, string password){
        this->id = id;
        this->password = password;
    }
    bool keyCheck(){
        // 임시키 입력
        string tempKey;
        cout<<"회원 가입 시 입력하였던 보안키 네글자를 입력하시오."<<endl;
        cin>>tempKey;
        
        // 임시키와 인스턴스가 가지고 있는 키와 동일하다면 true반환
        if(tempKey.compare(this->key) == 0)
        {
            cout<<"인증되었습니다"<<endl;
            return true;
        }
        return false;
    }
    // 비밀번호 변경
    void ChangePassword(){
        string changePassword1;
        string changePassword2;
        bool flag = true; // 비밀번호 처음, 재입력이 같은지 확인
        // keyCheck가 트루라면 비번 변경 시행
        if(keyCheck()){
            // 비밀번호 처음, 재입력이 같을때까지 무한 반복
            while (flag) {
                cout<<"변경할 비밀번호를 입력해주세요."<<endl;
                cin>>changePassword1;
                cout<<"한번 더 입력해주세요."<<endl;
                cin>>changePassword2;
                if(changePassword1.compare(changePassword2)==0)
                {
                    flag = false;
                    this->password = changePassword1;
                    cout<<"비밀번호 변경이 완료되었습니다😄"<<endl;
                }else{
                    cout<<"❗️두 비밀번호가 일치하지 않습니다. 다시입력해주시길 바랍니다.❗️"<<endl;
                }
            }
   
        }
    }
    
    // ID,비밀번호 설정
    
};

// 음식 클래스
class Food{
    
};

// 식당 클래스
class Restaurant{
    
};

// 로그인 이전 메인 메뉴 뜨게하기
int beforeLogin();
string AfterLoginMainMenu();
// 시작함수
void Start();

// 회원가입 함수
void SignUp();
void LogIn();

// 로그인 기능

int main(int argc, const char * argv[]) {
    Start();
    
    return 0;
}
void LogIn(){
    string id;
    string password;
    cout<<"ID를 입력해주세요 : ";
    cin>>id;
    cout<<"PASSWORD를 입력해주세요 : ";
    cin>>password;
    
    // 해당 객체 찾기
    
    //로그인 완료
    flagLogin = true;
    
}
void SignUp(){
    string id;
    string password;
    cout<<"ID를 입력해주세요 : ";
    cin>>id;
    
    // 객체 생성
    
    // 중복확인
    
    // 로그인 완료
    flagLogin = true;

}
// 작동 함수
void Start()
{
    string id;
    string password;
    // 미로그인 상태
    int outChoice=1;
    while(outChoice != 0)
    {
        // 로그인 안되어있는 상태
        if(flagLogin == false)
        {
            int choice;
            while ((choice = beforeLogin()) != 0)
            {
              //선택한 값에 따라 실행
              switch (choice)
              {
              case 1:
                // 회원가입
                      SignUp();
                break;
              case 2:
                // 로그인
                LogIn();
                break;
              default:
                // 0~3사이의 숫자 입력안할시 아래 문구 출력
                printf("0~2사이의 숫자를 입력해주세요.\n");
                break;
              }
                if(flagLogin==true)
                    break;
            }
            // 프로그램 종료
            if(choice == 0)
            {
                outChoice = 0;
                continue;
            }
            
          }
        
        // 로그인되어 있는 상태
        if(flagLogin == true)
        {
            string MenuChoice="";
            while (MenuChoice.compare("exit")!=0)
            {
                MenuChoice = AfterLoginMainMenu();
                // 마이페이지 이동
                if(MenuChoice.compare("마이페이지")==0)
                {
                    
                }else if(MenuChoice.compare("치킨")==0)
                {
                    // 치킨 식당 리스트
                }else if(MenuChoice.compare("피자")==0)
                {
                    // 피자 식당 리스트
                }else if(MenuChoice.compare("햄버거")==0)
                {
                    // 햄버거 식당 리스트
                }else if(MenuChoice.compare("logout")==0)
                {
                    // 로그아웃진행
                    flagLogin = false;
                    break;
                }else if(MenuChoice.compare("exit")==0)
                {
                    flagLogin = false;
                    outChoice = 0;
                    continue;
                }
                else{
                    cout<<"---아래의 명령만을 인식합니다---"<<endl;
                    cout<<"| - 마이페이지              |"<<endl;
                    cout<<"| -  치킨                 |"<<endl;
                    cout<<"| -  피자                 |"<<endl;
                    cout<<"| -  햄버거                |"<<endl;
                    cout<<"| -  logout              |"<<endl;
                    cout<<"| -  exit                |"<<endl;
                    cout<<" ------------------------"<<endl;
                    cout<<"해당하는 명령을 입력해주세요"<<endl;
                    
                    
                }
            }
            
        }
    }

  // 프로그램 종료 문구
  printf("프로그램을 종료합니다\n");
}

// 미로그인시 뜨는 화면
int beforeLogin(){
    int choice;
    cout<<"배달 서비스를 이용하실려면 로그인 또는 회원가입을 진행해주세요."<<endl;
    cout<<"| 1. 회원가입 | 2. 로그인 | 0. 프로그램 종료 |"<<endl;
    cin>>choice;
    return choice;
}

// 로그인 되어있을시 뜨는 메인 화면
string AfterLoginMainMenu(){
    string choice;
    string location = "신공학관 6층"; // 서비스 지역
    cout<<" ----------------------------"<<endl;
    cout<<"|    📦 Chan's Delivery 📦   |"<<endl;
    cout<<" ----------------------------"<<endl;
    cout<<"| mypage | logout |          |"<<endl;
    cout<<" ----------------------------"<<endl;
    cout<<"| 현재 서비스 지역 : "<<location<<"   |"<<endl;
    cout<<" ----------------------------"<<endl;
    cout<<"|       🧑‍🍳식당 카테고리🧑‍🍳       |"<<endl;
    cout<<" ----------------------------"<<endl;
    cout<<"| 🍗 치킨 | 🍕 피자 | 🍔 햄버거 |"<<endl;;
    cout<<" ----------------------------"<<endl;
    cout<<"|                            |"<<endl;;
    cout<<"|           Ver 1.4          |"<<endl;;
    cout<<"|                       exit |"<<endl;;
    cout<<" ----------------------------"<<endl;
    cout<<"명령어 입력 : ";
    cin>>choice;
    return choice;
}


