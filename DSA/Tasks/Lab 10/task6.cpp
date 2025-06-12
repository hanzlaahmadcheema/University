
#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};


TreeNode* insert(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}


int findMin(TreeNode* root) {
    if (!root) return -1;
    while (root->left) root = root->left;
    return root->data;
}


int findMax(TreeNode* root) {
    if (!root) return -1;
    while (root->right) root = root->right;
    return root->data;
}

int main() {
    TreeNode* root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 10);
    root = insert(root, 90);

    cout << "Minimum value in BST: " << findMin(root) << endl;
    cout << "Maximum value in BST: " << findMax(root) << endl;

    return 0;
}
