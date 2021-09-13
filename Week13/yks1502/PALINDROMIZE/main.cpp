#include <bits/stdc++.h>
using namespace std;

int C;
string S, revS;

vector<int> getPartialMatch(const string &s) {
    int n = s.size();
    vector<int> pi(n, 0);

    int begin = 1, matched = 0;
    while (begin + matched < n) {
        if (s[begin + matched] == s[matched]) {
            matched++;
            pi[begin + matched - 1] = matched;
        } else {
            if (matched == 0)
                begin++;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }

    return pi;
}

int main() {
    cin >> C;
    for (int tc = 0; tc < C; tc++) {
        cin >> S;
        int len = S.size();
        revS = S;
        reverse(revS.begin(), revS.end());

        vector<int> pi = getPartialMatch(revS);

        int begin = 0, matched = 0;
        int overlap = 0;
        while (begin < len) {
            if (matched < len && S[begin + matched] == revS[matched]) {
                matched++;
                if (begin + matched == len) {
                    overlap = matched;
                    break;
                }
            } else {
                if (matched == 0) begin++;
                else {
                    begin += matched - pi[matched - 1];
                    matched = pi[matched - 1];
                }
            }
        }
        
        cout << 2 * len - overlap << endl;
    }
}