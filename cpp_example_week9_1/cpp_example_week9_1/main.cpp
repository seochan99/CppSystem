#include <iostream>

using namespace std;

int big(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}

int big(int a[], int size){
    int res = a[0];
    for(int i=1;i<size;i++)
        if(res<a[i])
            res = a[i];
    return res;
}

int small(int a,int b){
    if(a<b)
        return a;
    else
        return b;
}

int small(int a[], int size){
    int res = a[0];
    for(int i=1;i<size;i++)
        if(res>a[i])
            res = a[i];
    return res;
}

int main(void){
    int array[] = { 1, 9, -2, 5, 11, 8, 56, 4, 5, 100, 97, 85, 12, 6 };
    cout << "5와 6중 큰 값 : " << big(5, 6) << endl;
    cout << "7과 8중 작은 값 : " << small(7, 8) << endl;
    cout << "최대값 : " << big(array, sizeof(array) / sizeof(array[0])) << endl;
    cout << "최소값 : " << small(array, sizeof(array) / sizeof(array[0])) << endl;
}
