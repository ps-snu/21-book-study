#include <bits/stdc++.h>
#define M 100
using namespace std;
int n, m, a[M+1], b[M+1], memo[M+1][M+1];

int solve(int ai, int bi) {
    int& ret = memo[ai][bi];
    if(ret != -1) return ret;
    ret = 0;
    int max_e = max(a[ai], b[bi]);
    for(int i = ai+1; i <= n; i++) {
        if(max_e < a[i]) ret = max(ret, solve(i, bi)+1);   
    }
    for(int i = bi+1; i <= m; i++) {
        if(max_e < b[i]) ret = max(ret, solve(ai, i)+1);
    }
    return ret;
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        memset(memo, -1, sizeof(memo));
        cin >> n >> m;
        a[0] = INT_MIN; b[0] = INT_MIN;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) cin >> b[i];

        printf("%d\n",solve(0,0));
    }
    return 0;
}