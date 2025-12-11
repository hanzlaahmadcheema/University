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

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = createTree();
    
    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    return 0;
}
