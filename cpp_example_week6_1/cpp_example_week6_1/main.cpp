#include <iostream>
#include <string>

using namespace std;


int main(void)
{
    string name[5];
    
    for(int i=0;i<5;i++){
        cout<<"NAME : ";
        getline(cin, name[i], '\n');
    }
    
    string latter = name[0];
    
    
    for(int i=0;i<5;i++){
        if(name[i].compare(latter)>0)
            latter = name[i];
            
    }
    cout<<latter<<endl;
    
    
    return 0;

}
