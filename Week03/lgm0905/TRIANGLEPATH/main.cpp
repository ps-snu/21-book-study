#include <bits/stdc++.h>
#define M 100
using namespace std;
int tri[101][101];

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int N; cin >> N; 
        int dp[101][101]; memset(dp, 0, 101*101);
        for(int n = 1; n <= N; n++) {
            for (int i = 1; i <= n; i++) {
                int c; cin >> c;
                dp[n][i] = max(dp[n-1][i], dp[n-1][i-1]) + c;
            }
        }
        int res = -1;
        for(int i = 0; i <= N; i++) {
            res = max(res, dp[N][i]);
        }
        printf("%d\n", res);
    }
    return 0;
}