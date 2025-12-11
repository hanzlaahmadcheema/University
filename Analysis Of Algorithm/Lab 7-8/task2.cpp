#include <iostream>
using namespace std;

struct Interval {
    double start;
    double end;
};

int main() {
    Interval appointments[5] = {
        {9, 10},
        {9.5, 11},
        {10, 10.5},
        {10.5, 11},
        {11, 12}
    };

    int n = 5;

    
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if (appointments[j].end > appointments[j+1].end) {
                Interval temp = appointments[j];
                appointments[j] = appointments[j+1];
                appointments[j+1] = temp;
            }
        }
    }

    cout << "Selected Schedule:" << endl;

    double lastEnd = 0;
    for(int i = 0; i < n; i++) {
        if (appointments[i].start >= lastEnd) {
            cout << "(" << appointments[i].start << ", " << appointments[i].end << ")" << endl;
            lastEnd = appointments[i].end;
        }
    }

    return 0;
}
