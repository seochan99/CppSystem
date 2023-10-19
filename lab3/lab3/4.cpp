#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

typedef int itemType;

int InsertionSortMoveSum(itemType a[], int n) {
    int moveSum = 0;
    for (int i = 1; i < n; i++) {
        itemType v = a[i];
        int j = i;
        while (j > 0 && a[j - 1] > v) {
            a[j] = a[j - 1];
            moveSum += a[j - 1];
            j--;
        }
        a[j] = v;
        if (i != j) moveSum += v;
    }
    return moveSum;
}

int BubbleSortMoveSum(itemType a[], int n) {
    int moveSum = 0;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        int currentMoveSum = 0; // 현재 패스에서의 움직임을 저장하기 위한 변수
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int light = min(a[j], a[j + 1]);
                int heavy = max(a[j], a[j + 1]);
                currentMoveSum += light * 2 + heavy; // 현재 교환의 움직임 누적
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        moveSum += currentMoveSum; // 현재 패스에서의 움직임을 전체 움직임에 누적
        if (!swapped) {
            break;
        }
    }
    return moveSum;
}


int ShellSortMoveSum(itemType a[], int n) {
    int moveSum = 0;
    int h = 1;
    do {
        h = 3 * h + 1;
    } while (h < n);

    do {
        h = h / 3;
        for (int i = h; i < n; i++) {
            itemType v = a[i];
            int j = i;
            while (j >= h && a[j - h] > v) {
                a[j] = a[j - h];
                moveSum += a[j - h];
                j -= h;
            }
            a[j] = v;
            if (i != j) moveSum += v;
        }
    } while (h > 1);
    return moveSum;
}

int main() {
    int N;
    cin >> N;

    int *A = new int[N];
    int *B = new int[N];
    int *C = new int[N];

    // 초기 배열 설정
    for (int i = 0; i < N; i++) {
        A[i] = N - i + 1;
        B[i] = N - i + 1;
        C[i] = N - i + 1;
    }

    // 각 정렬 방법별 이동 무게 합 계산
    int moveSumInsertion = InsertionSortMoveSum(A, N);
    int moveSumBubble = BubbleSortMoveSum(B, N);
    int moveSumShell = ShellSortMoveSum(C, N);

    // 결과 출력
    cout << "Insertion Sort : " << moveSumInsertion << endl;
    cout << "Bubble Sort : " << moveSumBubble << endl;
    cout << "Shell Sort : " << moveSumShell << endl;

    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
