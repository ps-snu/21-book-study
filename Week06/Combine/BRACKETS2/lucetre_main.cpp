#include <bits/stdc++.h>
using namespace std;

bool process(string& s) {
    stack<char> S;
    for (auto c : s)
        if (c == '(' || c == '{' || c == '[')
            S.push(c);
        else
            if (!S.empty() && S.top()/10 == c/10) S.pop();
            else return false;
    return S.empty();
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        string s; cin >> s;
        cout << (process(s) ? "YES" : "NO") << endl;
    }
    return 0;
}
