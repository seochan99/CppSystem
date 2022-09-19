#include <iostream>
#include <stdlib.h>

using namespace std;

class Rectangle{
public:
    int width;
    int height;
    double getArea();
};

// Circle 구현부
double Rectangle::getArea() {
    return width*height;
};

int main(void)
{
    Rectangle rect;
    rect.width = 3;
    rect.height = 5;
    cout<<"사각형의 면적은 : "<<rect.getArea()<<endl;
    
    return 0;
}
