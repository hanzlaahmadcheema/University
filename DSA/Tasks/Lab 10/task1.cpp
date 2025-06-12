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


Node* insertLevelOrder(vector<int>& values, int i) {
    if (i >= values.size() || values[i] == -1) return NULL;
    Node* root = new Node(values[i]);
    root->left = insertLevelOrder(values, 2 * i + 1);
    root->right = insertLevelOrder(values, 2 * i + 2);
    return root;
}


int main() {
    vector<int> levelOrder = {10, 5, 15, 2, 7, -1, 20}; 
    Node* binaryTree = insertLevelOrder(levelOrder, 0);
    
    return 0;
}
