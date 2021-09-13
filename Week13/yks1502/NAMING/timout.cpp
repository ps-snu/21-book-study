#include <bits/stdc++.h>
using namespace std;

string f, m;

int main() {
    cin >> f >> m;
    string fm = f + m;
    int len = fm.size();

    vector<int> v;
    string pre, suf;
    for (int i = 0; i < len; i++) {
        pre += fm[i];
        suf += fm[len - i - 1];
        
        bool same = true;
        for (int j = 0; j < i + 1; j++) {
            if (pre[j] != suf[i - j]) {
                same = false;
                break;
            }
        }

        if (same) v.push_back(i + 1);
    }

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}