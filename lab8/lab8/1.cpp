//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm> // for min function
//
//using namespace std;
//
//// 편집 거리를 계산하고 테이블을 출력하는 함수
//int EditDist(int n, string X, int m, string Y, int ins, int del, int chg) {
//    vector<vector<int>> D(n + 1, vector<int>(m + 1));
//
//    // 테이블 초기화
//    for (int i = 0; i <= n; i++)
//        D[i][0] = i * del; // 삭제 비용으로 초기화
//    for (int j = 0; j <= m; j++)
//        D[0][j] = j * ins; // 삽입 비용으로 초기화
//
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            int c = (X[i - 1] == Y[j - 1]) ? 0 : chg;
//            D[i][j] = min({D[i - 1][j] + del,  // 삭제
//                            D[i][j - 1] + ins,  // 삽입
//                            D[i - 1][j - 1] + c}); // 변경 또는 매칭
//        }
//    }
//
//    // 테이블 출력
//    cout << "편집거리 테이블" << endl;
//    for (int i = 0; i <= n; i++) {
//        for (int j = 0; j <= m; j++) {
//            cout << D[i][j] << "  ";
//        }
//        cout << endl;
//    }
//
//    // 최소 편집 비용 반환
//    return D[n][m];
//}
//
//int main() {
//    string X, Y;
//    cout << "초기 문자열을 입력하시오: ";
//    cin >> X;
//    cout << "목표 문자열을 입력하시오: ";
//    cin >> Y;
//
//    int n = X.length();
//    int m = Y.length();
//
//    // 여기서는 삽입, 삭제, 변경 비용이 모두 1로 가정
//    int cost = EditDist(n, X, m, Y, 1, 1, 2);
//    
//    cout << "최소편집비용: " << cost << endl;
//
//    return 0;
//}
