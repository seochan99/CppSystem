//#include <iostream>
//#include <cstring>
//#include <string>
//using namespace std;
//
//typedef long long ll;
//
//// 브루트포스 알고리즘
//int bruteForceSearch(string* pattern, string* text, int count = 0) {
//    for (int i = 0; i <= 90; i++) { // 90 = 100 - 10 + 1
//        for (int j = 0; j <= 90; j++) {
//            bool match = true;
//            for (int a = 0; a < 10; a++) {
//                if (!match) break;
//                for (int b = 0; b < 10; b++) {
//                    count++;
//                    if (pattern[a][b] != text[i + a][j + b]) {
//                        match = false;
//                        break;
//                    }
//                }
//            }
//        }
//    }
//
//    return count;
//}
//
//const int q = 33554393;
//const int d = 26;
//
//// 문자를 인덱스로 변환하는 함수
//int charToIndex(char c) {
//    return (int)c - 65;
//}
//
//// 라빈-카프 알고리즘
//int rabinKarpSearch(string* pattern, string* text, int count = 0) {
//    int h, k, l, dM = 1, patternHash = 0, textHash = 0, matchFlag = 0;
//    int patternSize = 10, textSize = 100;
//    for (int i = 1; i < patternSize; i++) dM = (d * dM) % q;
//    for (k = 0; k < textSize - patternSize + 1; k++) {
//        for (l = 0; l < textSize - patternSize + 1; l++) {
//            // [k][l]에서 시작
//            for (h = k; h < k + patternSize; h++) {
//                for (int i = l; i < l + patternSize; i++) {
//                    patternHash = (patternHash * d + charToIndex(pattern[h - k][i - l])) % q;
//                    textHash = (textHash * d + charToIndex(text[h][i])) % q;
//                }
//            }
//
//            matchFlag = 0;
//            count++;
//            if (patternHash == textHash) {
//                matchFlag = 1;
//                for (int i = k; i < k + patternSize; k++) {
//                    for (int j = l; j < l + patternSize; j++) {
//                        count++;
//                        if (pattern[i - k][j - l] != text[i][j]) {
//                            matchFlag = 0;
//                            break;
//                        }
//                    }
//                }
//            }
//        }
//    }
//
//    return count;
//}
//
//
//int main()
//{
//    string pattern[10], text[100];
//
//    // 패턴 문자열 구성
//    for (int i = 0; i < 10; i++) {
//        if (i == 9) {
//            pattern[i] = "AAAAAAAAAB";
//        }
//        else pattern[i] = "AAAAAAAAAA";
//    }
//
//    // 텍스트 문자열 구성
//    for (int i = 0; i < 100; i++) {
//        for (int j = 0; j < 100; j++) {
//            text[i].push_back('A');
//        }
//    }
//
//    // 결과 출력
//    cout << bruteForceSearch(pattern, text, 0) << '\n';
//    cout << rabinKarpSearch(pattern, text, 0) << '\n';
//
//    return 0;
//}
