#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <random>

using namespace std;

typedef int itemType;

class MAKE_HEAP {
private:
    itemType *a;
    int N;
    int compareCnt; // 데이터비교 연산회수
    int moveCnt;    // 자료이동 연산회수

public:
    MAKE_HEAP(int max) : compareCnt(0), moveCnt(0) {
        a = new itemType[max];
        N = 0;
    }
    
    ~MAKE_HEAP() {
        delete[] a;
    }
    
    int getCompareCnt() { return compareCnt; }
    int getMoveCnt() { return moveCnt; }

    void swap(itemType a[], int i, int j) {
        moveCnt += 3; // 3 times data movement for swap
        int temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }

    void MakeHeap(itemType a[], int Root, int LastNode) {
        int Parent, LeftSon, RightSon, Son;
        itemType RootValue;
        Parent = Root;
        RootValue = a[Root];
        LeftSon = 2*Parent + 1;
        RightSon = LeftSon + 1;

        while (LeftSon <= LastNode) {
            compareCnt++;  // Comparison count for if
            if (RightSon <= LastNode && a[LeftSon] < a[RightSon]) {
                Son = RightSon;
            } else {
                Son = LeftSon;
            }

            compareCnt++;  // Comparison count for if
            if (RootValue < a[Son]) {
                a[Parent] = a[Son];
                moveCnt++;   // Data movement for assignment
                Parent = Son;
                LeftSon = 2*Parent + 1;
                RightSon = LeftSon + 1;
            } else {
                break;
            }
        }
        a[Parent] = RootValue;
        moveCnt++;   // Data movement for assignment
    }

    void heapsort(itemType a[], int N) {
        for (int i = N/2 - 1; i >= 0; i--) {
            MakeHeap(a, i, N-1);
        }
        for (int i = N-1; i > 0; i--) {
            swap(a, 0, i);
            MakeHeap(a, 0, i-1);
        }
    }
};

void createDataArrays(int N, itemType* A, itemType* B, itemType* C) {
    // 배열 A 초기화 (내림차순)
    for(int i = 0; i < N; i++) {
        A[i] = N - i;
    }
    // 배열 B 초기화
    int** a = new int*[N];
    srand((unsigned)time(NULL));
    for(int i = 0; i < N; i++) {
        a[i] = new int[2];
        a[i][0] = (1 + rand() % N);
        a[i][1] = i;
    }

    // 정렬을 위한 간단한 비교 함수
    auto cmp = [](const int* left, const int* right) {
        return left[0] < right[0];
    };

    sort(a, a+N, cmp);

    for(int i = 0; i < N; i++) {
        B[i] = a[i][1] + 1;
        delete[] a[i];
    }
    delete[] a;

    
    for (int i = 0; i < N; i++) {
        C[i] = rand() % N + 1;
    }
}

int main() {
    int N;
    cin >> N;

    itemType *A = new itemType[N];
    itemType *B = new itemType[N];
    itemType *C = new itemType[N];

    createDataArrays(N, A, B, C);

    MAKE_HEAP heapA(N), heapB(N), heapC(N);

    heapA.heapsort(A, N);
    heapB.heapsort(B, N);
    heapC.heapsort(C, N);

    cout << "SortedData_A: ";
    for (int i = 0; i < min(20, N); i++) cout << A[i] << " ";
    cout << endl;

    cout << "SortedData_B: ";
    for (int i = 0; i < min(20, N); i++) cout << B[i] << " ";
    cout << endl;

    cout << "SortedData_C: ";
    for (int i = 0; i < min(20, N); i++) cout << C[i] << " ";
    cout << endl;

    cout << "Compare_Cnt_A: " << heapA.getCompareCnt() << ", DataMove_Cnt_A: " << heapA.getMoveCnt() << endl;
    cout << "Compare_Cnt_B: " << heapB.getCompareCnt() << ", DataMove_Cnt_B: " << heapB.getMoveCnt() << endl;
    cout << "Compare_Cnt_C: " << heapC.getCompareCnt() << ", DataMove_Cnt_C: " << heapC.getMoveCnt() << endl;

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
