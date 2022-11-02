#include <iostream>

using namespace std;

int GetMax(int a, int b){
    cout<<"int GetMax(int a, int b)"<<endl;
    if(a>b){
        return a;
    }
    return b;
}

int GetMax(char a, char b){
    cout <<"char GetMax(char a, char b)"<<endl;
    if(a>b){
        return a;
    }
    return b;
}

int main(){
    cout<<GetMax(4, 10)<<endl;
    cout<<GetMax('a', 'h')<<endl;
    
    return 0;
}
