#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int capacity;
    int size;

    void resize(int newCapacity) {
        int* temp = new int[newCapacity];
        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        capacity = newCapacity;
    }

public:
    DynamicArray(int cap = 2) : capacity(cap), size(0) {
        arr = new int[capacity];
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void insert(int value) {
        if (size == capacity) {
            resize(capacity * 2); 
        }
        arr[size++] = value;
    }

    void remove() {
        if (size > 0) {
            size--;
            if (size < capacity / 4) {
                resize(capacity / 2); 
            }
        }
    }

    int get(int index) {
        if (index >= 0 && index < size) {
            return arr[index];
        }
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray arr;
    int choice, value, index;
    
    while (true) {
        cout << "\nMenu:\n1. Insert\n2. Remove\n3. Get Element\n4. Display\n5. Exit\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                arr.insert(value);
                break;
            case 2:
                arr.remove();
                cout << "Last element removed." << endl;
                break;
            case 3:
                cout << "Enter index: ";
                cin >> index;
                    cout << "Element at index " << index << ": " << arr.get(index) << endl;
                break;
            case 4:
                cout << "Array: ";
                arr.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
}