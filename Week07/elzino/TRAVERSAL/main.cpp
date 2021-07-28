#include <bits/stdc++.h>

using namespace std;


int N;
int preorder[100];
int inorder[100];

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

int get_index(int *arr, int n, int v) {
    return find(arr, arr+n, v) - arr;
}

struct Node* build_tree(int pstart, int pend, int istart, int iend) {
    int num = pend - pstart + 1;
    if (num == 0) return NULL;
    int root_val = preorder[pstart];
    Node* root = new Node;
    root->value = root_val; root->left = NULL; root->right = NULL;
    if (num == 1) return root;
    int root_index = istart + get_index(inorder+istart, num, root_val);
    int left_num = root_index - istart;
    int right_num = iend - root_index;
    root->left = build_tree(pstart+1, pstart+left_num, istart, istart+left_num);
    root->right = build_tree(pstart+left_num+1, pend, root_index+1, iend);
    return root;
}

void preorder_t(Node* node) {
    if (node == NULL) return;
    cout << node->value << " ";
    preorder_t(node->left);
    preorder_t(node->right);
}

void inorder_t(Node* node) {
    if (node == NULL) return;
    inorder_t(node->left);
    cout << node->value << " ";
    inorder_t(node->right);
}

void postorder_t(Node* node) {
    if (node == NULL) return;
    postorder_t(node->left);
    postorder_t(node->right);
    cout << node->value << " ";
    delete node;
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> preorder[i];
        for (int i = 0; i < N; i++)
            cin >> inorder[i];
        Node* root = build_tree(0, N-1, 0, N-1);
        postorder_t(root);
        cout << endl;
    }
}
