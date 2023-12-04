//#include <iostream>
//#include <cstring>
//#include <string>
//using namespace std;
//
//typedef long long ll;
//int* SP;  // SP에 대한 메모리는 p의 크기만큼 동적 할당 해야한다.
//void initSP(string p);
//
//void brutesearch(string p, string a, int cnt = 0) {  //p : Pattern String, a : Text String
//    int i, j, n = p.size(), m = a.size();
//    if (n > m) return;
//    for (i = 0; i <= m - n; i++) {
//        for (j = 0; j < n; j++) {
//            cnt++;
//            if (a[i + j] != p[j]) break;
//        }
//        if (j == n) { //결과값 출력
//            cout << i << ", ";
//        }
//    }
//    cout << cnt << '\n';
//}
//
//void kmpsearch(string p, string a, int cnt = 0) {
//    int i, j, m = p.size(), n = a.size();
//    initSP(p);
//    for (i = 0, j = -1; i <= n - 1; i++) {
//        while ((j >= 0) && (p[j + 1] != a[i])) { j = SP[j]; cnt++; }
//        if (p[j + 1] == a[i]) { j++; cnt++; }
//        if (j == m - 1) {
//            // 결과값 출력
//            cout << (i - m + 1) << ", ";
//            j = SP[j];
//        }
//    }
//    cout << cnt << '\n';
//}
//
//void initSP(string p) {
//    int i, j, m = p.size();
//    SP[0] = -1;
//    for (i = 1, j = -1; i <= m - 1; i++) {
//        while ((j >= 0) && (p[j + 1] != p[i])) j = SP[j];
//        if (p[j + 1] == p[i]) j++;
//        SP[i] = j;
//    }
//}
//
//const int q = 33554393;
//const int d = 26;
//
//int index(char c) {
//    return (int)c - 65;
//}
//
//void rksearch(string p, string a, int cnt = 0) {
//    int i, j, dM = 1, flag = 0;
//    int h1 = 0, h2 = 0;
//    int m = p.size(), n = a.size();
//    for (i = 1; i < m; i++) dM = (d * dM) % q;
//    for (i = 0; i < m; i++) {
//        h1 = (h1 * d + index(p[i])) % q;
//        h2 = (h2 * d + index(a[i])) % q;
//    }
//    for (i = 0; i < n - m + 1; i++) {
//        flag = 0;
//        cnt++;
//        if (h1 == h2) {
//            flag = 1;
//            for (j = i; j < m + i; j++) {
//                cnt++;
//                if (a[j] != p[j - i]) { flag = 0; break; }
//            }
//
//        }
//        if (flag)
//            cout << i << ", ";
//        if (i < n - m) {
//            h2 = (h2 - index(a[i]) * dM) % q;
//            h2 = (h2 * d + index(a[i + m])) % q;
//        }
//    }
//    cout << cnt << '\n';
//}
//
//int main()
//{
//    string pattern, text;
//    getline(cin, text);
//    getline(cin, pattern);
//
//    SP = new int[pattern.size()];
//    brutesearch(pattern, text, 0);
//    kmpsearch(pattern, text, 0);
//    rksearch(pattern, text, 0);
//
//    return 0;
//}
