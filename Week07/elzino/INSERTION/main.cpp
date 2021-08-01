#include <bits/stdc++.h>

using namespace std;

typedef int KeyType;

struct Node {
    KeyType key;
    int priority, size;
    Node *left, *right;
    Node(const KeyType& _key) : key(_key), priority(rand()),
        size(1), left(NULL), right(NULL) {}
    void setLeft(Node* newLeft) {left = newLeft; calcSize();}
    void setRight(Node* newRight) {right = newRight; calcSize();}
    void calcSize() {
        size = 1;
        if (left) size += left->size;
        if (right) size += right->size;
    }
};

pair<Node*, Node*> split(Node* root, KeyType key) {
    if (root == NULL) return {NULL, NULL};
    if (root->key < key) {
        auto result_pair = split(root->right, key);
        root->setRight(result_pair.first);
        return {root, result_pair.second};
    } else {
        auto result_pair = split(root->left, key);
        root->setLeft(result_pair.second);
        return {result_pair.first, root};
    }
}

Node* insert(Node* root, Node* node) {
    if (node == NULL) return root;
    if (root == NULL) return node;
    if (root->priority < node->priority) {
        auto result_pair = split(root, node->key);
        node->setLeft(result_pair.first);
        node->setRight(result_pair.second);
        return node;
    }
    if (root->key > node->key) {
        Node* subtree = insert(root->left, node);
        root->setLeft(subtree);
        return root;
    }
    Node* subtree = insert(root->right, node);
    root->setRight(subtree);
    return root;
}

Node* merge(Node* left, Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;
    if (left->priority > right->priority) {
        left->setRight(merge(left->right, right));
        return left;
    }
    right->setLeft(merge(left, right->left));
    return right;
}

Node* erase(Node* root, KeyType key) {
    if (root == NULL) return root;
    if (root->key == key) {
        Node* new_root = merge(root->left, root->right);
        delete root;
        return new_root;
    }
    if (root->key > key) {
        root->setLeft(erase(root->left, key));
    } else {
        root->setRight(erase(root->right, key));
    }
    return root;
}

Node* kth(Node* root, int k) {
    int left_num = 0;
    if (root->left != NULL) left_num = root->left->size;
    if (left_num + 1 == k) return root;
    else if (left_num >= k) return kth(root->left, k);
    return kth(root->right, k - left_num - 1);
}

int countLessThan(Node* root, int x) {
    if (root == NULL) return 0;
    if (root->key < x) {
        int result = 1;
        if (root->left != NULL) result += root->left->size;
        result += countLessThan(root->right, x);
        return result;
    }
    return countLessThan(root->left, x);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int N;
int inputs[50001];
int outputs[50001];

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> N;
        Node* root = NULL;
        for (int i = 1; i <= N; i++) {
            Node* node = new Node(i);
            root = insert(root, node);
            scanf("%d", &inputs[i]);
        }
        for (int i = N; i >= 1; i--) {
            int ith = i - inputs[i];
            Node* ithNode = kth(root, ith);
            outputs[i] = ithNode->key;
            root = erase(root, ithNode->key);
        }
        for (int i = 1; i <= N; i++) {
            printf("%d ", outputs[i]);
        }
        printf("\n");
    }
}
