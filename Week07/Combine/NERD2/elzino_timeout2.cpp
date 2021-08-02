#include <bits/stdc++.h>

using namespace std;

int N;

struct Node {
    int value;
    int id;
    Node* left;
    Node* right;
};

Node* id2pnode[50000];
Node* id2qnode[50000];

void preorder_insert(Node* node, vector<int>& less) {
    if (node == NULL) return;
    less.push_back(node->id);
    preorder_insert(node->left, less);
    preorder_insert(node->right, less);
}

Node* insert_node(Node* root, Node* node, vector<int>& less) {
    if (root == NULL) return node;
    if (root->value > node->value)
        root->left = insert_node(root->left, node, less);
    else {
        if (root->value < node->value)
            less.push_back(root->id);
        preorder_insert(root->left, less);
        root->right = insert_node(root->right, node, less);
    }
    return root;
}

Node* combine_nodes(Node* left, Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;
    left->right = combine_nodes(left->right, right);
    return left;
}


Node* delete_node(Node* root, Node* node) {
    if (root == node) {
        Node* ptr = combine_nodes(root->left, root->right);
        delete root;
        return ptr;
    }
    if (root->value > node->value)
        root->left = delete_node(root->left, node);
    else {
        root->right = delete_node(root->right, node);
    }
    return root;
}


int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> N;
        int p, q;
        scanf("%d %d\n", &p, &q);
        Node* proot = new Node; Node* qroot = new Node;
        proot->value = p; proot->id = 0; proot->left = proot->right = NULL;
        qroot->value = q; qroot->id = 0; qroot->left = qroot->right = NULL;
        id2pnode[0] = proot; id2qnode[0] = qroot;
        int result = 1;
        int cur_part_num = 1;
        for (int i = 1; i < N; i++) {
            scanf("%d %d\n", &p, &q);
            Node* pnode = new Node; Node* qnode = new Node;
            pnode->value = p; pnode->id = i; pnode->left = pnode->right = NULL;
            qnode->value = q; qnode->id = i; qnode->left = qnode->right = NULL;
            id2pnode[i] = pnode; id2qnode[i] = qnode;
            vector<int> pless;
            vector<int> qless;
            proot = insert_node(proot, pnode, pless);
            qroot = insert_node(qroot, qnode, qless);
            cur_part_num += 1;
            vector<int> intersection;
            intersection.resize(pless.size()+qless.size());
            auto itr = set_intersection(pless.begin(), pless.end(), qless.begin(), qless.end(), intersection.begin());
            intersection.erase(itr, intersection.end());
            for (int id : intersection) {
                proot = delete_node(proot, id2pnode[id]);
                qroot = delete_node(qroot, id2qnode[id]);
                cur_part_num -= 1;
            }
            result += cur_part_num;
        }
        cout << result << endl;
    }
}
