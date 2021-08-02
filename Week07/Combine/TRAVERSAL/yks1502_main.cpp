#include <bits/stdc++.h>
using namespace std;

int C, N, input;
vector<int> preorder, inorder, postorder;

class Node {
    public:
        int label;
        Node* left = NULL;
        Node* right = NULL;
        Node(int label) { this->label = label; }
};

Node* makeTree(vector<int> &pre, vector<int> &in) {
    if (pre.size() == 0) return NULL;
    if (pre.size() == 1) return new Node(pre[0]);

    Node *root = new Node(pre[0]);
    int leftSize = 0;
    vector<int> leftPre, rightPre, leftIn, rightIn;

    for (int i = 0; i < pre.size(); i++) {
        if (in[i] == pre[0]) break;
        leftSize++;
    }
    for (int i = 0; i < leftSize; i++) {
        leftPre.push_back(pre[i + 1]);
        leftIn.push_back(in[i]);
    }
    for (int i = leftSize + 1; i < pre.size(); i++) {
        rightPre.push_back(pre[i]);
        rightIn.push_back(in[i]);
    }

    root->left = makeTree(leftPre, leftIn);
    root->right = makeTree(rightPre, rightIn);
    return root;
}

void postOrder(Node* root) {
    if (root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    postorder.push_back(root->label);
}

int main() {
    cin >> C;
    for (int i = 0; i < C; i++) {
        cin >> N;
        preorder.clear();
        inorder.clear();
        postorder.clear();
        
        for (int j = 0; j < N; j++) {
            cin >> input;
            preorder.push_back(input);
        }
        for (int j = 0; j < N; j++) {
            cin >> input;
            inorder.push_back(input);
        }

        Node* root = makeTree(preorder, inorder);
        postOrder(root);

        for (int j = 0; j < N - 1; j++) {
            cout << postorder[j] << " ";
        }
        cout << postorder[N - 1] << endl;
    }
}