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

int findMin(Node* root) {
    while (root && root->left) {
        root = root->left;
    }
    return root ? root->data : -1;
}

int findMax(Node* root) {
    while (root && root->right) {
        root = root->right;
    }
    return root ? root->data : -1;
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

    if (root) {
        cout << "Minimum element: " << findMin(root) << endl;
        cout << "Maximum element: " << findMax(root) << endl;
    } else {
        cout << "Tree is empty." << endl;
    }

    return 0;
}
