#include <bits/stdc++.h>
#define M 500
using namespace std;
int n, l, k, d[M+1], res[M+1];
long long dn[M+1];
vector<pair<int, int>> w; 

void getans(int seg, int idx) {
    if(k < 1) return;
    if(seg == l) {
        for(int i = 0 ; i < l; i++)
            cout << res[i] << " ";
        return;
    }

    for(int i = idx+1; i < n; i++) {
        if(d[w[i].second] != l-seg) continue;
        if(dn[w[i].second] < k && dn[w[i].second] != -1) {
            k -= dn[w[i].second]; continue;
        }
        res[seg] = w[i].first;
        getans(seg+1, i);
        break;
    }
}

void solve() {
    fill(d, d + sizeof(d)/sizeof(d[0]), 1);
    memset(dn, 0, sizeof(dn)); memset(res, 0, sizeof(res));
    for(int i = n-1; i > -1; i--) {
        for(int j = n-1; j > i; j--) 
            if(w[i].first < w[j].first) d[i] = max(d[i], d[j]+1);
        for(int j = n-1; j > i; j--) 
            if(d[i] == d[j]+1) {
                if(dn[j] == -1) {
                    dn[i] = -1; break;
                }
                dn[i] += dn[j];
                if(dn[i] > INT_MAX) dn[i] = -1;
            }
        if(dn[i] == 0) dn[i] = 1;
    }
    sort(w.begin(), w.end());

    l = *max_element(d, d + sizeof(d)/sizeof(d[0]));
    cout << l << endl;
    // for(int i = 0; i < n; i++) 
    //     cout << w[i].first << " " << w[i].second << " " << d[w[i].second] << " " <<  dn[w[i].second] << endl;
    getans(0, -1);
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        w.clear();
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            int in; cin >> in;
            w.push_back(make_pair(in, i));
        }
        solve();
        cout << endl;
    }
}