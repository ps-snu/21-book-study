#include <bits/stdc++.h>
#define M 50
#define D_M 100
using namespace std;
int n, d, p, c, a[M+1][M+1], rowsum[M+1];
double dp[D_M+1][M+1];

double solve(int v) {
    for(int i = 0; i < n; i++) 
        dp[0][i] = 0;
    dp[0][p] = 1;

    for(int i = 1; i <= d; i++) {
        for(int j = 0; j < n; j++) {
            if(dp[i][j] != -1) continue;
            dp[i][j] = 0;
            for(int k = 0; k < n; k++) 
                dp[i][j] += (a[k][j] == 1) ? dp[i-1][k] / rowsum[k] : 0;
        }
    }
    return dp[d][v];
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        fill(&dp[0][0], &dp[D_M][M+1], -1);
        memset(rowsum, 0, sizeof(rowsum));
        cin >> n >> d >> p;
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
                rowsum[i] += a[i][j];
            }
        int C; cin >> C;
        for(int c = 0; c < C; c++) {
            int v; cin >> v;
            printf("%.8f ", solve(v));
        }
        cout << endl;
    }
}