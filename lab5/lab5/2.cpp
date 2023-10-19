#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

typedef int itemType;

void merge(itemType a[], int l, int mid, int r, int &compareCnt, int &moveCnt) {
    int i, j, k, n;
    int* sorted = new int[r - l + 1]; // 임시 배열 생성

    i = l;
    j = mid + 1;
    k = 0;

    while (i <= mid && j <= r) {
        compareCnt++; // 비교 횟수 증가

        if (a[i] <= a[j]) {
            sorted[k++] = a[i++];
        } else {
            sorted[k++] = a[j++];
        }

        moveCnt++; // 데이터 이동 횟수 증가
    }

    while (i <= mid) {
        sorted[k++] = a[i++];
        moveCnt++; // 데이터 이동 횟수 증가
    }

    while (j <= r) {
        sorted[k++] = a[j++];
        moveCnt++; // 데이터 이동 횟수 증가
    }

    // 임시 배열을 원래 배열로 복사
    for (n = l; n <= r; n++) {
        a[n] = sorted[n - l];
        moveCnt++; // 데이터 이동 횟수 증가
    }

    delete[] sorted; // 임시 배열 해제
}

void mergeSort(itemType a[], int l, int r, int &compareCnt, int &moveCnt) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(a, l, mid, compareCnt, moveCnt);
        mergeSort(a, mid + 1, r, compareCnt, moveCnt);
        merge(a, l, mid, r, compareCnt, moveCnt);
    }
}


int main() {
    int N;
    cin >> N;

    // 데이터 배열 생성
    int *A = new int[N];
    int *B = new int[N];

    // 배열 A 초기화 (내림차순)
    for (int i = 0; i < N; i++) {
        A[i] = N - i;
    }

    // 배열 B 초기화
    int **a = new int *[N];

    srand((unsigned)time(NULL));

    for (int i = 0; i < N; i++) {
        a[i] = new int[2];
        a[i][0] = (1 + rand() % N);
        a[i][1] = i;
    }

    // 정렬을 위한 간단한 비교 함수
    auto cmp = [](const int *left, const int *right) {
        return left[0] < right[0];
    };

    sort(a, a + N, cmp);

    for (int i = 0; i < N; i++) {
        B[i] = a[i][1] + 1;
        delete[] a[i];
    }
    delete[] a;

    int compareCnt_A = 0, moveCnt_A = 0, compareCnt_B = 0, moveCnt_B = 0;

    // Merge Sort 진행
    mergeSort(A, 0, N - 1, compareCnt_A, moveCnt_A);
    mergeSort(B, 0, N - 1, compareCnt_B, moveCnt_B);

    // 결과 출력
    cout << "SortedData_A: ";
    for (int i = 0; i < min(N, 20); i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "SortedData_B: ";
    for (int i = 0; i < min(N, 20); i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    cout << "Compare_Cnt_A: " << compareCnt_A << ", DataMove_Cnt_A: " << moveCnt_A << endl;
    cout << "Compare_Cnt_B: " << compareCnt_B << ", DataMove_Cnt_B: " << moveCnt_B << endl;

    delete[] A;
    delete[] B;

    return 0;
}
