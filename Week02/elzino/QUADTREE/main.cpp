#include <bits/stdc++.h>

using namespace std;

string s;

string flip(int start_index) {
    if (s[start_index] != 'x') {
        return string(1, s[start_index]);
    }
    string quads[4];
    int index = start_index+1;
    for (int i = 0; i < 4; i++) {
        quads[i] = flip(index);
        index += quads[i].size();
    }
    return "x" + quads[2] + quads[3] + quads[0] + quads[1];
}

int main() {
    freopen("input.txt", "r", stdin);
    int c;
    cin >> c;
    for (int w = 0; w < c; w++) {
        cin >> s;
        cout << flip(0) << endl;
    }
}
