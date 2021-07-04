#include <bits/stdc++.h>
#define MOD 1000000007
#define M 100
using namespace std;
int F[M+1];

int main() {
    F[0] = F[1] = 1;
    for (int i = 2; i <= M; i++) F[i] = (F[i-1] + F[i-2]) % MOD;
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int n; cin >> n;
        int res = (F[n] - F[n/2] + MOD) % MOD;
        cout << (n%2 ? res : (res - F[n/2-1] + MOD) % MOD) << endl;
    }
    return 0;
}