#include <bits/stdc++.h>

using namespace std;


vector<int> getPartialMatchNaive(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);
    for (int  begin = 1; begin < m; begin++) {
        for (int i = 0; begin + i < m; i++) {
            if (N[begin+i] != N[i])
                break;
            pi[begin+i] = max(pi[begin+i], i+1);
        }
    }
    return pi;
}


vector<int> getPartialMatch(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while (begin + matched < m) {
        if (N[begin+matched] == N[matched]) {
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
    return pi;
}

vector<int> kmpSearch(const string& H, const string& N) {
    int n = H.size(), m = N.size();
    vector<int> ret;
    vector<int> pi = getPartialMatch(N);
    int begin = 0, matched = 0;
    while (begin <= n - m) {
        if (matched < m && H[begin+matched] == N[matched]) {
            matched++;
            if (matched == m)
                ret.push_back(begin);
        } else {
            if (matched == 0)
                begin++;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return ret;
}

void find_prefix_suffix(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);
    vector<int> ret;
    int begin = 1, matched = 0;
    while (begin + matched < m) {
        if (N[begin+matched] == N[matched]) {
            matched++;
            pi[begin+matched-1] = matched;

            if (begin+matched == m) {
                int temp = matched;
                while(temp > 0) {
                    ret.push_back(temp);
                    temp = pi[temp-1];
                }
                break;
            }

        } else {
            if (matched == 0)
                begin++;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    for (auto it = ret.rbegin(); it != ret.rend(); it++) {
        cout << *it << " ";
    }
    cout << m << " ";
}

int main() {
    string father, mother;
    cin >> father;
    cin >> mother;
    string concat_name = father + mother;
    find_prefix_suffix(concat_name);
}
