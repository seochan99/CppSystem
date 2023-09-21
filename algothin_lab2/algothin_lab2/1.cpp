//#include <iostream>
//using namespace std;
//
//struct treeNode {
//    char info;
//    struct treeNode *l, *r;
//};
//
//typedef treeNode* itemType;
//
//class Stack
//{
//    public:
//       Stack(int max=100) { stack=new itemType[max]; p=0; }; // 생성자에서 스택을 초기화
//       ~Stack() { delete[] stack; }; // 소멸자에서 스택 메모리를 해제
//       inline void push(itemType v) { stack[p++] = v; }; // 스택에 원소를 푸시
//       inline itemType pop() { return stack[--p]; }; // 스택에서 원소를 팝
//       inline int empty() { return p == 0; }; // 스택이 비어있는지 확인
//    private:
//       itemType *stack;
//       int p;
//};
//
//void visit(struct treeNode *t)
//{
//    cout << t->info << " "; // 노드 방문 시, 노드 정보 출력
//}
//
//void traverse(struct treeNode *t)
//{
//    if (t != nullptr)
//    {
//       traverse(t->l);  // 왼쪽 서브트리를 순회
//       visit(t);        // 현재 노드를 방문
//       traverse(t->r);  // 오른쪽 서브트리를 순회
//    }
//}
//
//int main()
//{
//    char c;
//    Stack stack(50);
//    treeNode *z = nullptr;
//    treeNode *x = nullptr;
//
//    while((c= cin.get())!='\n')
//    {
//        while(c==' ') cin.get(c);
//        x = new treeNode;
//        x->info = c; x->l = z; x->r = z;
//        if(c=='+' || c=='*' || c=='-') { // 연산자를 만나면, 스택에서 두 노드를 팝하고 새 노드의 자식으로 설정
//            x->r = stack.pop();
//            x->l = stack.pop();
//        }
//        stack.push(x); // 새 노드를 스택에 푸시
//    }
//
//    traverse(stack.pop()); // 생성된 트리를 중위 순회
//    cout << endl;
//    return 0;
//}
