#include <bits/stdc++.h>
using namespace std;
string c;
int n, m;

int append(int here, int edge, int mod) {
    int there = here * 10 + edge;
    if(there >= mod) return mod + there % mod;
    return there % mod;
}

string solve() {
    sort(c.begin(), c.end());
    vector<int> v(2*n, -1), e(2*n, -1);
    queue<int> q;
    v[0] = 0;
    q.push(0);
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        for(auto cc : c) {
            int there = append(here, cc-'0', n);
            if(v[there] == -1) {
                v[there] = here;
                e[there] = cc-'0';
                q.push(there);
            }
        }
    }

    if(v[n+m] == -1) return "IMPOSSIBLE";

    string ret = "";
    int here = n+m;
    while(v[here] != here) {
        ret += (char)('0' + e[here]);
        here = v[here];
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> c >> n >> m;
        cout << solve() << endl;
    }
    return 0;
}