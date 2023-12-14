#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;


const int alphabet_count = 26;
int *skip, *lp, *SP;

int index(char c) {
    return (int)c - 'A';
}

void initSP(char *p) {
    int m = strlen(p);
    SP[0] = -1;
    for (int i = 1, j = -1; i < m; i++) {
        while ((j >= 0) && (p[j + 1] != p[i])) j = SP[j];
        if (p[j + 1] == p[i]) j++;
        SP[i] = j;
    }
}



void LastPos(char *p) {
    for (int i = 0; i < alphabet_count; i++) lp[i] = -1;
    for (int i = 0; i < strlen(p); i++) lp[index(p[i])] = i;
}

void GoodSuffix(char *p) {
    int m = strlen(p);
    char *r_p = new char[m];
    for (int i = 0; i < m; i++) {
        r_p[m - i - 1] = p[i];
    }
    initSP(r_p);
    for (int i = -1; i <= m - 1; i++) skip[i] = m - 1 - SP[m - 1];
    for (int k = 0; k <= m - 1; k++) {
        int i = m - 1 - SP[k] - 1;
        if (skip[i] > k - SP[k]) skip[i] = k - SP[k];
    }
    delete[] r_p;
}

void BoyerMoore(char *p, char *a) {
    int m = strlen(p), n = strlen(a);
    LastPos(p);
    GoodSuffix(p);
    vector<int> found_positions;
    int j = 0, cnt = 0;
    while (j <= n - m) {
        int i;
        for (i = m - 1; i >= 0 && p[i] == a[j + i]; i--) cnt++;
        if (i < 0) {
            found_positions.push_back(j);
            j += skip[-1];
        } else {
            j += max(skip[i], i - lp[index(a[j + i])]);
        }
        cnt++;
    }
    for (int pos : found_positions) {
        cout << pos << ", ";
    }
    cout << cnt << " (Boyer-Moore - 문자열의 시작 IDX들, 문자열 비교 횟수)" << '\n';
}

// Brute-Force와 KMP 함수는 이전 구현을 그대로 사용

void brutesearch(char *p, char *a) {
    int m = strlen(p), n = strlen(a), cnt = 0;
    vector<int> found_positions;
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            cnt++;
            if (a[i + j] != p[j]) break;
        }
        if (j == m) {
            found_positions.push_back(i);
        }
    }
    for (int pos : found_positions) {
        cout << pos << ", ";
    }
    cout << cnt << " (Brute-Force - 문자열의 시작 IDX들, 문자열 비교 횟수)" << '\n';
}

void kmpsearch(char *p, char *a) {
    int m = strlen(p), n = strlen(a), cnt = 0;
    vector<int> found_positions;
    initSP(p);
    for (int i = 0, j = -1; i < n; i++) {
        while ((j >= 0) && (p[j + 1] != a[i])) {
            j = SP[j];
            cnt++;
        }
        if (p[j + 1] == a[i]) {
            j++;
            cnt++;
        }
        if (j == m - 1) {
            found_positions.push_back(i - m + 1);
            j = SP[j];
        }
    }
    for (int pos : found_positions) {
        cout << pos << ", ";
    }
    cout << cnt << " (KMP - 문자열의 시작 IDX들, 문자열 비교 횟수)" << '\n';
}



int main() {
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);

    char *c_text = new char[text.length() + 1];
    char *c_pattern = new char[pattern.length() + 1];
    strcpy(c_text, text.c_str());
    strcpy(c_pattern, pattern.c_str());

    lp = new int[alphabet_count];
    skip = new int[pattern.length() + 1];
    SP = new int[pattern.length()];
    int cnt;
    BoyerMoore(c_pattern, c_text);
    
    brutesearch(c_pattern, c_text);
    kmpsearch(c_pattern, c_text);


    
    delete[] c_text;
    delete[] c_pattern;
    delete[] lp;
    delete[] skip;
    delete[] SP;

    return 0;
}
