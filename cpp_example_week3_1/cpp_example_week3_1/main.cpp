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
YoutubeSize::YoutubeSize(int w, int h){
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
    // 인수 2개를 전달할때의 선언
    YoutubeSize youtubeSize(1000,800);
    
    cout<<"인수 2개 전달받은 youtubeSize width : "<<youtubeSize.GetWidth()<<endl;
    cout<<"인수 2개 전달받은 youtubeSize height : "<<youtubeSize.GetHeight()<<endl;
    
    
    // resize
    youtubeSize.ResizeWindow(1400, 600);
    
    cout<<"Resize된 인수 2개 전달받은 youtubeSize width :"<<youtubeSize.GetWidth()<<endl;
    cout<<"Resize된 인수 2개 전달받은 youtubeSize height : "<<youtubeSize.GetHeight()<<endl;
    
    // 인수를 전달안할때의 선언
    YoutubeSize youtubeSize2;
    
    cout<<"인수 전달받지 않은 youtubeSize width : "<<youtubeSize2.GetWidth()<<endl;
    cout<<"인수 전달받지 않은 youtubeSize height : "<<youtubeSize2.GetHeight()<<endl;
    
    
    
    return 0;
}
