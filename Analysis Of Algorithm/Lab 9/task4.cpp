#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* createTree() {
    int rootVal;
    cout << "Enter root: ";
    cin >> rootVal;
    if (rootVal == -1) return NULL;

    Node* root = new Node(rootVal);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        int l, r;
        cout << "Enter left child of " << curr->data << ": ";
        cin >> l;
        if (l != -1) {
            curr->left = new Node(l);
            q.push(curr->left);
        }

        cout << "Enter right child of " << curr->data << ": ";
        cin >> r;
        if (r != -1) {
            curr->right = new Node(r);
            q.push(curr->right);
        }
    }
    return root;
}

int getHeight(Node* root) {
    if (!root) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

int main() {
    Node* root = createTree();
    cout << "Height of Tree = " << getHeight(root) << endl;
    return 0;
}
