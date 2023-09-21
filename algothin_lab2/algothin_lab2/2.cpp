//#include <iostream>
//#include <sstream>
//using namespace std;
//
//
//// treenode 생성
//struct treeNode {
//    char info;
//    struct treeNode* l, * r;
//};
//
//typedef treeNode* itemType;
//
//// 스택생성
//class Stack {
//public:
//    Stack(int max = 100) : stack(new itemType[max]), p(0) {}
//    ~Stack() { delete[] stack; }
//    void push(itemType v) { stack[p++] = v; }
//    itemType pop() { return stack[--p]; }
//    int empty() { return p == 0; }
//
//private:
//    itemType* stack;
//    int p;
//};
//
//// 큐 생성
//class Queue {
//public:
//    Queue(int max = 100) : size(max), head(0), tail(0) { queue = new itemType[max]; }
//    ~Queue() { delete[] queue; }
//    void put(itemType v);
//    itemType get();
//    int empty();
//
//private:
//    itemType* queue;
//    int size;
//    int head;
//    int tail;
//};
//
//// 큐 : put
//void Queue::put(itemType v) {
//    queue[tail++] = v;
//    if (tail > size) tail = 0;
//}
//
//// 큐 : get
//itemType Queue::get() {
//    itemType t = queue[head++];
//    if (head > size) head = 0;
//    return t;
//}
//
//// 큐 : 비었는지
//int Queue::empty() { return head == tail; }
//
//// 방문
//void visit(struct treeNode* t) {
//    cout << t->info << " ";
//}
//
//// 순회
//void traverse(struct treeNode* t) {
//    Queue queue;
//    treeNode* z = nullptr;
//    queue.put(t);
//
//    while (!queue.empty()) {
//        t = queue.get(); visit(t);
//        if (t->l != z) queue.put(t->l);
//        if (t->r != z) queue.put(t->r);
//    }
//}
//
//
//// 메인
//int main() {
//    char c;
//    Stack stack(50);
//    treeNode* z = nullptr;
//    treeNode* x = nullptr;
//    treeNode* root = nullptr;
//
//        while((c= cin.get())!='\n')
//        {
//            while(c==' ') cin.get(c);
//            x = new treeNode;
//            x->info = c; x->l = z; x->r = z;
//            if(c=='+' || c=='*' || c=='-') { // 연산자를 만나면, 스택에서 두 노드를 팝하고 새 노드의 자식으로 설정
//                x->r = stack.pop();
//                x->l = stack.pop();
//            }
//            stack.push(x); // 새 노드를 스택에 푸시
//        }
//    
//    root = stack.pop(); // 마지막에 스택에 남은 요소가 수식 트리의 루트입니다.
//
//    traverse(root); // 생성된 트리를 레벨 순회
//    cout << endl;
//    return 0;
//}
