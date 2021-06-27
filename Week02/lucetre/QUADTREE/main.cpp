#include <bits/stdc++.h>
using namespace std;
string tree;

string process(int lev) {
    if (lev >= tree.size()) return "";
    if (tree[lev] == 'b' || tree[lev] == 'w') return {tree[lev]};
    string t[4];
    for (int i = 0; i < 4; i++) {
        t[i] = process(1 + lev);
        lev += t[i].size();
    }
    return "x" + t[2] + t[3] + t[0] + t[1];
}

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> tree;
        cout << process(0) << endl;
    }
    return 0;
}