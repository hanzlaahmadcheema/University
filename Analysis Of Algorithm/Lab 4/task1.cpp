#include <iostream>
using namespace std;
struct Point {
    int x, y;
};
bool dominates(const Point &p1, const Point &p2) {
    return (p1.x >= p2.x && p1.y >= p2.y) && (p1.x > p2.x || p1.y > p2.y);
}
int main() {
    int n;
    cout << "Enter number of points: ";
    cin >> n;
    Point *points = new Point[n];
    cout << "Enter points (x y): \n";
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    bool *isMaximal = new bool[n];
    for (int i = 0; i < n; i++) {
        isMaximal[i] = true;
    }
    int comparisons = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                comparisons++;  
                if (dominates(points[j], points[i])) {
                    isMaximal[i] = false;
                    break;
                }
            }
        }
    }
    cout << "Maximal Points:\n";
    for (int i = 0; i < n; i++) {
        if (isMaximal[i]) {
            cout << "(" << points[i].x << ", " << points[i].y << ")\n";
        }
    }
    cout << "Total comparisons: " << comparisons << "\n";
    delete[] points;
    delete[] isMaximal;
    return 0;
}