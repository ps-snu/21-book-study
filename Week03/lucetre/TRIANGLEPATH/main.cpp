#include <bits/stdc++.h>
#define M 100
using namespace std;
int a[M+5], d[M+5][M+5];

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int N, res = 0; cin >> N;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= i; j++) {
                cin >> a[j];
                d[i][j] = max(d[i-1][j-1], d[i-1][j]) + a[j];
                // cout << d[i][j] << " ";
                if (i == N) res = max(res, d[i][j]);
            }
            // cout << endl;
        }
        cout << res << endl;
    }
    return 0;
}