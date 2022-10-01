#include <iostream>
#include <string>

using namespace std;

class Fraction{
private:
    int m_numerator;
    int m_denominator;
public:
    Fraction(){
        m_numerator = 0;
        m_denominator = 1;
    }
    int getNumerator() {return m_numerator;}
    int getDenominator() {return m_denominator;}
    double getValue() { return (m_numerator)/ m_denominator; }
    
    ~Fraction(){cout<<"기록삭제"<<endl;}
};

int main(int argc, const char * argv[]) {
    Fraction frac;
    cout<< frac.getNumerator()<<frac.getDenominator()<<'\n';
    cout<<frac.getValue()<<endl;
    
    
    return 0;
}
