#include <bits/stdc++.h>
using namespace std;

vector<int> getPartialMatch(string N) {
    int m = N.size();
    vector<int> pi(m, 0);

    int begin = 1, matched = 0;
    while(begin+matched < m) {
        if(N[begin+matched] == N[matched]) {
            matched++;
            pi[begin+matched-1] = matched;
        }
        else {
            if(matched == 0) begin++;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}

int solve(string a) {
    string b = a;
    reverse(b.begin(), b.end());
    int n = a.size(); int m = b.size();
    vector<int> pi = getPartialMatch(b);

    int begin = 0, matched = 0;
    while(begin < n) {
        if(matched < m && a[begin+matched] == b[matched]) {
            matched++;
            if(begin+matched == n) return matched;
        }
        else {
            if(matched == 0) begin++;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return 0;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        string s; cin >> s;
        cout << 2 * s.size() - solve(s) << endl;
    }
    return 0;
}