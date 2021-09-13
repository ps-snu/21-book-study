#include <bits/stdc++.h>
using namespace std;

string f, m;

int main() {
    cin >> f >> m;
    string fm = f + m;
    int len = fm.size();

    vector<int> v;
    vector<int> pi(len, 0);

    int begin = 1, matched = 0;
    while (begin + matched < len) {
        if (fm[begin + matched] == fm[matched]) {
            matched++;
            pi[begin + matched - 1] = matched;
        } else {
            if (matched == 0) begin++;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }

    while (len > 0) {
        v.push_back(len);
        len = pi[len - 1];
    }

    reverse(v.begin(), v.end());
    for (auto l : v)
        cout << l << " ";
    cout << endl;
}