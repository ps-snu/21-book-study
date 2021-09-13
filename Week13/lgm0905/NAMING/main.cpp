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

int main() {
    string a, b;
    cin >> a >> b;
    vector<int> pi = getPartialMatch(a+b);
    vector<int> ret;
    int k = (a+b).size();
    while(k > 0) {
        ret.push_back(k);
        k = pi[k-1];
    }
    sort(ret.begin(), ret.end());
    for(int val : ret) 
        cout << val << " ";
    cout << endl;
    return 0;
}