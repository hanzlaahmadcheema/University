//Quick Sort 
#include <iostream>
using namespace std;

struct Patient {
    string id;
    int urgency;
};
int partition(Patient arr[], int low, int high) {
    int pivot = arr[high].urgency;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].urgency < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(Patient arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() {
    int n;
    cout << "Enter number of patients: ";
    cin >> n;
    Patient *p = new Patient[n];
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Patient " << i + 1 << ":\n";
        cout << "Enter Patient ID: ";
        cin >> p[i].id;
        cout << "Enter Urgency Score (lower = more critical): ";
        cin >> p[i].urgency;
    }
    quickSort(p, 0, n - 1);
    cout << "\n--- Sorted Patient Records (by urgency) ---\n";
    for (int i = 0; i < n; i++) {
        cout << "Patient ID: " << p[i].id
             << ", Urgency Score: " << p[i].urgency << endl;
    }
    cout << "Time Complexity: O(n log n)\n";
    delete[] p;
    return 0;
}