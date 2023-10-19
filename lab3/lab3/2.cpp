//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <algorithm>
//
//using namespace std;
//
//typedef int itemType;
//
//// Shell Sort 함수
//void shellSort(int a[], int n, int &compareCnt, int &moveCnt) {
//    int i, j, h;
//    int v;
//    h = 1;
//    do {
//        h = 3 * h + 1;
//    } while (h < n);
//
//    do {
//        h = h / 3;
//        for (i = h; i < n; i++) {
//            v = a[i];
//            j = i;
//            while (j >= h) {
//                compareCnt++;
//
//                if (a[j - h] > v) {
//                    moveCnt++;
//                    a[j] = a[j - h];
//                    j -= h;
//                } else {
//                    break;
//                }
//            }
//            a[j] = v;
//            moveCnt++; // 데이터 이동이 발생할 때만 증가
//            moveCnt++; // 데이터 이동이 발생할 때만 증가
//        }
//
//    } while (h > 1);
//}
//
//
//
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
//    for(int i = 0; i < N; i++) {
//        A[i] = N - i;
//    }
//
//    // 배열 B 초기화
//    int** a = new int*[N];
//    srand((unsigned)time(NULL));
//    for(int i = 0; i < N; i++) {
//        a[i] = new int[2];
//        a[i][0] = (1 + rand() % N);
//        a[i][1] = i;
//    }
//
//    // 정렬을 위한 간단한 비교 함수
//    auto cmp = [](const int* left, const int* right) {
//        return left[0] < right[0];
//    };
//
//    sort(a, a+N, cmp);
//
//    for(int i = 0; i < N; i++) {
//        B[i] = a[i][1] + 1;
//        delete[] a[i];
//    }
//    delete[] a;
//
//    int compareCnt_A = 0, moveCnt_A = 0, compareCnt_B = 0, moveCnt_B = 0;
//
//    shellSort(A, N, compareCnt_A, moveCnt_A);
//    shellSort(B, N, compareCnt_B, moveCnt_B);
//
//    // 결과 출력
//    cout << "SortedData_A: ";
//    for(int i = 0; i < min(N, 20); i++) {
//        cout << A[i] << " ";
//    }
//    cout << endl;
//
//    cout << "SortedData_B: ";
//    for(int i = 0; i < min(N, 20); i++) {
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
