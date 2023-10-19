#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

#define infoNIL 0
#define itemMIN -1

typedef int itemType;       // 노드의 키 타입 정의
typedef double infoType;    // 노드의 정보 타입 정의

class BST {
private:
    struct node {
        itemType key;         // 노드의 키
        infoType info;        // 노드의 정보
        struct node* l, * r;  // 왼쪽 서브트리와 오른쪽 서브트리를 가리키는 포인터
        node(itemType k, infoType i, struct node* ll, struct node* rr)
        { key = k; info = i; l = ll; r = rr; };
    };
    struct node* head, * z;   // 헤드 노드와 널 노드를 가리키는 포인터

public:
    // 생성자: BST 클래스 초기화
    BST(int max) {
        z = new node(0, infoNIL, 0, 0);  // 널 노드 초기화
        head = new node(itemMIN, infoNIL, z, z);  // 헤드 노드 초기화
    }

    // 소멸자: 트리 소멸
    ~BST() {
        destroyTree(head->r);
        delete z;
        delete head;
    }

    // 키를 이용한 탐색 함수
    infoType BSTsearch(itemType v) {
        struct node* x = head->r;  // 루트 노드부터 시작
        z->key = v;  // 키를 찾지 못했을 때 사용할 널 노드에 키 설정
        while (v != x->key) x = (v < x->key) ? x->l : x->r;  // 이진 탐색
        return x->info;  // 찾은 노드의 정보 반환
    }

    // 삽입 함수
    void BSTinsert(itemType v, infoType info) {
        struct node* p, * x;
        p = head;
        x = head->r;
        while (x != z) {  // 널 노드를 만날 때까지 이동
            p = x;
            x = (v < x->key) ? x->l : x->r;
        }
        x = new node(v, info, z, z);  // 새 노드 생성
        if (v < p->key) p->l = x; else p->r = x;  // 부모 노드와 연결
    }

    // 평균 비교 횟수 계산
    double averageComparisonCount() {
        int totalComparisons = 0;  // 전체 비교 횟수
        int nodeCount = 0;        // 노드 수
        computeAverageComparisonCount(head->r, 1, totalComparisons, nodeCount);
        if (nodeCount == 0) return 0;
        return static_cast<double>(totalComparisons) / nodeCount;
    }

    // Inorder 순회를 통해 데이터 수집
    void inorderTraversal(vector<itemType>& data) {
        data.clear();
        inorder(head->r, data);
    }

private:
    // 평균 비교 횟수 계산을 위한 재귀 함수
    void computeAverageComparisonCount(node* x, int depth, int& totalComparisons, int& nodeCount) {
        if (x == z) return;
        totalComparisons += depth;  // 현재 깊이를 전체 비교 횟수에 더함
        nodeCount++;               // 노드 수 증가
        computeAverageComparisonCount(x->l, depth + 1, totalComparisons, nodeCount);  // 왼쪽 서브트리 순회
        computeAverageComparisonCount(x->r, depth + 1, totalComparisons, nodeCount);  // 오른쪽 서브트리 순회
    }

    // 트리 소멸을 위한 재귀 함수
    void destroyTree(node* x) {
        if (x == z) return;
        destroyTree(x->l);
        destroyTree(x->r);
        delete x;
    }

    // Inorder 순회를 통해 데이터 수집하는 재귀 함수
    void inorder(node* x, vector<itemType>& data) {
        if (x == z) return;
        inorder(x->l, data);      // 왼쪽 서브트리 순회
        data.push_back(x->key);  // 노드의 키를 데이터에 추가
        inorder(x->r, data);      // 오른쪽 서브트리 순회
    }
};


int main() {
    int N;
    cin >> N;

    // 시드를 현재 시간으로 초기화
    srand(static_cast<unsigned int>(time(nullptr)));

    BST T1(N);  // 크기가 N인 BST T1 생성

    // 중복되지 않는 N개의 난수를 발생시켜 BST에 삽입
    for (int i = 0; i < N; i++) {
        itemType randomKey = rand() % 10000 + 100;      // 100부터 10099 사이의 난수 생성
        infoType randomInfo = static_cast<infoType>(rand() % 10000);  // 0부터 9999 사이의 난수 생성
        T1.BSTinsert(randomKey, randomInfo);  // 난수를 이용하여 BST T1에 노드 삽입
    }

    // Inorder 순회하여 데이터 재배치
    vector<itemType> data;
    T1.inorderTraversal(data);

    // 새로운 트리 T3 생성
    BST T3(N);

    // 데이터를 순서대로 T3에 삽입
    for (itemType key : data) {
        infoType randomInfo = static_cast<infoType>(rand() % 10000);  // 0부터 9999 사이의 난수 생성
        T3.BSTinsert(key, randomInfo);  // 데이터를 이용하여 BST T3에 노드 삽입
    }


    // 평균 비교 횟수 계산
    double avgComparisonCountT1 = T1.averageComparisonCount();
    double avgComparisonCountT3 = T3.averageComparisonCount();

    cout << " T1 :" << avgComparisonCountT1 << endl;
    cout << " T3 :" << avgComparisonCountT3  << endl;

    // T1과 T3의 비교
    if (avgComparisonCountT1 < avgComparisonCountT3) {
        cout << "T1이 T3보다 탐색 성능이 우수합니다." << endl;
    }
    else if (avgComparisonCountT1 > avgComparisonCountT3) {
        cout << "T3이 T1보다 탐색 성능이 우수합니다." << endl;
    }
    else {
        cout << "T1과 T3의 탐색 성능이 동일합니다." << endl;
    }

    return 0;
}
