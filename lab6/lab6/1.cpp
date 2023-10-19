//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//
//using namespace std;
//
//#define infoNIL 0
//#define itemMIN -1
//
//typedef int itemType;
//typedef double infoType;
//
//class BST {
//private:
//    // 노드 구조체 정의
//    struct node {
//        itemType key;         // 노드의 키
//        infoType info;        // 노드의 정보
//        struct node* l, * r;  // 왼쪽 자식과 오른쪽 자식 노드를 가리키는 포인터
//
//        // 노드 생성자: 키, 정보, 왼쪽 자식, 오른쪽 자식 초기화
//        node(itemType k, infoType i, struct node* ll, struct node* rr)
//        { key = k; info = i; l = ll; r = rr; };
//    };
//
//    struct node* head, * z;  // 더미 헤드 노드와 널 노드를 가리키는 포인터
//
//public:
//    // 생성자: 이진 탐색 트리 초기화
//    BST(int max) {
//        z = new node(0, infoNIL, 0, 0);             // 널 노드 초기화
//        head = new node(itemMIN, infoNIL, z, z);    // 더미 헤드 노드 초기화
//    }
//
//    // 소멸자: 이진 탐색 트리의 모든 노드 삭제
//    ~BST() {
//        destroyTree(head->r);  // 루트 노드부터 시작하여 트리 삭제
//        delete z;              // 널 노드 메모리 해제
//        delete head;           // 더미 헤드 노드 메모리 해제
//    }
//
//    // 키를 이용한 탐색 함수
//    infoType BSTsearch(itemType v) {
//        struct node* x = head->r;  // 루트 노드부터 시작
//        z->key = v;                // 키를 찾지 못했을 때 사용할 널 노드에 키 설정
//        while (v != x->key) {
//            x = (v < x->key) ? x->l : x->r;  // 이진 탐색 수행
//        }
//        return x->info;  // 찾은 노드의 정보 반환
//    }
//
//    // 삽입 함수
//    void BSTinsert(itemType v, infoType info) {
//        struct node* p, * x;
//        p = head;
//        x = head->r;
//        while (x != z) {
//            p = x;
//            x = (v < x->key) ? x->l : x->r;  // 올바른 위치까지 이동
//        }
//        x = new node(v, info, z, z);  // 새 노드 생성
//        if (v < p->key) {
//            p->l = x;  // 왼쪽 자식으로 연결
//        } else {
//            p->r = x;  // 오른쪽 자식으로 연결
//        }
//    }
//
//    // 평균 비교 횟수를 계산하는 함수
//    double averageComparisonCount() {
//        int totalComparisons = 0;  // 전체 비교 횟수
//        int nodeCount = 0;        // 노드 수
//        computeAverageComparisonCount(head->r, 1, totalComparisons, nodeCount);
//        if (nodeCount == 0) return 0;
//        return static_cast<double>(totalComparisons) / nodeCount;
//    }
//
//private:
//    // 평균 비교 횟수를 계산하는 재귀 함수
//    void computeAverageComparisonCount(node* x, int depth, int& totalComparisons, int& nodeCount) {
//        if (x == z) return;  // 널 노드인 경우 종료
//        totalComparisons += depth;  // 현재 깊이를 전체 비교 횟수에 더함
//        nodeCount++;               // 노드 수 증가
//        computeAverageComparisonCount(x->l, depth + 1, totalComparisons, nodeCount);  // 왼쪽 서브트리 순회
//        computeAverageComparisonCount(x->r, depth + 1, totalComparisons, nodeCount);  // 오른쪽 서브트리 순회
//    }
//
//    // 트리의 모든 노드를 삭제하는 재귀 함수
//    void destroyTree(node* x) {
//        if (x == z) return;  // 널 노드인 경우 종료
//        destroyTree(x->l);   // 왼쪽 서브트리 삭제
//        destroyTree(x->r);   // 오른쪽 서브트리 삭제
//        delete x;            // 노드 삭제
//    }
//};
//
//
//
//int main() {
//    int N;
//    cin >> N;
//
//    // 시드를 현재 시간으로 초기화
//    srand(static_cast<unsigned int>(time(nullptr)));
//
//    BST T1(N);
//
//    // 중복되지 않는 N개의 난수를 발생시켜 BST에 삽입
//    for (int i = 0; i < N; i++) {
//        itemType randomKey = rand() % 10000 + 100;
//        infoType randomInfo = static_cast<infoType>(rand() % 10000);
//        T1.BSTinsert(randomKey, randomInfo);
//    }
//
//    // 평균 비교 횟수 계산
//    double avgComparisonCount = T1.averageComparisonCount();
//    cout << avgComparisonCount << endl;
//
//    return 0;
//}
