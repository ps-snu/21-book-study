#include <bits/stdc++.h>
#define M 100
#define C_M 1000000100
using namespace std;
int n, m, k, c[2*M+1][2*M+1];

void solve(int a, int b, string ret) {
    if(k < 0) return;
    if(a == 0 && b == 0) {
        if(k == 0) cout << ret << endl;
        k--;
        return;
    }
    if(c[a+b][a] <= k) {
        k -= c[a+b][a];
        return;
    }
    if(a > 0) solve(a-1, b, ret+'-');
    if(b > 0) solve(a, b-1, ret+'o');
}

int main() {
    for(int i = 0; i < 2*M+1; i++) 
        c[i][0] = c[i][i] = 1;
    for(int i = 1; i < 2*M+1; i++)
        for(int j = 1; j < i; j++) 
            c[i][j] = min(C_M, c[i-1][j-1] + c[i-1][j]);

    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> n >> m >> k;
        k -= 1;
        solve(n, m, "");
    }
    return 0;
}