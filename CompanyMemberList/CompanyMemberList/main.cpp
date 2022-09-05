#include <iostream>
#include <cstring>
using namespace std;

// 이름공간 만들기
namespace COM_POS
{
    enum {CLERK, SENIOR, ASSIST, MANAGER};

    void ShowPositionInfo(int pos)
{
        switch (pos) {
            case CLERK:
                cout<<"사원"<<endl;
                break;
            case SENIOR:
                cout<<"주임"<<endl;
                break;
            case ASSIST:
                cout<<"대리"<<endl;
                break;
            case MANAGER:
                cout<<"과장"<<endl;
        }
    }

}

class NameCard
{
private:
    char * name;
    char * company;
    char * phone;
    int position;
    
public:
    
    //생성자
    NameCard(char * _name, char *_company, char * _phone, int pos):position(pos)
    {
        // 크기만큼 동적할당 배열
        name = new char[strlen(_name)+1]; // name을 입력받은 길이 만큼 동적할당 받기
        company = new char[strlen(_company)+1];
        phone = new char[strlen(_phone)+1];
        
        // 배열 복사
        strcpy(name, _name);
        strcpy(company, _company);
        strcpy(phone, _phone);
    }
    void ShowNameCardInfo()
    {
        cout<<"이름 : "<<name<<endl;
        cout<<"회사 : "<<company<<endl;
        cout<<"전화번호 : "<<phone<<endl;
        cout<<"직급 : ";
        COM_POS::ShowPositionInfo(position);
        cout<<endl;
    }
    
    // 소멸자
    ~NameCard()
    {
        delete []name;
        delete []company;
        delete []phone;
    }
};

int main(void)
{
    NameCard manClerk("Lee","ABCEng","010-2321-2123",COM_POS::CLERK);
    NameCard manSENIOR("chan","A23124CEng","010-3333-2423",COM_POS::SENIOR);
    NameCard manAssist("Lee","ABCEng","010-2321-2123",COM_POS::ASSIST);
    
    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    
    
    
    return 0;
}
