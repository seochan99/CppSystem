//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <algorithm>
//
//using namespace std;
//
//typedef int itemType;
//
//// qick Sort
//inline void swap(itemType a[], int i, int j) {
//    itemType t = a[i];
//    a[i] = a[j];
//    a[j] = t;
//}
//
//int partition(itemType a[], int l, int r, int &compareCnt, int &moveCnt) {
//    int i, j;
//    itemType v;
//    if (r > l) {
//        v = a[l];
//        i = l;
//        j = r + 1;
//        moveCnt++;
//        for (;;) {
//            while (a[++i] < v) {
//                compareCnt++;
//                if (i >= r) break;
//            }
//            while (a[--j] > v) {
//                compareCnt++;
//                if (j <= l) break;
//            }
//            if (i >= j) break;
//            swap(a, i, j);
//            moveCnt += 3;
//        }
//        swap(a, j, l);
//        moveCnt += 3;
//    }
//    return j;
//}
//
//
//
//void quicksort(itemType a[], int l, int r, int &compareCnt, int &moveCnt) {
//    int j;
//    if (r > l) {
//        j = partition(a, l, r, compareCnt, moveCnt);
//        quicksort(a, l, j - 1, compareCnt, moveCnt);
//        quicksort(a, j + 1, r, compareCnt, moveCnt);
//    }
//}
//
//int main() {
//    int N;
//    cin >> N;
//
//    // 데이터 배열 생성
//    int *A = new int[N];
//    int *B = new int[N];
//
//    // 배열 A 초기화 (내림차순)
//    for (int i = 0; i < N; i++) {
//        A[i] = N - i;
//    }
//
//    // 배열 B 초기화
//    int **a = new int *[N];
//
//    srand((unsigned)time(NULL));
//
//    for (int i = 0; i < N; i++) {
//        a[i] = new int[2];
//        a[i][0] = (1 + rand() % N);
//        a[i][1] = i;
//    }
//
//    // 정렬을 위한 간단한 비교 함수
//    auto cmp = [](const int *left, const int *right) {
//        return left[0] < right[0];
//    };
//
//    sort(a, a + N, cmp);
//
//    for (int i = 0; i < N; i++) {
//        B[i] = a[i][1] + 1;
//        delete[] a[i];
//    }
//    delete[] a;
//
//    int compareCnt_A = 0, moveCnt_A = 0, compareCnt_B = 0, moveCnt_B = 0;
//
//    // sort진행
//    quicksort(A, 0, N - 1, compareCnt_A, moveCnt_A);
//    quicksort(B, 0, N - 1, compareCnt_B, moveCnt_B);
//
//    // 결과 출력
//    cout << "SortedData_A: ";
//    for (int i = 0; i < min(N, 20); i++) {
//        cout << A[i] << " ";
//    }
//    cout << endl;
//
//    cout << "SortedData_B: ";
//    for (int i = 0; i < min(N, 20); i++) {
//        cout << B[i] << " ";
//    }
//    cout << endl;
//
//    cout << "Compare_Cnt_A: " << compareCnt_A << ", DataMove_Cnt_A: " << moveCnt_A << endl;
//    cout << "Compare_Cnt_B: " << compareCnt_B << ", DataMove_Cnt_B: " << moveCnt_B << endl;
//
//    delete[] A;
//    delete[] B;
//
//    return 0;
//}
