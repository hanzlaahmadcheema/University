#include <iostream>
using namespace std;

class Queue
{
private:
    int front, rear;
    char arr[100];

public:
    Queue()
    {
        front = 0;
        rear = -1;
    }

    bool isEmpty()
    {
        return front > rear;
    }

    bool isFull()
    {
        return rear == 99;
    }

    void enqueue(char ch)
    {
        if (isFull())
        {
            cout << "Queue Overflow\n";
            return;
        }
        arr[++rear] = ch;
    }

    char dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            return '\0';
        }
        return arr[front++];
    }

    int size()
    {
        return isEmpty() ? 0 : rear - front + 1;
    }

    char getAt(int i)
    {
        return arr[i];
    }
};

bool isPalindrome(const char str[])
{
    Queue q;
    int len = 0;

    while (str[len] != '\0')
    {
        q.enqueue(str[len]);
        len++;
    }

    for (int i = len - 1; i >= 0; i--)
    {
        char fromQueue = q.dequeue();
        if (fromQueue != str[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    char str[100];

    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str))
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
