#include <iostream>
#include <sstream>
using namespace std;

struct treeNode {
    char info; // 노드에 저장될 정보 (문자)
    struct treeNode* l, * r; // 왼쪽과 오른쪽 자식 노드를 가리키는 포인터
};

typedef treeNode* itemType;

class Stack {
public:
    Stack(int max = 100) : stack(new itemType[max]), p(0) {} // 생성자
    ~Stack() { delete[] stack; } // 소멸자
    void push(itemType v) { stack[p++] = v; } // 스택에 아이템을 푸시
    itemType pop() { return stack[--p]; } // 스택에서 아이템을 팝
    int empty() { return p == 0; } // 스택이 비어 있는지 확인

private:
    itemType* stack; // 스택 배열
    int p; // 스택 포인터
};

class Queue {
public:
    Queue(int max = 100) : size(max), head(0), tail(0) { queue = new itemType[max]; } // 생성자
    ~Queue() { delete[] queue; } // 소멸자
    void put(itemType v); // 큐에 아이템을 넣기
    itemType get(); // 큐에서 아이템 얻기
    int empty(); // 큐가 비어 있는지 확인
    int getSize() { return abs(tail - head); } // 현재 큐의 사이즈를 반환

private:
    itemType* queue; // 큐 배열
    int size; // 큐의 최대 크기
    int head; // 큐의 헤드 위치
    int tail; // 큐의 꼬리 위치
};

void Queue::put(itemType v) {
    queue[tail++] = v; // 아이템을 큐에 넣기
    if (tail > size) tail = 0; // 꼬리 위치가 큐의 최대 크기를 넘어서면 0으로 초기화
}

itemType Queue::get() {
    itemType t = queue[head++]; // 아이템을 큐에서 얻기
    if (head > size) head = 0; // 헤드 위치가 큐의 최대 크기를 넘어서면 0으로 초기화
    return t; // 아이템 반환
}

int Queue::empty() { return head == tail; } // 큐가 비어 있는지 확인

bool isValidInput(const string& input) {
    for(char c : input) {
        if(isalpha(c)) {  // 입력 문자열에 알파벳(피 연산자)이 있는지 확인
            return true; // 있으면 true 반환
        }
    }
    return false; // 없으면 false 반환
}

void findAndPrintLevel(treeNode* root, char target) {
    Queue queue;
    treeNode* z = nullptr; // null 포인터 초기화
    queue.put(root); // 루트 노드를 큐에 넣기
    int level = 1; // 레벨 초기화

    // 레벨 순회
    while (!queue.empty()) {
        int size = queue.getSize(); // 현재 큐의 크기 얻기
        for (int i = 0; i < size; ++i) {
            treeNode* t = queue.get(); // 노드를 큐에서 얻기
            if (t->info == target) { // 찾고자 하는 노드인지 확인
                cout << level << endl; // 레벨 출력
                return; // 함수 종료
            }
            if (t->l != z) queue.put(t->l); // 왼쪽 자식 노드를 큐에 넣기
            if (t->r != z) queue.put(t->r); // 오른쪽 자식 노드를 큐에 넣기
        }
        level++; // 레벨 증가
    }
    cout << "Not Found" << endl; // 찾지 못하면 "Not Found" 출력
}

// 표현식 트리 만들기
treeNode* buildExpressionTree(const string& input) {
    istringstream iss(input);
    char c;
    Stack stack(50);
    treeNode* z = nullptr;
    treeNode* x = nullptr;

    // 입력 스트림에서 문자 읽기
    while (iss >> c) {
        x = new treeNode; // 새 노드 생성
        x->info = c; x->l = z; x->r = z; // 노드 초기화
        if(c=='+' || c=='*' || c=='-') { // 연산자인 경우
            x->r = stack.pop(); // 오른쪽 자식을 스택에서 팝
            x->l = stack.pop(); // 왼쪽 자식을 스택에서 팝
        }
        stack.push(x); // 노드를 스택에 푸시
    }

    return stack.pop(); // 루트 노드 반환
}




int main() {
    string input;
    char target;

    getline(cin, input); // 입력 문자열 읽기
    cin >> target; // 찾고자 하는 문자 읽기
    
    // target이 연산자인지 확인
     if(target == '+' || target == '-' || target == '*') {
//         cout << "Invalid Target" << endl; // target이 연산자라면 "Invalid Target" 출력
         return 0; // 프로그램 종료
     }

    // 입력이 유효한지 확인
    if(!isValidInput(input)) {
        cout << "Not Found" << endl; // 유효하지 않으면 "Not Found" 출력
        return 0; // 프로그램 종료
    }

    treeNode* root = buildExpressionTree(input); // 표현식 트리 만들기
    findAndPrintLevel(root, target); // 레벨 찾아서 출력

    return 0; // 프로그램 종료
}
