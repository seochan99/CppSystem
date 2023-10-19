//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <algorithm>
//
//using namespace std;
//
//typedef int itemType;
//
//int Bubble(itemType *a, int &compareCnt, int &moveCnt)
//{
//    int temp;
//    compareCnt++;  // 비교 연산 횟수 증가
//    if (*(a - 1) > *a) {
//        moveCnt += 3; // 3번의 자료 이동 발생 (temp, a-1, a).
//        temp = *(a - 1);
//        *(a - 1) = *a;
//        *a = temp;
//        return true; // 정렬되지 않았음을 나타내는 true 반환
//    }
//    return false; // 이미 정렬되었음을 나타내는 false 반환
//}
//
//void bubbleSort(itemType a[], int n, int &compareCnt, int &moveCnt)
//{
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            compareCnt++; // 비교 연산 횟수 증가
//            if (a[j] > a[j + 1]) {
//                moveCnt += 3; // 3번의 자료 이동 발생 (temp, a[j], a[j + 1]).
//                int temp = a[j];
//                a[j] = a[j + 1];
//                a[j + 1] = temp;
//            }
//        }
//    }
//}
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
//    bubbleSort(A, N, compareCnt_A, moveCnt_A);
//    bubbleSort(B, N, compareCnt_B, moveCnt_B);
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
