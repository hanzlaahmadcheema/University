#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* insertBST(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insertBST(root->left, key);
    else
        root->right = insertBST(root->right, key);
    return root;
}

bool searchBST(Node* root, int key) {
    if (!root) return false;
    if (root->data == key) return true;
    if (key < root->data)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}

int main() {
    Node* bst = NULL;
    int keys[] = {10, 5, 1, 7, 15, 12, 18};
    for (int k : keys) bst = insertBST(bst, k);

    cout << "\nSearch 7 in BST: " << (searchBST(bst, 7) ? "Found" : "Not Found") << endl;
    return 0;
}
