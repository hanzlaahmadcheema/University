#include <iostream>
#include <queue>
#include <vector>
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

Node* createTree() {
    int rootVal;
    cout << "Enter root: ";
    cin >> rootVal;
    if (rootVal == -1) return NULL;

    Node* root = new Node(rootVal);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        int l, r;
        cout << "Enter left child of " << curr->data << ": ";
        cin >> l;
        if (l != -1) {
            curr->left = new Node(l);
            q.push(curr->left);
        }

        cout << "Enter right child of " << curr->data << ": ";
        cin >> r;
        if (r != -1) {
            curr->right = new Node(r);
            q.push(curr->right);
        }
    }
    return root;
}

void processNodes(Node* root, vector<int>& all, vector<int>& leaves, vector<int>& internal) {
    if (!root) return;
    all.push_back(root->data);
    if (!root->left && !root->right) {
        leaves.push_back(root->data);
    } else {
        internal.push_back(root->data);
    }
    processNodes(root->left, all, leaves, internal);
    processNodes(root->right, all, leaves, internal);
}

void printVector(const vector<int>& v) {
    cout << v.size();
    if (!v.empty()) {
        cout << " (";
        for (size_t i = 0; i < v.size(); ++i) {
            cout << v[i] << (i < v.size() - 1 ? ", " : "");
        }
        cout << ")";
    }
    cout << endl;
}

int main() {
    Node* root = createTree();
    
    vector<int> allNodes, leafNodes, internalNodes;
    processNodes(root, allNodes, leafNodes, internalNodes);

    cout << "Total Nodes: " << allNodes.size() << endl;
    cout << "Leaf Nodes: ";
    printVector(leafNodes);
    cout << "Internal Nodes: ";
    printVector(internalNodes);

    return 0;
}
