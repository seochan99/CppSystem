#include <iostream>

using namespace std;

class CRect{
    
private:
    int left,top,right,bottom;
public:
    void print(){
        cout<<"("<<left<<", "<<top<<", "<<right<<", "<<bottom<<")"<<endl;
    }
    void SetRect(int l, int t, int r, int b)
    {
        left = l;
        right = r;
        top = t;
        bottom = b;
    }
};

int main(void)
{
    CRect rc;
    rc.SetRect(0, 0, 20, 20);
    rc.print();
    
    return 0;
}
