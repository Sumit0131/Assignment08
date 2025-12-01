#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

bool isBSTUtil(Node* root, long long mn, long long mx) {
    if (!root) return true;
    if (root->val <= mn || root->val >= mx) return false;
    return isBSTUtil(root->left, mn, root->val) && isBSTUtil(root->right, root->val, mx);
}

bool isBST(Node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    bool ok = isBST(root);
    return 0;
}
