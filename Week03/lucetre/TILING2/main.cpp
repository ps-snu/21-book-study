#include <bits/stdc++.h>
#define M 100
#define MOD 1000000007
using namespace std;
int f[M+1];

int fibo(int n) {
    int& res = f[n];
    if (res) return res;
    return res = (fibo(n-1) + fibo(n-2))%MOD;
}

int main() {
    freopen("input.txt", "r", stdin);
    f[0] = f[1] = 1;
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int n; cin >> n;
        cout << fibo(n) << endl;
    }
    return 0;
}