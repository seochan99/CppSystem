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
//    struct node {
//        itemType key;
//        infoType info;
//        struct node* l, * r;
//        node(itemType k, infoType i, struct node* ll, struct node* rr)
//        { key = k; info = i; l = ll; r = rr; };
//    };
//    struct node* head, * z;
//
//public:
//    BST(int max) {
//        z = new node(0, infoNIL, 0, 0);
//        head = new node(itemMIN, infoNIL, z, z);
//    }
//
//    ~BST() {
//        destroyTree(head->r);
//        delete z;
//        delete head;
//    }
//
//    infoType BSTsearch(itemType v) {
//        struct node* x = head->r;
//        z->key = v;
//        while (v != x->key) x = (v < x->key) ? x->l : x->r;
//        return x->info;
//    }
//
//    void BSTinsert(itemType v, infoType info) {
//        struct node* p, * x;
//        p = head;
//        x = head->r;
//        while (x != z) { p = x; x = (v < x->key) ? x->l : x->r; }
//        x = new node(v, info, z, z);
//        if (v < p->key) p->l = x; else p->r = x;
//    }
//
//    void BSTdelete(itemType v) {
//        struct node* x = head->r, * p, * t, * c;
//        p = head;
//        while (x->key != v && x != z) {
//            p = x;
//            x = (v < x->key) ? x->l : x->r;
//        }
//        if (x == z) return;
//        else t = x;
//        if (t->r == z) x = t->l;
//        else if (t->r->l == z) {
//            x = t->r;
//            x->l = t->l;
//        }
//        else {
//            c = t->r;
//            while (c->l->l != z) c = c->l;
//            x = c->l;
//            c->l = x->r;
//            x->l = t->l;
//            x->r = t->r;
//        }
//        delete t;
//        if (v < p->key) p->l = x;
//        else p->r = x;
//    }
//
//    // 평균 비교 횟수를 계산하는 함수
//    double averageComparisonCount() {
//        int totalComparisons = 0;
//        int nodeCount = 0;
//        computeAverageComparisonCount(head->r, 1, totalComparisons, nodeCount);
//        if (nodeCount == 0) return 0;
//        return static_cast<double>(totalComparisons) / nodeCount;
//    }
//
//private:
//    void destroyTree(node* x) {
//        if (x == z) return;
//        destroyTree(x->l);
//        destroyTree(x->r);
//        delete x;
//    }
//
//    void computeAverageComparisonCount(node* x, int depth, int& totalComparisons, int& nodeCount) {
//        if (x == z) return;
//        totalComparisons += depth;
//        nodeCount++;
//        computeAverageComparisonCount(x->l, depth + 1, totalComparisons, nodeCount);
//        computeAverageComparisonCount(x->r, depth + 1, totalComparisons, nodeCount);
//    }
//};
//
//int main() {
//    int N;
//    cin >> N;
//
//    // 시드를 현재 시간으로 초기화
//    srand(static_cast<unsigned int>(time(nullptr)));
//
//    BST T2(N);
//
//    // 중복되지 않는 N개의 난수를 생성하여 BST에 삽입
//    for (int i = 0; i < N; i++) {
//        itemType randomKey = rand() % 10000 + 100;
//        infoType randomInfo = static_cast<infoType>(rand() % 10000);
//        T2.BSTinsert(randomKey, randomInfo);
//    }
//
//    // 평균 비교 횟수 계산
//    double avgComparisonCount = T2.averageComparisonCount();
//
//    // 배열 데이터를 순서대로 10개씩 불러들여 랜덤하게 삭제
//    for (int i = 0; i < N / 10; i++) {
//        int startIndex = i * 10;
//        int randomIndex = rand() % 10;
//        itemType keyToDelete = startIndex + randomIndex + 100;
//        T2.BSTdelete(keyToDelete);
//    }
//
//    // 다시 평균 비교 횟수 계산
//    avgComparisonCount = T2.averageComparisonCount();
//    cout << avgComparisonCount << endl;
//
//    return 0;
//}
