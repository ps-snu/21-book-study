#include<bits/stdc++.h>
#define M 50000
using namespace std;
int shifted[M+1], res[M+1];

struct Node {
    int key;
    int priority;
    int size;
    Node* left; 
    Node* right;
    Node(int Key) : key(Key), priority(rand()), size(1), left(NULL), right(NULL) {}
    void setLeft(Node* newLeft) {
        left = newLeft; calcSize();
    }
    void setRight(Node* newRight) {
        right = newRight; calcSize();
    }
    void calcSize() {
        size = 1;
        if(left) size += left->size;
        if(right) size += right->size;
    }
};
typedef pair<Node*, Node*> NodePair;

NodePair split(Node* root, int key) {
    if(root == NULL) return NodePair(NULL, NULL);
    if(root->key < key) {
        NodePair rs = split(root->right, key);
        root->setRight(rs.first);
        return NodePair(root, rs.second);
    }
    NodePair ls = split(root->left, key);
    root->setLeft(ls.second);
    return NodePair(ls.first, root);
}

Node* insert(Node* root, Node* node) {
    if(node == NULL) return root;
    if(root == NULL) return node;
    if(root->priority < node->priority) {
        NodePair splitted = split(root, node->key);
        node->setLeft(splitted.first);
        node->setRight(splitted.second);
        return node;
    }
    else if(node->key < root->key) 
        root->setLeft(insert(root->left, node));
    else 
        root->setRight(insert(root->right, node));
    return root;
}

Node* merge(Node* a, Node* b) {
    if(a == NULL) return b;
    if(b == NULL) return a;
    if(a->priority < b->priority) {
        b->setLeft(merge(a, b->left));
        return b;
    }
    a->setRight(merge(a->right, b));
    return a;
}

Node* erase(Node* root, int key) {
    if(root == NULL) return root;
    if(root->key == key) {
        Node* ret = merge(root->left, root->right);
        delete root;
        return ret;
    }
    if(key < root->key)
        root->setLeft(erase(root->left, key));
    else 
        root->setRight(erase(root->right, key));
    return root;
}

Node* kth(Node* root, int k) {
    int leftSize = 0;
    if(root->left != NULL) leftSize = root->left->size;
    if(k <= leftSize) return kth(root->left, k);
    if(k == leftSize+1) return root;
    return kth(root->right, k-leftSize-1);
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        memset(shifted, 0, sizeof(shifted));
        memset(res, 0, sizeof(res));
        int N; cin >> N;
        for(int i = 0; i < N; i++)
            cin >> shifted[i];
        Node* a = NULL;
        for(int i = 1; i <= N; i++) {
            a = insert(a, new Node(i));
        }
        for(int i = N-1; i >= 0; i--) {
            Node* k = kth(a, i+1-shifted[i]);
            res[i] = k->key;
            a = erase(a, res[i]);
        }
        for(int i = 0; i < N; i++) 
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}