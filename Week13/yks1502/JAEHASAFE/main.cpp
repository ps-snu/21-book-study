#include <bits/stdc++.h>
using namespace std;

int C, N;
string cur, nxt;

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

vector<int> kmp(const string &s, const string &f) {
    int n = s.size();
    int m = f.size();
    vector<int> pi = getPartialMatch(f);
    vector<int> result;

    int begin = 0, matched = 0;
    while (begin <= n - m) {
        if (matched < m && s[begin + matched] == f[matched]) {
            matched++;
            if (matched == m)
                result.push_back(begin);
        } else {
            if (matched == 0)
                begin++;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }

    return result;
}

int main() {
    cin >> C;
    for (int tc = 0; tc < C; tc++) {
        cin >> N >> cur;
        int len = cur.size();
        int result = 0;

        for (int n = 0; n < N; n++) {
            cin >> nxt;

            int turn;
            if (n % 2)
                turn = kmp(cur + cur, nxt)[0];
            else
                turn = kmp(nxt + nxt, cur)[0];
            result += turn;

            cur = nxt;
        }

        cout << result << endl;
    }
}