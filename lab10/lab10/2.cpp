#include <iostream>
#include <cstring>
#include <string>
using namespace std;

typedef long long ll;

// Brute-Force
int brute_force_search(string* p, string* t, int cnt = 0) {  //p : Pattern String, a : Text String
    for (int i = 0; i <= 90; i++) { //90 = 100 -10 + 1
        for (int j = 0; j <= 90; j++) {
            bool flag = true;
            for (int a = 0; a < 10; a++) {
                if (flag == false) break;
                for (int b = 0; b < 10; b++) {
                    cnt++;
                    if (p[a][b] != t[i + a][j + b]) {
                        flag = false;
                        break;
                    }
                }
            }
        }
    }

    return cnt;
}

const int q = 33554393;
const int d = 26;


int index(char c) {
    return (int)c - 65;
}

// Rabin-Karp
int rabin_karp_search(string* p, string* a, int cnt = 0) {
    int i, j, h, k, l, dM = 1, h1 = 0, h2 = 0, flag = 0;
    int m = 10, n = 100;
    for (i = 1; i < m; i++) dM = (d * dM) % q;
    for (k = 0; k < n - m + 1; k++) {
        for (l = 0; l < n - m + 1; l++) {
            // [k][l]에서 시작한다
            for (h = k; h < k + m; h++) {
                for (i = l; i < l + m; i++) {
                    h1 = (h1 * d + index(p[h - k][i - l])) % q;
                    h2 = (h2 * d + index(a[h][i])) % q;
                }
            }

            flag = 0;
            cnt++;
            if (h1 == h2) {
                flag = 1;
                for (i = k; i = k + m; k++) {
                    for (j = l; j < l + m; j++) {
                        cnt++;
                        if (p[i - k][j - l] != a[i][j]) {
                            flag = 0;
                            break;
                        }
                    }
                }
            }
        }
    }

    return cnt;
}


int main()
{
    string pattern[10], text[100];

    // Pattern_String 구성
    for (int i = 0; i < 10; i++) {
        if (i == 9) {
            pattern[i] = "AAAAAAAAAB";
        }
        else pattern[i] = "AAAAAAAAAA";
    }

    // Text_String 구성
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            text[i].push_back('A');
        }
    }

    // 출력
    cout << brute_force_search(pattern, text, 0) << '\n';
    cout << rabin_karp_search(pattern, text, 0) << '\n';

    return 0;
}
