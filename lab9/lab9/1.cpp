#include <iostream>
#include <vector>
using namespace std;

class HeapConstructor {
private:
    int* array;
    int size;
public:
    HeapConstructor(int max) { array = new int[max]; size = 0; }
    ~HeapConstructor() { delete array; }
    void swap(vector<pair<char, float>>& angleArray, int i, int j)
    {
        pair<char, float> temp = angleArray[j];
        angleArray[j] = angleArray[i];
        angleArray[i] = temp;
    }

    void MakeHeap(vector<pair<char, float>>& angleArray, int root, int lastNode, int& compareCount, int& moveCount)
    {
        int parent, leftChild, rightChild, child;
        float rootValue;
        parent = root;
        rootValue = angleArray[root].second;
        pair<char, float> temp = angleArray[root];
        leftChild = 2 * parent + 1; 
        rightChild = leftChild + 1;
        compareCount++;
        while (leftChild <= lastNode) {
            compareCount++;
            if (rightChild <= lastNode && angleArray[leftChild].second < angleArray[rightChild].second) {
                child = rightChild;
            }
            else child = leftChild;

            compareCount++;
            if (rootValue < angleArray[child].second) {
                angleArray[parent] = angleArray[child];
                moveCount++;
                parent = child;
                leftChild = 2 * parent + 1;
                rightChild = leftChild + 1;
            }
            else break;
        }
        angleArray[parent] = temp;
        moveCount++;
    }
};

void heapSort(vector<pair<char, float>>& angleArray, int n, int& compareCount, int& moveCount) {
    HeapConstructor heap(n);
    for (int i = n / 2; i >= 0; i--) heap.MakeHeap(angleArray, i, n - 1, compareCount, moveCount);

    for (int i = n - 1; i >= 1; i--) {
        heap.swap(angleArray, 0, i);
        heap.MakeHeap(angleArray, 0, i - 1, compareCount, moveCount);
    }
}

struct Point {
    char name;
    int x, y;
    Point(char _name, int _x, int _y) {
        name = _name; x = _x; y = _y;
    }
};

struct Line { struct Point p1, p2; };
struct Point* polygon;

float ComputeAngle(struct Point p1, struct Point p2, int& count) {
    int dx, dy, ax, ay;
    float t;
    dx = p2.x - p1.x; ax = abs(dx);
    dy = p2.y - p1.y; ay = abs(dy);
    t = (ax + ay == 0) ? 0 : (float)dy / (ax + ay);
    if (dx < 0) t = 2 - t; else if (dy < 0) t = 4 + t;
    count++;
    return t * 90.0;
}

int main()
{
    int n;
    vector<Point> points;
    vector<pair<char, float>> angles; // char: 점의 이름, float: 각도
    Point* startPoint = new Point('s', 200, 200);

    cout << "점의 개수: ";
    cin >> n;
    char name;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> name >> x >> y;
        Point temp(name, x, y);
        if (startPoint->y > temp.y) *startPoint = temp;
        points.push_back(temp);
    }

    // y값이 가장 낮은 점을 기준점으로 설정
    int compareCount = 0, moveCount = 0, angleCount = 0;
    for (int i = 0; i < n; i++) {
        if (points[i].name == startPoint->name) continue;
        angles.push_back(make_pair(points[i].name, ComputeAngle(*startPoint, points[i], angleCount)));
    }

    heapSort(angles, n - 1, compareCount, moveCount);

    cout << "========결과=======" << '\n';

    cout << startPoint->name << ' ';
    for (int i = 0; i < n - 1; i++) {
        if (angles[i].first == startPoint->name) continue;
        cout << angles[i].first << ' ';
    }
    cout << '\n';
    cout << angleCount << " (수평각 계산 횟수)" << '\n';
    cout << compareCount << " (각의 비교 횟수)" << '\n';

    return 0;
}
