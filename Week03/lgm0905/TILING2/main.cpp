#include <bits/stdc++.h>
#define M 100
#define MOD 1000000007
using namespace std;
int d[M+1], n;

void solve() {
    d[1] = 1; d[2] = 2;
    for(int i = 3; i <= n; i++) {
        d[i] = (d[i-1] + d[i-2]) % MOD;
    }
    printf("%d\n", d[n]);
}

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        solve();
    }
    return 0;
}