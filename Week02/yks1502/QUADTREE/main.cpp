#include <bits/stdc++.h>
using namespace std;

string reverse(const string& tree, int idx);

int main() {
    freopen("input.txt", "r", stdin);
    int C;
    cin >> C;
    string input;
    for (int i = 0; i < C; i++) {
        cin >> input;
        string result = reverse(input, 0);
        cout << result << endl;
    }
}

string reverse(const string& tree, int idx) {
    if (tree.at(idx) == 'b' || tree.at(idx) == 'w') {
        return string(1, tree.at(idx));
    }
    idx++;

    string quadTree[4];
    for (int i = 0; i < 4; i++) {
        quadTree[i] = reverse(tree, idx);
        idx += quadTree[i].length();
    }

    return 'x' + quadTree[2] + quadTree[3] + quadTree[0] + quadTree[1];
}