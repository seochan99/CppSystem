#include <iostream>
#include <string>

using namespace std;

class YoutubeSize{
private:
    int width;
    int height;
public:
    YoutubeSize();
    YoutubeSize(int, int);
    int GetWidth();
    int GetHeight();
    void ResizeWindow(int,int);
};

// 이니셜라이저
YoutubeSize::YoutubeSize() : width(800), height(600){}
YoutubeSize::YoutubeSize(int w, int h):YoutubeSize()
{
    ResizeWindow(w, h);
}

int YoutubeSize::GetHeight(){
    return height;
}

int YoutubeSize::GetWidth(){
    return width;
}

void YoutubeSize::ResizeWindow(int w, int h)
{
    if(w>800) width=w;
    else width = 800;
    
    if(h>600) height =h;
    else height = 600;
}

int main(void)
{
    
    // 객체 생성
    YoutubeSize mainWindow;
    
    // 리사이즈
    mainWindow.ResizeWindow(854, 480);
    //출력
    cout<<mainWindow.GetWidth()<<" X "<<mainWindow.GetHeight()<<endl;
    
    mainWindow.ResizeWindow(1920, 1080);
    cout<<mainWindow.GetWidth()<<" X "<<mainWindow.GetHeight()<<endl;
    
    mainWindow.ResizeWindow(3840, 2160);
    cout<<mainWindow.GetWidth()<<" X "<<mainWindow.GetHeight()<<endl;
    
    return 0;
}
