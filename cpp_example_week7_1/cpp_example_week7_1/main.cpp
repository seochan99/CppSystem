#include <iostream>
#include <string>

using namespace std;

void half(double &num){
    num/=2;
}

int main(void)
{
    double n = 20;
    half(n);
    cout<<n<<endl;
    
    return 0;
}
