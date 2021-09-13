#include <bits/stdc++.h>
using namespace std;

string f, m;

int main() {
    cin >> f >> m;
    string fm = f + m;
    int len = fm.size();

    vector<int> v;
    for (int l = 1; l <= len; l++) {
        string pre = fm.substr(0, l);
        string suf = fm.substr(len - l, l);
        if (pre == suf) v.push_back(l);
    }

    for (auto l : v)
        cout << l << " ";
    cout << endl;
}