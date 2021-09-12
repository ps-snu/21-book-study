#include <bits/stdc++.h>

using namespace std;

void getPartialMatch(const string &S) {
    int m = S.size();
    vector<int>pi(m, 0);
    int begin = 1, matched = 0;
    while (begin+matched < m) {
        if (matched < m/2 && S[begin+matched] == S[matched]) {
            matched++;
            pi[begin+matched-1] = matched;
        } else {
            if (matched == 0)
                begin++;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    cout << m - pi[m-1] << endl;
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        string S;
        cin >> S;
        string rS = S;
        reverse(rS.begin(), rS.end());
        string totalS = rS + S;
        getPartialMatch(totalS);
    }
}
