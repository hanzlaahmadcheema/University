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

int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int treeHeight(Node* root) {
    if (!root) return 0;
    return 1 + max(treeHeight(root->left), treeHeight(root->right));
}

int main() {
    Node* binaryTree = new Node(1);
    binaryTree->left = new Node(2);
    binaryTree->right = new Node(3);
    binaryTree->left->left = new Node(4);
    binaryTree->left->right = new Node(5);

    cout << "\nTotal Nodes: " << countNodes(binaryTree) << endl;
    cout << "Leaf Nodes: " << countLeaves(binaryTree) << endl;
    cout << "Height: " << treeHeight(binaryTree) << endl;
    
    return 0;
}
