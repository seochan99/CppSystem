#include <iostream>
#include <ctime>
#include <algorithm>

typedef int itemType;
typedef struct node *node_pointer;
typedef struct node {
    itemType value;
    node_pointer next;
};

node_pointer TABLE[10], x, z, temp;
int dataMoveCnt = 0;
int dataCompareCnt = 0;

void radixSort(itemType *a, int n) {
    int i,j, cnt, radix, radix_mod =10, cipher=0;
    i=n;
    while(i>0) { i=i/10; cipher++; }
    
    for(i=0; i<cipher; i++) {
        cnt=0;
        for(j=0; j<n; j++) {
            radix = (a[j] % radix_mod) / (radix_mod / 10);

            temp = new node;
            temp->value = a[j];
            temp->next = z;
            dataMoveCnt++;
            if(TABLE[radix] == z) {
                TABLE[radix]=temp;
            } else {
                x = TABLE[radix];
                while(x->next != z) {
                    x = x->next;
                    dataCompareCnt++;
                }
                x->next = temp;
            }
        }

        for(j=0; j<10; j++) {
            if(TABLE[j] != z) {
                x = TABLE[j];
                while(x != z) {
                    a[cnt++] = x->value;
                    temp = x;
                    x = x->next;
                    delete temp;
                }
            }
            TABLE[j] = z;
        }
        radix_mod *= 10;
    }
}

void createDataArrays(int N, itemType* A, itemType* B, itemType* C) {
    for(int i = 0; i < N; i++) {
        A[i] = N - i;
    }

    int** a = new int*[N];
    
    for(int i = 0; i < N; i++) {
        a[i] = new int[2];
        a[i][0] = (1 + rand() % N);
        a[i][1] = i;
    }

    auto cmp = [](const int* left, const int* right) {
        return left[0] < right[0];
    };

    std::sort(a, a+N, cmp);

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
    std::cin >> N;
    
    srand((unsigned)time(NULL));

    itemType *A = new itemType[N];
    itemType *B = new itemType[N];
    itemType *C = new itemType[N];

    z = new node{0, nullptr};
    for(int i = 0; i < 10; i++) {
        TABLE[i] = z;
    }

    createDataArrays(N, A, B, C);

    radixSort(A, N);
    std::cout << "SortedData_A: ";
    for(int i = 0; i < 20; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << "\nCompare_Cnt_A: " << dataCompareCnt << ", DataMove_Cnt_A: " << dataMoveCnt << "\n";

    dataMoveCnt = 0; dataCompareCnt = 0;
    radixSort(B, N);
    std::cout << "SortedData_B: ";
    for(int i = 0; i < 20; i++) {
        std::cout << B[i] << " ";
    }
    std::cout << "\nCompare_Cnt_B: " << dataCompareCnt << ", DataMove_Cnt_B: " << dataMoveCnt << "\n";

    dataMoveCnt = 0; dataCompareCnt = 0;
    radixSort(C, N);
    std::cout << "SortedData_C: ";
    for(int i = 0; i < 20; i++) {
        std::cout << C[i] << " ";
    }
    std::cout << "\nCompare_Cnt_C: " << dataCompareCnt << ", DataMove_Cnt_C: " << dataMoveCnt << "\n";

 
    delete z; // z 노드의 메모리를 해제
      delete[] A;
      delete[] B;
      delete[] C;


    return 0;
}
