#include <bits/stdc++.h>
#define MOD 10000000
#define M 100
using namespace std;
int n; long d[M][M];

long solve() {
    int ret = 0;
    memset(d, 0, sizeof(d));
    d[1][1] = 1; d[2][1] = 1; d[2][2] = 1;
    for(int i = 3; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            for(int k = 1; k <= i-j; k++) {
                d[i][j] += (d[i-j][k] * (j+k-1)) % MOD;
            }
        }
        d[i][i] = 1;
    }
    for(int i = 1; i <= n; i++) {
        ret += d[n][i];
        ret %= MOD;
    }
    
    return ret;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> n;
        cout << solve() << endl;
    }
    return 0;
}