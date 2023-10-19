//#include <iostream>
//#include <ctime>
//#include <algorithm>
//
//typedef int itemType;
//
//class CountingSorter {
//private:
//    int moveCnt;
//public:
//    CountingSorter(): moveCnt(0) {}
//
//    void CountSort(itemType *a, itemType *b, int *N, int n, int k) {
//        for(int i=0; i<=k; i++) N[i]=0;
//        for(int i=0; i<n; i++) N[a[i]]++;
//        
//        for(int i=1; i<=k; i++) N[i] += N[i-1];
//
//        for(int j=n-1; j>=0; j--) {
//            b[N[a[j]] - 1] = a[j];
//            moveCnt++;
//            N[a[j]]--;
//        }
//    }
//
//    int getMoveCnt() const {
//        return moveCnt;
//    }
//};
//
//void createDataArrays(int N, itemType* A, itemType* B, itemType* C) {
//    // 배열 A 초기화 (내림차순)
//    for(int i = 0; i < N; i++) {
//        A[i] = N - i;
//    }
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
//    std::sort(a, a+N, cmp);
//
//    for(int i = 0; i < N; i++) {
//        B[i] = a[i][1] + 1;
//        delete[] a[i];
//    }
//    delete[] a;
//
//    for (int i = 0; i < N; i++) {
//        C[i] = rand() % N + 1;
//    }
//}
//
//int main() {
//    int N;
//    std::cin >> N;
//
//    itemType *A = new itemType[N];
//    itemType *B = new itemType[N];
//    itemType *C = new itemType[N];
//    itemType *sortedA = new itemType[N];
//    itemType *sortedB = new itemType[N];
//    itemType *sortedC = new itemType[N];
//    int *countArr = new int[N + 1];
//
//    createDataArrays(N, A, B, C);
//
//    CountingSorter sorter;
//
//    sorter.CountSort(A, sortedA, countArr, N, N);
//    std::cout << "SortedData_A: ";
//    for(int i = 0; i < 20; i++) {
//        std::cout << sortedA[i] << " ";
//    }
//    std::cout << "\nDataMove_Cnt_A: " << sorter.getMoveCnt() << "\n";
//
//    sorter.CountSort(B, sortedB, countArr, N, N);
//    std::cout << "SortedData_B: ";
//    for(int i = 0; i < 20; i++) {
//        std::cout << sortedB[i] << " ";
//    }
//    std::cout << "\nDataMove_Cnt_B: " << sorter.getMoveCnt() << "\n";
//
//    sorter.CountSort(C, sortedC, countArr, N, N);
//    std::cout << "SortedData_C: ";
//    for(int i = 0; i < 20; i++) {
//        std::cout << sortedC[i] << " ";
//    }
//    std::cout << "\nDataMove_Cnt_C: " << sorter.getMoveCnt() << "\n";
//
//    delete[] A;
//    delete[] B;
//    delete[] C;
//    delete[] sortedA;
//    delete[] sortedB;
//    delete[] sortedC;
//    delete[] countArr;
//
//    return 0;
//}
