#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for min function

using namespace std;

// 편집 경로를 나타내는 열거형 타입
enum Operation { NONE, INSERT, DELETE, CHANGE, MATCH };

// 열거형 타입에 따른 문자 출력 함수
char OpToChar(Operation op) {
    switch (op) {
        case INSERT: return 'I';
        case DELETE: return 'D';
        case CHANGE: return 'C';
        case MATCH: return 'O';
        default: return ' ';
    }
}

int EditDist(int n, string X, int m, string Y, int ins, int del, int chg) {
    vector<vector<int>> D(n + 1, vector<int>(m + 1));
    vector<vector<Operation>> op(n + 1, vector<Operation>(m + 1));

    // 테이블 초기화
    for (int i = 0; i <= n; i++) {
        D[i][0] = i * del;
        op[i][0] = DELETE;
    }
    for (int j = 0; j <= m; j++) {
        D[0][j] = j * ins;
        op[0][j] = INSERT;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int costChange = (X[i - 1] == Y[j - 1]) ? 0 : chg;
            int costInsert = D[i][j - 1] + ins;
            int costDelete = D[i - 1][j] + del;
            int costChangeOrMatch = D[i - 1][j - 1] + costChange;

            D[i][j] = min({costInsert, costDelete, costChangeOrMatch});

            // 연산 추적
            if (D[i][j] == costChangeOrMatch) {
                op[i][j] = (X[i - 1] == Y[j - 1]) ? MATCH : CHANGE;
            } else if (D[i][j] == costDelete) {
                op[i][j] = DELETE;
            } else {
                op[i][j] = INSERT;
            }
        }
    }

    // 최소비용 경로 추적
    string path;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        path += OpToChar(op[i][j]);
        switch (op[i][j]) {
            case CHANGE:
            case MATCH:
                i--; j--;
                break;
            case DELETE:
                i--;
                break;
            case INSERT:
                j--;
                break;
            default:
                break;
        }
    }

    // 나머지 경로 처리
    while (i > 0) {
        path += 'D';
        i--;
    }
    while (j > 0) {
        path += 'I';
        j--;
    }

    // 경로는 역순으로 추적되었으므로 뒤집어 줌
    reverse(path.begin(), path.end());

    // 테이블 출력
    cout << "편집거리 테이블" << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << D[i][j] << "  ";
        }
        cout << endl;
    }

    // 경로 출력
    cout << "최소비용 경로 : " << path << endl;

    // 최소 편집 비용 반환
    return D[n][m];
}

int main() {
    string X, Y;
    cout << "초기 문자열을 입력하시오: ";
    cin >> X;
    cout << "목표 문자열을 입력하시오: ";
    cin >> Y;

    int n = X.length();
    int m = Y.length();

    // 삽입, 삭제, 변경 비용 설정 (변경 비용을 2로 설정)
    EditDist(n, X, m, Y, 1, 1, 2);

    return 0;
}
