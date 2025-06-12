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
    Node* binaryTree = new Node(1);
    binaryTree->left = new Node(2);
    binaryTree->right = new Node(3);
    binaryTree->left->left = new Node(4);
    binaryTree->left->right = new Node(5);

    cout << "Inorder: "; inorder(binaryTree); cout << endl;
    cout << "Preorder: "; preorder(binaryTree); cout << endl;
    cout << "Postorder: "; postorder(binaryTree); cout << endl;

    return 0;
}
