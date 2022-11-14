#include <iostream>
#include <algorithm> // find
#include <vector> // vector
#include "account.hpp"

using namespace std;
#define MEMBERNUM 100;

// 로그인 여부 깃발 전역으로 저장
bool flagLogin=false;


// 회원 클래스
class Member{
private:
    string id; // 회원 아이디
    string password; // 회원 비밀번호
    int rank = 1; // 등급, 1부터 시작
    int point = 0; // 포인트, 0부터 시작
    string key; // 비밀번호 변경 및 탈퇴시 인증키
    bool login=false; // 해당 계정 로그인 여부 체크
public:
    
    // 회원 생성자 호출 시 id, password 가진상태로 시작
    Member(string id, string password, string key){
        this->id = id;
        this->password = password;
        this->key = key;
    }
    // 임시 암호키 확인
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
    
    // id 반환
    string getId(){
        return this->id;
    }
    string getPassword(){
        return this->password;
    }
    bool getActivate(){
        return this->login;
    }
    
    void Activate(){
        this->login = true;
    }
    void Deactivate(){
        this->login = false;
    }
    
};



// 음식 클래스
class Food{
    
};

// 식당 클래스
class Restaurant{
    
};

// 클래스별 벡터 생성
vector<Member> members;
vector<Food> foods;
vector<Restaurant> restaurants;


// 로그인 이전 메인 메뉴 뜨게하기
int beforeLogin();
string AfterLoginMainMenu();
// 시작함수
void Start();

// 회원가입 함수
void SignUp();
// 로그인 기능
void LogIn();
// 로그아웃기능
void Logout();

int main(int argc, const char * argv[]) {
    Start();
    
    return 0;
}

// 로그인 구현
void LogIn(){
    string id;
    string password;
    bool flag=true;
        
        // 로그인 진행
        cout<<"🔑 ID를 입력해주세요 : ";
        cin>>id;
        cout<<"🔒 PASSWORD를 입력해주세요 : ";
        cin>>password;
        
        // 해당 id찾기
        for(vector<Member>::iterator iter = members.begin(); iter!=members.end();++iter){
            
            // id가 있다면!
            if (iter->getId().compare(id) == 0)
            {
                
                // password가 일치하면!
                if(iter->getPassword().compare(password) ==0)
                {
                    // 로그인 완료!!
                    iter->Activate(); // 활성화시키기
                    flagLogin = true;
                    // 로그인 완료시 false!
                    flag = false;
                    break;
                }
                
            }
        }
        // flag가 여전히 true면 해당 아이디 못찾음
        if(flag==true)
        {
            cout<<"❗️해당하는 계정이 존재하지않습니다."<<endl;
            cout<<"❗️다시 로그인을 진행해주시길 바랍니다."<<endl;
            beforeLogin();
        }

    }

// 로그아웃
void Logout(){
    for(vector<Member>::iterator iter = members.begin(); iter!=members.end();++iter){
            // password가 일치하면!
            if(iter->getActivate())
            {
                // 비활성화 시키기
                // 해당 계정 비활성화
                iter->Deactivate();
                
                //로그인 전역변수 false로
                flagLogin = false;
                break;
            }
        }
    }

// 회원가입 구현
void SignUp(){
    string id;
    string password1; // 패스워드
    string password2; // 확인용 패스워드
    string key1; // 인증키
    string key2; // 인증키 확인용
    bool flag = true;
    // 객체 생성자 호출
    
    //아이디 중복 확인 알고리즘
    while(flag)
    {
        cout<<"🔒 ID를 입력해주세요 : ";
        cin>>id;
        
        // 반복체크
        // 사이즈가 0이면 아직 생성된 회원 없음
        // id중복 체크 필요없음
        if(members.size() == 0)
        {
            break;
        }
        else{
            // 동일아이디이 있는지 vector돌면서 check
            for(vector<Member>::iterator iter = members.begin(); iter!=members.end();++iter){
                // 동알한 아이디가 있다면
                if (iter->getId().compare(id) == 0)
                {
                    cout<<"❗️이미 중복된 id가 존재합니다. 다시 입력해주세요."<<endl;
                    break;
                }else{
                    // 만약 중복되는 id가 없다면 flag = false로
                    flag = false;
                }
            }
        }
        
        
    }
    // 패스워드 확인 알고리즘
    while(true)
    {
        // password1 입력
        cout<<"🔑 PASSWORD를 입력해주세요 : ";
        cin>>password1;
        
        // password2 입력
        cout<<"🔑 (확인용)PASSWORD를 다시 입력해주세요 : ";
        cin>>password2;
        
            if(password1.compare(password2)==0)
            {
                cout<<"✅ 비밀번호가 설정됐습니다."<<endl;
                break;
            }else{
                cout<<"❗️두 비밀번호가 일치하지 않습니다. 다시입력해주시길 바랍니다.❗️"<<endl;
                continue;
            }
    }
 
        // 인증키 확인 알고리즘
        while(true)
        {
            // password1 입력
            cout<<"💡비밀번호 변경 혹은 회원삭제를 위한 인증키를 입력해주세요💡"<<endl;
            cout<<"💡인증키는 6자리이하 영어,특수문자,숫자중 설정가능합니다.💡"<<endl;
            cout<<"🔐 인증키 입력 : ";
            cin>>key1;
            
            // password2 입력
            cout<<"🔐 (확인용)인증키를 다시 입력해주세요 : ";
            cin>>key2;
            // 길이부터 체크
                if(key1.length()>6)
                {
                    cout<<"❗️인증키는 6자리이하로 입력하셔야 합니다."<<endl;
                    continue;
                }else if(key1.compare(key2)==0)
                {
                    cout<<"✅ 인증키가 설정됐습니다."<<endl;
                    break;
                    
                }
                else{
                    cout<<"❗️두 인증키가 일치하지 않습니다. 다시입력해주시길 바랍니다.❗️"<<endl;
                    continue;
                }
        }
    // 객체 생성
    members.push_back(Member(id,password1,key1));
    // 중복확인, it 포인터 생성
    
    // 해당 객체 signup activate로 바꾸기
    for(vector<Member>::iterator iter = members.begin(); iter!=members.end();++iter){
            // 해당하는 id찾으면
            if(iter->getId().compare(id) == 0)
            {
                // 해당계정활성화시키고 로그인 전역변수 true로 바꾸기
                iter->Activate();
                flagLogin = true;
                break;
            }
        }
    // 로그인 완료
    cout<<"🌿 Chan's Delivery 로그인 완료 🌿"<<endl;
    
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
                // 로그인 되어있다면 탈출
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
                    Logout();
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
    cout<<"Chan's Delivery에 오신것을 환영합니다.😆"<<endl;
    cout<<"💡 배달 서비스를 이용하실려면 로그인 또는 회원가입을 진행해주세요."<<endl;
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


