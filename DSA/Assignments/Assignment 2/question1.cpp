#include <iostream>
#include <vector>
using namespace std;

float findMedian(const vector<int>& class1, const vector<int>& class2) {
    int n = class1.size();
    int m = class2.size();
    int total = n + m;
    
    
    int i = 0, j = 0;
    int mid1 = -1, mid2 = -1;
    
    
    for (int count = 0; count <= total / 2; count++) {
        mid1 = mid2;
        
        
        if (i < n && (j >= m || class1[i] <= class2[j])) {
            mid2 = class1[i++];
        } else {
            mid2 = class2[j++];
        }
    }
    
    
    if (total % 2 != 0) {
        return mid2;
    }
    
    
    return (mid1 + mid2) / 2.0;
}

int main() {
    vector<int> class1 = {55, 70, 85};
    vector<int> class2 = {60, 75, 90, 100};
    
    float median = findMedian(class1, class2);
    
    cout << "Median: " << median << endl;
    
    return 0;
}