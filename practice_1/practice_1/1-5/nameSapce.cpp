//#include <iostream>
//
//using namespace std;
//
//namespace AAA {
//    namespace BBB {
//        namespace CCC {
//            int num1;
//            int num2;
//        }
//    }
//}
//int main(void){
//    AAA::BBB::CCC::num1 = 20;
//    AAA::BBB::CCC::num2 = 30;
//    
//    namespace ABC = AAA::BBB::CCC;
//    cout<<ABC::num1<<endl;
//    cout<<ABC::num2<<endl;
//}
//
//int val = 100; // global
//
//int SimpleFunc(void){
//    int val = 20;
//    val+=3; // 지역변수 증가
//    ::val += 7; //전역변수 증가
//}
//
//
