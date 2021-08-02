#include <bits/stdc++.h>
#define M 100
using namespace std;
int n, longest;
typedef struct Node {
    int x;
    int y;
    int r;
    vector<Node> ch;
} node;

bool isEnclose(node a, node b) {
    int sqrdist = (a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y);
    if(a.r > b.r && sqrdist < (a.r-b.r)*(a.r-b.r)) return true;
    return false;
}

void genTree(node& root, node& nd) {
    if(root.ch.empty()) {
        root.ch.push_back(nd);
        return;
    }

    bool isChild = false;
    int curIdx = 0;
    while(true) {
        if(curIdx == root.ch.size()) {
            root.ch.push_back(nd);
            break;
        }
        if(isEnclose(nd, root.ch[curIdx])) {
            nd.ch.push_back(root.ch[curIdx]);
            root.ch.erase(root.ch.begin() + curIdx);
            isChild = true;
        }
        else if(isEnclose(root.ch[curIdx], nd)) {
            genTree(root.ch[curIdx], nd);
            break;
        }
        else curIdx++;
    }
    return;
}

int heights(node head) {
    if(head.ch.empty()) return 0;

    vector<int> hei;
    for(auto v : head.ch) {
        hei.push_back(heights(v));
    }
    sort(hei.begin(), hei.end());
    if(hei.size() >= 2) {
        longest = max(longest, 2+hei[hei.size()-2]+hei[hei.size()-1]);
    }
    return hei.back() + 1;
}

void printTree(node head) {
    if(head.ch.empty()) return;
    cout << "root : " << head.x << " " << head.y << " " << head.r << endl;
    for(auto v : head.ch) 
        cout << v.x << " " << v.y << " " << v.r << endl;
    for(auto v : head.ch)
        printTree(v);
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        longest = 0;
        cin >> n;
        int x, y, r; cin >> x >> y >> r;
        node head; head.x = x; head.y = y; head.r = r;
        for(int i = 1; i < n; i++) {
            cin >> x >> y >> r; 
            node nd; nd.x = x; nd.y = y; nd.r = r;
            genTree(head, nd);
        }
        int h = heights(head);
        cout << max(longest, h) << endl;
    }
    return 0;
}