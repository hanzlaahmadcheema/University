#include <iostream>
using namespace std;

#define MAX 100
int arr[MAX];
int top1 = -1;
int top2 = MAX;

void push1(int val) {
    if(top1+1 == top2) { cout << "Stack Overflow\n"; return; }
    arr[++top1] = val;
}
void push2(int val) {
    if(top1+1 == top2) { cout << "Stack Overflow\n"; return; }
    arr[--top2] = val;
}
void pop1() { if(top1==-1) cout<<"Stack1 Empty\n"; else top1--; }
void pop2() { if(top2==MAX) cout<<"Stack2 Empty\n"; else top2++; }

void display() {
    cout<<"Stack1: "; for(int i=0;i<=top1;i++) cout<<arr[i]<<" "; cout<<endl;
    cout<<"Stack2: "; for(int i=MAX-1;i>=top2;i--) cout<<arr[i]<<" "; cout<<endl;
}

int main() {
    push1(10); push1(20); push2(30); push2(40);
    display();
    pop1(); pop2();
    display();
    return 0;
}
