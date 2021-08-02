#include <bits/stdc++.h>
using namespace std;

int C, N;
int x[100], y[100], r[100];

class Node {
    public:
        int x, y, r, height;
        vector<Node*> children;
        Node(int x, int y, int r) : x(x), y(y), r(r) {
            this->height = 0;
        }
};

bool contains(Node* parent, Node* child) {
    if (parent->r <= child->r) return false;

    int d_sq = (parent->x - child->x) * (parent->x - child->x)
        + (parent->y - child->y) * (parent->y - child->y);
    int r_sq = (parent->r - child->r) * (parent->r - child->r);

    return d_sq < r_sq;
}

void makeTree(Node* parent, Node* leaf) {
    for (Node* child : parent->children) {
        if (contains(child, leaf)) {
            makeTree(child, leaf);
            return;
        }
    }

    parent->children.push_back(leaf);
}

void calcHeight(Node* root) {
    if (root->children.size() == 0)
        return;

    for (Node* child : root->children)
        calcHeight(child);

    for (Node* child : root->children)
        root->height = max(root->height, child->height + 1);
}

int overCastle(Node* root) {
    int result = root->height;

    if (root->children.size() >= 2) {
        vector<int> heights;
        for (Node* child : root->children) {
            heights.push_back(child->height);
        }
        sort(heights.begin(), heights.end(), greater<int>());

        result = max(result, heights[0] + heights[1] + 2);
    }

    for (Node* child : root->children) {
        result = max(result, overCastle(child));
    }

    return result;
}

bool compare(Node* a, Node* b) {
    return a->r > b->r;
}

int main() {
    cin >> C;
    
    for (int i = 0; i < C; i++) {
        cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> x[j] >> y[j] >> r[j];
        }

        Node* root = new Node(x[0], y[0], r[0]);
        vector<Node*> nodes;
        for (int j = 1; j < N; j++) {
            Node* inner = new Node(x[j], y[j], r[j]);
            nodes.push_back(inner);
        }
        sort(nodes.begin(), nodes.end(), compare);
        for (Node* node : nodes)
            makeTree(root, node);

        calcHeight(root);
        int result = overCastle(root);

        cout << result << endl;
    }
}