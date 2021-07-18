#include <bits/stdc++.h>
#define MOD 1000000007 
using namespace std;
string e, sorted_e;
int m, l, dp[1<<14][20][2];

int solve(int idx, int taken, int mod, int less) {
    if(idx == l) return (less && mod == 0) ? 1 : 0;

    int& ret = dp[taken][mod][less];
    if(ret != -1) return ret;

    for(int i = 0; i < l; i--) {
        if(taken & (1 << i) == 0) {
            if(!less && e[idx] <= sorted_e[i]) continue;
            
        }
    }
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> e >> m;
        sorted_e = e;
        sort(sorted_e.begin(), sorted_e.end());
        l = (int)sorted_e.size();
    }
    return 0;
}