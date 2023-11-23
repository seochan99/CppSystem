//#include <iostream>
//#include <vector>
//using namespace std;
//
//class HeapSort {
//private:
//    int* heapArray;
//    int heapSize;
//
//public:
//    HeapSort(int max) { heapArray = new int[max]; heapSize = 0; }
//    ~HeapSort() { delete heapArray; }
//
//    void swap(vector<pair<char, float>>& angles, int i, int j)
//    {
//        pair<char, float> temp;
//        temp = angles[j]; angles[j] = angles[i]; angles[i] = temp;
//    }
//
//    void heapify(vector<pair<char, float>>& angles, int root, int lastNode, int& comparisonCount, int& dataMoveCount)
//    {
//        int parent, leftChild, rightChild, child;
//        float rootValue;
//        parent = root;
//        rootValue = angles[root].second;
//        pair<char, float> temp = angles[root];
//        leftChild = 2 * parent + 1;
//        rightChild = leftChild + 1;
//        comparisonCount++;
//        while (leftChild <= lastNode) {
//            comparisonCount++;
//            if (rightChild <= lastNode && angles[leftChild].second < angles[rightChild].second) {
//                child = rightChild;
//            }
//            else {
//                child = leftChild;
//            }
//            comparisonCount++;
//            if (rootValue < angles[child].second) {
//                angles[parent] = angles[child];
//                dataMoveCount++;
//                parent = child;
//                leftChild = parent * 2 + 1;
//                rightChild = leftChild + 1;
//            }
//            else {
//                break;
//            }
//        }
//        angles[parent] = temp;
//        dataMoveCount++;
//    }
//};
//
//void heapSort(vector<pair<char, float>>& angles, int n, int& comparisonCount, int& dataMoveCount) {
//    HeapSort heap(n);
//    for (int i = n / 2; i >= 0; i--) heap.heapify(angles, i, n - 1, comparisonCount, dataMoveCount);
//
//    for (int i = n - 1; i >= 1; i--) {
//        heap.swap(angles, 0, i);
//        heap.heapify(angles, 0, i - 1, comparisonCount, dataMoveCount);
//    }
//}
//
//struct Point {
//    char name;
//    int x, y;
//
//    void initialize(char _name, int _x, int _y) {
//        name = _name;
//        x = _x;
//        y = _y;
//    }
//};
//
//struct Line {
//    Point point1, point2;
//};
//
//float computeAngle(Point p1, Point p2, int& count) {
//    int dx, dy, ax, ay;
//    float t;
//    dx = p2.x - p1.x; ax = abs(dx);
//    dy = p2.y - p1.y; ay = abs(dy);
//    t = (ax + ay == 0) ? 0 : (float)dy / (ax + ay);
//    if (dx < 0) t = 2 - t; else if (dy < 0) t = 4 + t;
//    count++;
//    return t * 90.0;
//}
//
//int direction(Point A, Point B, Point C) {
//    int dxAB, dxAC, dyAC, dyAB, dir;
//    dxAB = B.x - A.x; dyAB = B.y - A.y;
//    dxAC = C.x - A.x; dyAC = C.y - A.y;
//    if (dxAB * dyAB < dyAC * dxAC) dir = 1;
//    if (dxAB * dyAB > dyAC * dxAC) dir = -1;
//    if (dxAB * dyAB == dyAC * dxAC) {
//        if (dxAB == 0 && dyAB == 0) dir = 0;
//        if ((dxAB * dxAC < 0) || (dyAB * dyAC < 0)) {
//            dir = -1;
//        }
//        else if ((dxAB * dxAB + dyAB * dyAB) >= (dxAC * dxAC + dyAC * dyAC)) {
//            dir = 0;
//        }
//        else {
//            dir = 1;
//        }
//    }
//    return dir;
//}
//
//int intersection(Line AB, Line CD)
//{
//    int lineCrossing;
//    if ((direction(AB.point1, AB.point2, CD.point1) * direction(AB.point1, AB.point2, CD.point2) <= 0)
//        && (direction(CD.point1, CD.point2, AB.point1) * direction(CD.point1, CD.point2, AB.point2) <= 0)) {
//        lineCrossing = true;
//    }
//    else {
//        lineCrossing = false;
//    }
//    return lineCrossing;
//}
//
//int isPointInside(Point A, vector<Point> v, int n) {
//    int count = 0, lastPoint = 0, pointOnTestLine = 0;
//    Line testLine, polyLine;
//    testLine.point1 = A;
//    testLine.point2 = A;
//    testLine.point2.x = 200;
//
//    for (int i = 0; i < n; i++) {
//        polyLine.point1 = v[i];
//        polyLine.point2 = v[i];
//
//        if (intersection(testLine, polyLine)) pointOnTestLine = true;
//        else {
//            polyLine.point2 = v[lastPoint];
//            lastPoint = i;
//            if (!pointOnTestLine) {
//                if (intersection(testLine, polyLine)) count++;
//            }
//            else {
//                if (direction(testLine.point1, testLine.point2, polyLine.point1) * direction(testLine.point1, testLine.point2, polyLine.point2) < 0) {
//                    count++;
//                    pointOnTestLine = false;
//                }
//            }
//
//        }
//    }
//    return (count % 2 == 1);
//}
//
//int main()
//{
//    int n;
//    vector<Point> points;
//    vector<pair<char, float>> angles;
//    Point start;
//    start.initialize('s', 200, 200);
//
//    cout << "점의 개수, Z의 x좌표 값, Z의 y좌표 값: ";
//    cin >> n;
//    char name;
//    int x, y;
//    cin >> x >> y;
//    Point Z; Z.initialize('Z', x, y);
//
//    for (int i = 0; i < n; i++) {
//        cin >> name >> x >> y;
//        Point temp;
//        temp.initialize(name, x, y);
//        if (start.y > temp.y) start = temp;
//        points.push_back(temp);
//    }
//
//    int comparisonCount = 0, dataMoveCount = 0, angleCount = 0;
//    for (int i = 0; i < n; i++) {
//        if (points[i].name == start.name) continue;
//        angles.push_back(make_pair(points[i].name, computeAngle(start, points[i], angleCount)));
//    }
//
//    heapSort(angles, n - 1, comparisonCount, dataMoveCount);
//
//    cout << "========결과=======" << '\n';
//
//    cout << start.name << ' ';
//    for (int i = 0; i < n - 1; i++) {
//        if (angles[i].first == start.name) continue;
//        cout << angles[i].first << ' ';
//    }
//    cout << '\n';
//   cout << "=================" << '\n';
//    if (isPointInside(Z, points, n)) cout << "True" << '\n';
//    else cout << "False" << '\n';
//
//    return 0;
//}
