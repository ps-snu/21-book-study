#include <bits/stdc++.h>
#define MOD 10000000
#define M 100
using namespace std;
int P[M+1][M+1];
/*
0  1 2 3 4
1  1 0 0 0
2  1 1 0 0
3  3 2 1 0
4 10 5 3 1
*/

int main() {
    for (int i = 1; i <= M; i++) {
        P[i][i] = 1;
        for (int j = 1; j < i; j++)
            for (int k = 1; k <= i-j; k++)
                P[i][j] = (P[i][j] + (P[i-j][k] * (k+j-1)) % MOD) % MOD;
    }
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int n; cin >> n;
        int res = 0;
        for (int i = 1; i <= n; i++)
            res = (res + P[n][i]) % MOD;
        cout << res << endl;
    }
}