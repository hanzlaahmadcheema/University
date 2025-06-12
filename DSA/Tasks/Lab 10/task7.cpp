
#include <iostream>
#include <vector>
#include <algorithm>
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


TreeNode* createBinaryTree() {
   
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    return root;
}


void storeInorder(TreeNode* root, vector<int>& vals) {
    if (!root) return;
    storeInorder(root->left, vals);
    vals.push_back(root->data);
    storeInorder(root->right, vals);
}


void assignInorder(TreeNode* root, vector<int>& vals, int& index) {
    if (!root) return;
    assignInorder(root->left, vals, index);
    root->data = vals[index++];
    assignInorder(root->right, vals, index);
}


void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    TreeNode* root = createBinaryTree();

    cout << "Original Binary Tree (Inorder): ";
    printInorder(root);
    cout << endl;

    vector<int> values;
    storeInorder(root, values);
    sort(values.begin(), values.end()); 

    int index = 0;
    assignInorder(root, values, index);

    cout << "Converted BST (Inorder): ";
    printInorder(root);
    cout << endl;

    return 0;
}
