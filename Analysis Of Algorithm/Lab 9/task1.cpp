#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* left;
    Node* right;
    Node(string val) {
        data = val;
        left = right = NULL;
    }
};

Node* createTree() {
    string rootVal;
    cout << "Enter root: ";
    cin >> rootVal;
    if (rootVal == "-1") return NULL;

    Node* root = new Node(rootVal);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        string l, r;
        cout << "Enter left child of " << curr->data << ": ";
        cin >> l;
        if (l != "-1") {
            curr->left = new Node(l);
            q.push(curr->left);
        }

        cout << "Enter right child of " << curr->data << ": ";
        cin >> r;
        if (r != "-1") {
            curr->right = new Node(r);
            q.push(curr->right);
        }
    }
    return root;
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    Node* root = createTree();
    cout << "Binary Tree (Preorder): ";
    preorder(root);
    cout << endl;
    return 0;
}
