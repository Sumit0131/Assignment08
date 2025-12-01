#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int v) : val(v), left(NULL), right(NULL) {}
};

Node* insertNode(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->val) root->left = insertNode(root->left, key);
    else if (key > root->val) root->right = insertNode(root->right, key);
    return root;
}

Node* searchRec(Node* root, int key) {
    if (!root || root->val == key) return root;
    if (key < root->val) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

Node* searchIter(Node* root, int key) {
    while (root && root->val != key) {
        if (key < root->val) root = root->left;
        else root = root->right;
    }
    return root;
}

Node* minNode(Node* root) {
    if (!root) return NULL;
    while (root->left) root = root->left;
    return root;
}

Node* maxNode(Node* root) {
    if (!root) return NULL;
    while (root->right) root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* x) {
    if (x->right) return minNode(x->right);
    Node* succ = NULL;
    while (root) {
        if (x->val < root->val) {
            succ = root;
            root = root->left;
        } else if (x->val > root->val) {
            root = root->right;
        } else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* x) {
    if (x->left) return maxNode(x->left);
    Node* pred = NULL;
    while (root) {
        if (x->val > root->val) {
            pred = root;
            root = root->right;
        } else if (x->val < root->val) {
            root = root->left;
        } else break;
    }
    return pred;
}

int main() {
    Node* root = NULL;
    vector<int> v = {20,10,30,5,15,25,35};
    for (int x : v) root = insertNode(root, x);
    Node* s1 = searchRec(root, 15);
    Node* s2 = searchIter(root, 25);
    Node* mn = minNode(root);
    Node* mx = maxNode(root);
    Node* suc = inorderSuccessor(root, s1);
    Node* pre = inorderPredecessor(root, s1);
    return 0;
}
