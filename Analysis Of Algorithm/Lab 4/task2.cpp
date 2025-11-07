#include <iostream>
#include <algorithm>
using namespace std;


struct Point {
    int x, y;
};
bool compareByX(const Point &p1, const Point &p2) {
    return p1.x < p2.x;
}
int main() {
    int INT_MIN = -2147483648;
    int n;
    cout << "Enter number of points: ";
    cin >> n;
    Point *points = new Point[n];
    cout << "Enter points (x y): \n";
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    sort(points, points + n, compareByX);
    cout << "Sorted Points (by x asc):\n";
    for (int i = 0; i < n; i++) {
        cout << "(" << points[i].x << ", " << points[i].y << ")\n";
    }
    cout << "Maximal Points (Plane Sweep):\n";
    int maxY = INT_MIN;
    for (int i = n - 1; i >= 0; i--) {
        if (points[i].y >= maxY) {
            cout << "(" << points[i].x << ", " << points[i].y << ")\n";
            maxY = points[i].y;
        }   
    }
    delete[] points;
    return 0;
}
