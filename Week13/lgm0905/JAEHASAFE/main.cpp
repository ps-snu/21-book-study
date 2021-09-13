#include <bits/stdc++.h>
#define M 50
using namespace std;
int N;

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

int kmpSearch(string a, string b) {
    int n = a.size(), m = b.size();
    vector<int> pi = getPartialMatch(b);
    int begin = 0, matched = 0;
    while(begin <= n-m) {
        if(matched < m && a[begin+matched] == b[matched]) {
            matched++;
            if(matched == m) return begin;
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

int solve(string original, string target, int isCounterClockWise) {
    int ret = 0;
    if(isCounterClockWise) return kmpSearch(original+original, target);
    else return kmpSearch(target+target, original);
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        int ret = 0;
        cin >> N;
        string original; cin >> original;
        for(int n = 0; n < N; n++) {
            string target; cin >> target;
            ret += solve(original, target, n%2);
            original = target;
        }
        cout << ret << endl;
    }
    return 0;
}