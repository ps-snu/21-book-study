#include <bits/stdc++.h>
#define M 100
using namespace std;
struct TreeNode {
    vector<TreeNode*> children;
};

int y[M+1], x[M+1], r[M+1];
int n, res;

bool encloses(int p, int c) {
    if (r[p] <= r[c]) return false;
    double d = (y[p]-y[c])*(y[p]-y[c]) + (x[p]-x[c])*(x[p]-x[c]);
    return sqrt(d) < (r[p]-r[c]);
}

bool isChild(int p, int c) {
    if (! encloses(p, c))
        return false;
    for (int i = 0; i < n; i++)
        if (encloses(p, i) && encloses(i, c))
            return false;
    return true;
}

TreeNode* getTree(int root) {
    TreeNode* node = new TreeNode();
    for (int i = 0; i < n; i++)
        if (isChild(root, i))
            node->children.push_back(getTree(i));
    return node;
}

int process(TreeNode* root) {
    vector<int> h;
    for (auto child : root->children)
        h.push_back(process(child));
    if (h.empty()) return 0;
 
    sort(h.begin(), h.end(), greater<int>());
    if (h.size() > 1)
        res = max(res, h[0]+h[1]+2);
    return h[0]+1;
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> x[i] >> y[i] >> r[i];
        TreeNode* root = getTree(0);
        res = 0;
        cout << max(res, process(root)) << endl;
    }
    return 0;
}

