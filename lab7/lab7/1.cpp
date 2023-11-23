#include <iostream>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <random>

#define infoNIL 0
#define itemMIN -1
#define black 0
#define red 1

typedef int itemType;
typedef double infoType;
using namespace std;

int MAX;

class RBtree {
private:
    // 레드-블랙 트리 노드 구조체
    struct node {
        itemType key, tag;
        infoType Info;
        struct node* l, * r;
        node(itemType k, infoType i, itemType t, struct node* ll, struct node* rr) {
            key = k; Info = i; tag = t; l = ll; r = rr;
        }
    };
    struct node* head, * tail, * x, * p, * g, * gg, * z;

public:
    // 생성자
    RBtree(int max) {
        // NIL 노드 생성 (0 키 값, 정보 없음, 검정색, 자식 없음)
        z = new node(0, infoNIL, black, 0, 0);
        // NIL 노드의 왼쪽과 오른쪽 자식을 자기 자신(NIL)로 설정
        z->l = z; z->r = z;
        // 루트 노드 생성 (가장 작은 키 값, 정보 없음, 검정색, NIL 노드로 연결)
        head = new node(itemMIN, infoNIL, black, z, z);
        x = NULL; p = NULL; g = NULL; gg = NULL; // 초기화
        tail = NULL;
    }

    // 삽입 연산
    void insert(itemType k, infoType info, int& comp_cnt) {
        x = head; p = head; g = head;
        while (x != z) {
            comp_cnt++;
            gg = g; g = p; p = x;
            x = (k < x->key) ? x->l : x->r;
            if (x->l->tag && x->r->tag) split(k); // 더블 레드인 경우 분할 수행
        }
        x = new node(k, info, red, z, z);
        if (k < p->key) p->l = x; else p->r = x;
        split(k); head->r->tag = black; // 루트 노드는 검정색
    }

    // 회전 연산
    struct node* rotate(itemType k, struct node* y) {
        struct node* high, * low;
        high = (k < y->key) ? y->l : y->r;
        if (k < high->key) { low = high->l; high->l = low->r; low->r = high; }
        else { low = high->r; high->r = low->l; low->l = high; }
        if (k < y->key) y->l = low; else y->r = low;
        return low;
    }

    // 분할 연산
    void split(itemType k) {
        x->tag = red; x->l->tag = black; x->r->tag = black;
        if (p->tag == red) {
            g->tag = red;
            if (k < g->key != k < p->key) p = rotate(k, g);
            x = rotate(k, gg);
            x->tag = black;
        }
    }

    // 출력 함수
    void print();

    // 탐색 연산
    infoType search(itemType k, int& comp_cnt) {
        struct node* n = head->r;
        while (n != z) {
            comp_cnt++;
            if (k == n->key) {
                return n->Info;
            }
            n = (k < n->key) ? n->l : n->r;
        }
        return infoNIL; // 키를 찾지 못한 경우 정보 없음 반환
    }
};


class BST {
private:
    // BST의 노드를 위한 구조체 정의
    struct node {
        int key;       // 노드의 값
        double info;   // 노드에 저장될 수 있는 추가 정보
        node* l;       // 왼쪽 자식 노드를 가리키는 포인터
        node* r;       // 오른쪽 자식 노드를 가리키는 포인터

        // 노드 생성자
        node(int k, double i, struct node* ll, struct node* rr) {
            key = k;     // 키 값 설정
            info = i;    // 정보 값 설정
            l = ll;      // 왼쪽 자식 설정
            r = rr;      // 오른쪽 자식 설정
        }
    };

    // 'head'는 트리의 가장 상단 노드를 가리키며, 'z'는 노드가 없는 경우를 나타내는 더미 노드를 가리킴
    struct node* head, * z;

public:
    // 생성자
    BST(int max) {
        z = new node(NULL, infoNIL, NULL, NULL); // 'z'는 더미 노드로 초기화. 여기서 NULL은 노드가 없음을 의미.
        head = new node(itemMIN, infoNIL, z, z); // 'head'는 최소값을 가지며, 양쪽 자식으로 'z'를 가짐
    }

    // 소멸자
    ~BST() {
        // 'head'와 'z'에 할당된 메모리를 해제.
        delete head; // 'head'를 삭제.
        delete z;    // 'z'를 삭제.
    }

    // 이하 함수들은 각각 검색, 삽입, 출력 및 중위 순회를 위한 함수들
    void BSTsearch(int v, int& comp_cnt);
    void BSTinsert(int v, double info, int& comp_cnt);
    void print(node* n);
    void inorder(int* a, node* n, int& cnt);
    node* gethead() { return head; } // 'head' 노드에 대한 포인터를 반환하는 함수
};


// Red-Black 트리를 위한 함수
void RBtree::print() {
    queue<node*> q;  // 노드 포인터들을 저장하기 위한 큐
    q.push(head);    // 트리의 루트 노드를 큐에 푸시

    // 큐가 비어있지 않을 때까지 반복.
    while (!q.empty()) {
        int lvSize = q.size();  // 현재 레벨의 노드 수

        // 현재 레벨의 모든 노드를 순회
        for (int i = 0; i < lvSize; i++) {
            node* f = q.front(); // 큐의 맨 앞 노드를 가져옴
            q.pop();             // 그 노드를 큐에서 제거.
            // 자식 노드가 있다면 큐에 푸시.
            if (f->l != z) q.push(f->l);
            if (f->r != z) q.push(f->r);
            cout << f->key << ' ';  // 현재 노드의 키를 출력.
        }
        cout << '\n';  // 레벨이 바뀔 때 줄바꿈을 .
    }
}

// 이진 탐색 트리를 위한 검색 함수
void BST::BSTsearch(int v, int& comp_cnt) {
    struct node* x = head->r;  // 루트 노드로 시작.
    comp_cnt++;                // 비교 횟수를 1 증가시킴

    // 'x'가 'z'(더미 노드)가 아닐 때까지 반복.
    while (x != z) {
        if (v == x->key) {
            return; // 찾고자 하는 값이면 함수를 종료.
        }
        // 'v'가 현재 노드의 키보다 작으면 왼쪽, 크면 오른쪽으로 이동.
        x = (v < x->key) ? x->l : x->r;
        comp_cnt++; // 비교 횟수를 증가시킴
    }
}

// 이진 탐색 트리에 새로운 노드를 삽입하는 함수
void BST::BSTinsert(int v, double info, int& comp_cnt) {
    struct node* p, * x;
    p = head; // 'p'는 부모 노드를 가리키며, 처음에는 'head'를 가리
    x = head->r; // 'x'는 현재 노드를 가리키며, 처음에는 루트 노드를 가리킴
    // 삽입할 위치를 찾기 위해 트리를 내려감
    while (x != z) {
        p = x; // 'p'를 'x'로 업데이트.
        // 삽입할 값과 현재 노드의 키 값을 비교하여 왼쪽 혹은 오른쪽으로 이동.
        x = (v < x->key) ? x->l : x->r;
        comp_cnt++; // 비교 횟수를 증가시킴
    }
    // 새로운 노드를 생성하고 'x'에 할당.
    x = new node(v, info, z, z);
    comp_cnt++; // 비교 횟수를 증가시킴
    // 'p'의 자식으로 새 노드를 연결.
    if (v < p->key) p->l = x;
    else p->r = x;
}

// 이진 탐색 트리를 중위 순회하면서 노드의 키 값을 출력하는 함수
void BST::print(node* n) {
    if (n == z) return;  // 'n'이 'z'(더미 노드)라면 더 이상 진행하지 않고 반환.
    print(n->l);        // 왼쪽 서브트리를 중위 순회.
    cout << n->key << ' '; // 현재 노드의 키 값을 출력.
    print(n->r);        // 오른쪽 서브트리를 중위 순회.
}

// 이진 탐색 트리를 중위 순회하면서 노드의 키 값을 배열에 저장하는 함수
void BST::inorder(int* a, node* n, int& cnt) {
    if (n == z) return;  // 'n'이 'z'(더미 노드)라면 더 이상 진행하지 않고 반환.
    inorder(a, n->l, cnt); // 왼쪽 서브트리를 중위 순회.
    if (n != head) {       // 'head' 노드가 아니면 배열에 키 값을 저장.
        a[cnt] = n->key;
        cnt++;             // 배열 인덱스를 증가시킴
    }
    inorder(a, n->r, cnt); // 오른쪽 서브트리를 중위 순회.
}




// 주어진 2차원 배열을 첫 번째 열('0'번째 인덱스)의 값에 따라 삽입 정렬하는 함수
void sortby0(int** a, int n)
{
    int v, k;  // 임시 저장할 변수 선언
    // 배열을 순회하면서 각 원소를 적절한 위치에 삽입.
    for (int i = 1; i < n; i++)
    {
        v = a[i][0];  // 'v'에 현재 원소의 첫 번째 열 값을 저장.
        k = a[i][1];  // 'k'에 현재 원소의 두 번째 열 값을 저장.
        int j = i;    // 현재 인덱스를 'j'에 저장.

        // 삽입 위치를 찾을 때까지 이전 원소들을 뒤로 밀어냄
        while (j > 0)
        {
            if (a[j - 1][0] > v)  // 앞의 원소가 더 크면 교환.
            {
                a[j][0] = a[j - 1][0];
                a[j][1] = a[j - 1][1];
                j--;
            }
            else break;  // 삽입 위치를 찾으면 반복을 멈춤
        }
        // 찾은 위치에 현재 원소를 삽입.
        a[j][0] = v;
        a[j][1] = k;
    }
}

// 주어진 배열을 출력하는 함수
void printarr(int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';
}

// 메인 함수
int main()
{
    int* b;  // 정수 배열을 가리킬 포인터 선언
    int** k;  // 2차원 정수 배열을 가리킬 포인터 선언
    std::cout << "input : ";
    std::cin >> MAX;  // 사용자로부터 최대 크기를 입력받습니다.
    b = new int[MAX];  // b 배열 동적 할당
    k = new int* [MAX];  // k 배열 동적 할당

    srand(static_cast<unsigned>(time(NULL)));  // 난수 발생기 초기화
    // k 배열에 난수를 채우는 반복문
    for (int i = 0; i < MAX; i++)
    {
        k[i] = new int[2];  // 2차원 배열의 각 행에 대한 동적 할당
        k[i][0] = (1 + rand() % MAX);  // 첫 번째 열에 난수 할당
        k[i][1] = 1 + i;  // 두 번째 열에 순차적 값 할당
    }
    sortby0(k, MAX);  // k 배열을 첫 번째 열 기준으로 정렬.
    // 정렬된 순서를 b 배열에 저장.
    for (int i = 0; i < MAX; i++) b[i] = k[i][1];

    // BST와 RBtree를 선언하고 초기화하는 과정
    int input[3] = { 0, };
    int search[3] = { 0, };

    BST T1(MAX);  // 첫 번째 이진 탐색 트리 초기화
    // T1에 b 배열의 값을 삽입
    for (int i = 0; i < MAX; i++) T1.BSTinsert(b[i], 1, input[0]);
    // T1에서 각 숫자를 검색
    for (int i = 0; i < MAX; i++) T1.BSTsearch(i, search[0]);
    
    // 중위 순회를 통해 b 배열에 트리의 모든 값을 저장
    int cnt = 0;
    T1.inorder(b, T1.gethead(), cnt);

    // std::shuffle을 사용하여 배열 b를 무작위로 섞음
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(b, b + MAX, g);

    // 두 번째 BST 초기화 및 값 삽입
    BST T2(MAX);
    for (int i = 0; i < MAX; i++) T2.BSTinsert(b[i], 1, input[1]);
    for (int i = 0; i < MAX; i++) T2.BSTsearch(i, search[1]);

    // 레드-블랙 트리 초기화 및 값 삽입
    RBtree T3(MAX);
    for (int i = 0; i < MAX; i++) T3.insert(b[i], 1, input[2]);
    for (int i = 0; i < MAX; i++) if (T3.search(i, search[2])) {}

    // 각 트리의 구축 시 평균 비교 횟수를 출력
    std::cout << (double)input[0] / MAX << " (T1의 구축시  평균 비교 회수)" << '\n';
    std::cout << (double)input[1] / MAX << " (T2의 구축시  평균 비교 회수)" << '\n';
    std::cout << (double)input[2] / MAX << " (T3의 구축시  평균 비교 회수)" << '\n';
    std::cout << '\n';

    // 각 트리의 평균 탐색 비교 횟수를 출력
    std::cout << (double)search[0] / MAX << " (T1의 평균 탐색 비교 회수)" << '\n';
    std::cout << (double)search[1] / MAX << " (T2의 평균 탐색 비교 회수)" << '\n';
    std::cout << (double)search[2] / MAX << " (T3의 평균 탐색 비교 회수)" << '\n';

    return 0;  // 프로그램 종료
}
