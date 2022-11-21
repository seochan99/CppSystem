#include <iostream>
#include <algorithm> // find
#include <vector> // vector

using namespace std;
#define CHICKENKEY 0

// 로그인 여부 깃발 전역으로 저장
bool flagLogin=false;


// 회원 클래스
class Member{
private:
    string id; // 회원 아이디
    string password; // 회원 비밀번호
    int rank = 1; // 등급, 1부터 시작
    int point = 0; // 포인트, 0부터 시작
    string key; // 비밀번호 변경 및 탈퇴시 보안키
    bool login = false; // 해당 계정 로그인 여부 체크
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
        string tempPass;

        cout<<"❗️회원 가입 시 입력하였던 비밀번호를 입력하시오 : ";
        cin>>tempPass;
        
        // 임시키와 인스턴스가 가지고 있는 키와 동일하다면 true반환
        if(tempPass.compare(this->password) == 0)
        {
            cout<<"✅ 비밀번호가 인증되었습니다"<<endl;
            
            cout<<"❗️회원 가입 시 입력하였던 보안키를 입력하시오 : ";
            cin>>tempKey;
            // 임시키와 인스턴스가 가지고 있는 키와 동일하다면 true반환
            if(tempKey.compare(this->key) == 0)
            {
                cout<<"✅ 인증되었습니다"<<endl;
                return true;
            }
        }
        cout<<"⚠️ 보안키 또는 비밀번호가 틀렸습니다. 뒤로 돌아갑니다."<<endl;
        return false;
    }
    // 비밀번호 찾기
    void FindPassword(){
        string tempKey;

        cout<<"❗️회원 가입 시 입력하였던 보안키를 입력하시오 : ";
        cin>>tempKey;
        if(tempKey.compare(this->key) == 0)
        {
            cout<<"✅ 보안키가 인증되었습니다"<<endl;
            cout<<"🔎 "<<this->id<<"의 비밀번호는 "<<this->password<<"입니다."<<endl;
        }else{
            cout<<"⚠️ 보안키가 틀렸습니다. 다시 진행해주시길 바랍니다."<<endl;
        }
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
                cout<<"🔑 변경할 비밀번호를 입력해주세요 : ";
                cin>>changePassword1;
                cout<<"🔑 한번 더 입력해주세요 : ";
                cin>>changePassword2;
                if(changePassword1.compare(changePassword2)==0)
                {
                    flag = false;
                    this->password = changePassword1;
                    cout<<"✅ 비밀번호 변경이 완료되었습니다"<<endl;
                }else{
                    cout<<"❗️두 비밀번호가 일치하지 않습니다. 다시입력해주시길 바랍니다.❗️"<<endl;
                }
            }
        }
    }
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
    // 랭크가져오기
    int getRank(){
        return this->rank;
    }
    // 포인트 가져오기
    int getPoint(){
        return this->point;
    }
    void upPoint(string choice)
    {
        if(choice.compare("Fried") == 0){
            point += 16000*0.01;
            cout<<"💰"<<16000*0.01<<"포인트가 적립됐습니다.(현재 누적 포인트 : "<<this->point<<")"<<endl;
        }
        else if(choice.compare("SoySauce") == 0)
        {
            point += 20000*0.01;
            cout<<"💰"<<20000*0.01<<"포인트가 적립됐습니다.(현재 누적 포인트 : "<<this->point<<")"<<endl;
        }
        else if(choice.compare("Seasoned") == 0){
            point += 18000*0.01;
            cout<<"💰"<<18000*0.01<<"포인트가 적립됐습니다.(현재 누적 포인트 : "<<this->point<<")"<<endl;
        }
        updateRank();
    }
    void updateRank(){
        // 포인트 업과 함께 랭크 업데이트
        if(point>300 && point<500){
            rank = 2;
        }else if(point>500 && point<1000)
        {
            rank = 3;
        }else if(point>1000){
            rank = 4;
        }
    }
};



// 음식 클래스
class Food{
private:
    int key; // key값에 따라 음식 구분 0 이면 치킨, 1 이면 피자
    string name; // 음식 이름
    int price; // 음식 가격
    string intro;
    string from;
public:
    // 생성자
    Food(int key,string name,int price,string intro,string from){
        this->key = key; // 음식 코드 받기
        this->name = name; // 음식 이름
        this->price = price; // 음식 가격
        this->intro = intro; // 메뉴 소개
        this->from = from; // 메뉴 원산지
    }
    // 음식 키 값 가져오기
    int getFoodKey(){
        return this->key;
    }
    // 음식 이름 가져오기
    string getFoodName(){
        return this->name;
    }
    // 음식 키 값 가져오기
    int getPrice(){
        return this->price;
    }
    
    // 음식 한줄 소개, 원산지 안내
    void getInfo(){
        cout<<" 📝 메뉴소개"<<endl;
        cout<<" "<<this->intro<<endl;
        cout<<" 💰 가격"<<endl;
        cout<<" "<<this->price<<endl;
        cout<<" 🐤 원산지"<<endl;
        cout<<" "<<this->from<<endl;
    }
    
    
};

// 클래스별 벡터 생성
vector<Member> members;
vector<Food> foods;

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

// Mypage
void Mypage();

//계정삭제
void deleteAccount();

// Mypage UI그리기
string MypageUI(vector<Member>::iterator iter);

// 치킨집 UI 그리기
string ChickenUI(vector<Member>::iterator iter);
// 치킨집
void Chicken();

// fired 치킨 ui
string ChickenDetail(vector<Member>::iterator iter,string choice);

int main(int argc, const char * argv[]) {
    
    // 치킨생성, 치킨 key값으로 치킨 생성
    foods.push_back(Food(CHICKENKEY,"Fried",14000,"바삭바삭한 치킨","국내산"));
    foods.push_back(Food(CHICKENKEY,"Seasoned",16000,"양념이 맛있는 치킨","칠레산"));
    foods.push_back(Food(CHICKENKEY,"SoySauce",20000,"간장치킨이 진리~!","중국산"));
    // start함수
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
    string key1; // 보안키
    string key2; // 보안키 확인용
    bool flag = true; // 로그인 여부를 확인하기 위한 깃발
    bool doubleflag = false; // 중복 id체크 여부를 위한 깃발
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
                    cout<<"❗️ 해당 id가 이미 존재합니다. 다시 입력해주세요."<<endl;
                    doubleflag = true;
                    break;
                }
                }

            // 만약 중복되는 id가 없다면 flag = false로
            if(doubleflag == false){
                    flag = false;
            }
            // 깃발 초기화
            doubleflag = false;
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
 
        // 보안키 확인 알고리즘
        while(true)
        {
            // password1 입력
            cout<<"💡비밀번호 변경 혹은 회원삭제를 위한 보안키를 입력해주세요💡"<<endl;
            cout<<"💡보안키는 6자리이하 영어,특수문자,숫자중 설정가능합니다.💡"<<endl;
            cout<<"🔐 보안키 입력 : ";
            cin>>key1;
            
            // password2 입력
            cout<<"🔐 (확인용)보안키를 다시 입력해주세요 : ";
            cin>>key2;
            // 길이부터 체크
                if(key1.length()>6)
                {
                    cout<<"❗️보안키는 6자리이하로 입력하셔야 합니다."<<endl;
                    continue;
                }else if(key1.compare(key2)==0)
                {
                    cout<<"✅ 보안키가 설정됐습니다."<<endl;
                    break;
                    
                }
                else{
                    cout<<"❗️두 보안키가 일치하지 않습니다. 다시입력해주시길 바랍니다.❗️"<<endl;
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
    cout<<"🌿 Chan's Delivery 로그인 완료 🌿"<<endl<<endl;
    
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
                printf("❗️ 0~2사이의 숫자를 입력해주세요.\n");
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
                if(MenuChoice.compare("mypage")==0)
                {
                    Mypage();
                    break;
                }else if(MenuChoice.compare("chicken")==0)
                {
                    Chicken();
                    // 치킨 식당 리스트
                }else if(MenuChoice.compare("pizza")==0)
                {
                    // 피자 식당 리스트
                    cout<<"🥲 아직 입점되어 있는 피자집이 없습니다."<<endl;
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
                    cout<<"--❗️아래의 명령만을 인식합니다❗️--"<<endl;
                    cout<<"| -  mypage                |"<<endl;
                    cout<<"| -  chicken               |"<<endl;
                    cout<<"| -  pizza                 |"<<endl;
                    cout<<"| -  logout                |"<<endl;
                    cout<<"| -  exit                  |"<<endl;
                    cout<<" --------------------------"<<endl;
                    cout<<"해당하는 명령을 입력해주세요"<<endl;
                }
            }
            
        }
    }

  // 프로그램 종료 문구
  printf("👋 프로그램을 종료합니다\n");
}

// 미로그인시 뜨는 화면
int beforeLogin(){
    int choice;
    cout<<"Chan's Delivery에 오신것을 환영합니다.😆"<<endl;
    cout<<"💡 배달 서비스를 이용하실려면 로그인 또는 회원가입을 진행해주세요."<<endl;
    cout<<"| 1. 회원가입 | 2. 로그인 | 0. 프로그램 종료 |"<<endl;
    cout<<"▶️ 명령어 입력 : ";
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
    cout<<"| [mypage] | [logout] |      |"<<endl;
    cout<<" ----------------------------"<<endl;
    cout<<"| 현재 서비스 지역 : "<<location<<"   |"<<endl;
    cout<<" ----------------------------"<<endl;
    cout<<"|       🧑‍🍳식당 카테고리🧑‍🍳       |"<<endl;
    cout<<" ----------------------------"<<endl;
    cout<<"| 🍗 [chicken] | 🍕 [pizza]  |"<<endl;;
    cout<<" ----------------------------"<<endl;
    cout<<"|                            |"<<endl;;
    cout<<"|          Ver 1.7           |"<<endl;;
    cout<<"|                     [exit] |"<<endl;;
    cout<<" ----------------------------"<<endl;
    cout<<"명령어 입력 ▶️ ";
    cin>>choice;
    return choice;
}

void deleteAccount(string id){
    // 계정삭제

    // 인덱스 변수
    int idx=0;
    // iter로 빙글 돌기
    for(vector<Member>::iterator iter = members.begin(); iter!=members.end();++iter)
    {
        if(id.compare(iter->getId()) == 0)
        {
            break;
        }else{
            idx++;
        }
    }
    // idx번째 원소 삭제
    members.erase(members.begin());
    // 로그인 해제
    flagLogin = false;
}

void Mypage(){
    string choice;
    bool accFlag=false; // 계정삭제여부 깃발
        for(vector<Member>::iterator iter = members.begin(); iter!=members.end();++iter){
                // password가 일치하면!
                if(iter->getActivate())
                {
                    while(true)
                    {
                        // 해당 계정 mypage UI그리기
                        choice = MypageUI(iter);
                        // 홈화면으로 가기
                        if(choice.compare("home") == 0){
                            // 홈화면으로
                            break;
                        }//계정 삭제
                        else if(choice.compare("delete") == 0){
                            // 계정삭제 진행
                            // 키체크 성공 시
                            if(iter->keyCheck())
                            {                             
                                // 활성화 해제
                                iter->Deactivate();
                                cout<<"✅ 계정 "<<iter->getId()<<"이 삭제 완료되었습니다."<<endl;
                                deleteAccount(iter->getId());
                                accFlag = true;
                                // 로그인 전 홈화면으로
                                break;
                            }
                            // 키체크 실패 시
                            else{
                                // 다시 mypage로
                                continue;
                            }
                            break;
                        }else if(choice.compare("change") == 0){
                            // 페스워드 변경
                            iter->ChangePassword();
                            // 다시 mypage로
                            continue;
                        }else if(choice.compare("find") == 0){
                            // 비밀번호 찾기
                            iter->FindPassword();
                            // 다시 mypage로
                            continue;
                        }else{
                            cout<<"--❗️아래의 명령만을 인식합니다❗️--"<<endl;
                            cout<<"| -  find                 |"<<endl;
                            cout<<"| -  change               |"<<endl;
                            cout<<"| -  delete               |"<<endl;
                            cout<<"| -  home                 |"<<endl;
                            cout<<" -------------------------"<<endl;
                            cout<<"해당하는 명령을 입력해주세요"<<endl;
                            continue;
                        }
                    }
                }else{
                    if (accFlag==true){
                        accFlag = false;
                        break;
                    }
                }
            }
}


string MypageUI(vector<Member>::iterator iter){
    // chocie
    string choice;
    cout<<endl;
    cout<<" ----------------------------"<<endl;
    cout<<"         👤 MYPAGE 👤        "<<endl;
    cout<<" ----------------------------"<<endl;
    cout<<" 🔑 접속된 ID : "<<iter->getId()<<endl;
    cout<<" ----------------------------"<<endl;
    cout<<" 👑 Rank : "<<iter->getRank()<<endl;
    cout<<" ----------------------------"<<endl;
    cout<<" 💰 Point : "<<iter->getPoint()<<endl;
    cout<<" ----------------------------"<<endl;
    cout<<"                             "<<endl;;
    cout<<"   🔒  [change] password 🔒  "<<endl;;
    cout<<"   🔎  [find] password   🔎  "<<endl;;
    cout<<"   ⚠️  [delete] account  ⚠️    "<<endl;;
    cout<<"                       [home] "<<endl;;
    cout<<" ----------------------------"<<endl;
    cout<<"명령어 입력 ▶️ ";
    cin>>choice;
    return choice;
}

void Chicken(){
    string choice;
    string doubleCheck;
    
        for(vector<Member>::iterator iter = members.begin(); iter!=members.end();++iter){
                // password가 일치하면!
                if(iter->getActivate())
                {
                    while(true)
                    {
                        // 해당 계정 Chicken UI그리기
                        choice = ChickenUI(iter);
                        // 홈화면으로 가기
                        if(choice.compare("home") == 0){
                            // 홈화면으로
                            Start();
                            break;
                        }else if(choice.compare("Fried") == 0 || choice.compare("SoySauce") == 0 || choice.compare("Seasoned") == 0){
                            // 치킨 구매?
                            doubleCheck = ChickenDetail(iter,choice);
                            if(doubleCheck.compare("yes") == 0){
                                cout<<"💡 주문 완료! 결제는 현장에서 진행됩니다."<<endl;
                                cout<<"⏰ 도착예정시간 : 40분 후"<<endl;
                                iter->upPoint(choice); // 포인트 올리기
                            }else if(doubleCheck.compare("no") == 0)
                            {
                                
                            }else{
                                cout<<"❗️메뉴로 돌아갑니다.."<<endl;
                                continue;
                            }
                        }
                        else{
                            cout<<"--❗️아래의 명령만을 인식합니다❗️--"<<endl;
                            cout<<"| -  Fried, SoySauce..    |"<<endl;
                            cout<<"| -  home                  |"<<endl;
                            cout<<" -------------------------"<<endl;
                            cout<<"해당하는 명령을 입력해주세요"<<endl;
                            continue;
                        }
                    }
          
                }
            }
}
string ChickenUI(vector<Member>::iterator iter){
    // chocie
    string choice;
    // food전부 객체 한바퀴 돌기
    int i=1;

    cout<<endl;
    cout<<" ----------------------------"<<endl;
    cout<<"         🍗 Chicken 🍗        "<<endl;
    cout<<" ----------------------------"<<endl;
    for(vector<Food>::iterator foodIter = foods.begin(); foodIter!=foods.end();++foodIter){
        // CHICKENKEY를 가지고 있으면
        if(foodIter->getFoodKey() == CHICKENKEY)
            cout<<i++<<". 🐔 : ["<<foodIter->getFoodName()<<"] 💰 : "<<foodIter->getPrice()<<endl;
    }
    cout<<" ----------------------------"<<endl;
    cout<<"                             "<<endl;;
    cout<<" 🫢 치킨 값 1퍼센트 포인트 적립 🫢 "<<endl;;
    cout<<"                             "<<endl;;
    cout<<"                       [home]"<<endl;;
    cout<<" ----------------------------"<<endl;
    cout<<"주문 원하시는 Chicken Name을 입력해주세요. ▶️ ";
    cin>>choice;
    return choice;
}

string ChickenDetail(vector<Member>::iterator iter,string choice){
    string doubleCheck;
    cout<<""<<endl;

    for(vector<Food>::iterator foodIter = foods.begin(); foodIter!=foods.end();++foodIter){
        // choice와 동일하다면 정보 출력

        if(foodIter->getFoodName().compare(choice)==0)
        {
            cout<<" ----------------------------"<<endl;
            cout<<" 🐔 "<<foodIter->getFoodName()<<" Chicken"<<endl;
            cout<<" ----------------------------"<<endl;
            foodIter->getInfo();
            cout<<" ----------------------------"<<endl;
            cout<<"구매 하시겠습니까?(yes or no) ▶️ "; cin>>doubleCheck;
            return doubleCheck;
        }
    }
    // 구매여부 반환
    return doubleCheck;
}
