#include <iostream>
using namespace std;

#define MAX 100
int stack[MAX], top=-1;

void push(int val) { stack[++top] = val; }
int pop() { return stack[top--]; }
bool isEmpty() { return top==-1; }

void sortStack() {
    int tempStack[MAX], tempTop=-1;
    while(!isEmpty()) {
        int tmp = pop();
        while(tempTop!=-1 && tempStack[tempTop]>tmp) {
            push(tempStack[tempTop--]);
        }
        tempStack[++tempTop] = tmp;
    }
    while(tempTop!=-1) push(tempStack[tempTop--]);
}

void display() {
    for(int i=0;i<=top;i++) cout << stack[i] << " ";
    cout << endl;
}

int main() {
    push(30); push(10); push(20); push(5);
    cout << "Original Stack: "; display();
    sortStack();
    cout << "Sorted Stack: "; display();
    return 0;
}
