#include <iostream>
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

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

Node* search(Node* root, int val) {
    if (!root || root->data == val) return root;
    if (val < root->data) return search(root->left, val);
    return search(root->right, val);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int n, val;
    cout << "Enter number of nodes to insert: ";
    cin >> n;
    
    cout << "Insert into BST: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    int searchVal;
    cout << "Search for: ";
    cin >> searchVal;

    cout << "Inorder Traversal (sorted): ";
    inorder(root);
    cout << endl;

    if (search(root, searchVal)) {
        cout << "Element " << searchVal << " found in BST." << endl;
    } else {
        cout << "Element " << searchVal << " not found in BST." << endl;
    }

    return 0;
}
