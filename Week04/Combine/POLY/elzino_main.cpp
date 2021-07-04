#include <bits/stdc++.h>

using namespace std;

int N;
int dp[101][101];

int process(int n) {
    int& result = dp[n][0];
    if (result != -1) return result;
    process(n-1);
    dp[n][n] = 1;
    for(int i = 1; i <= n-1; i++) {
        int temp = 0;
        int k = n-i;
        for (int j = 1; j <= i; j++) {
            temp += dp[i][j] * (j + k -1);
            temp %= 10000000;
        }
        dp[n][k] = temp;
    }
    result = 0;
    for (int i = 1; i <= n; i++) {result += dp[n][i]; result %= 10000000;}
    return result;
}

int main()
{
    int C;
    cin >> C;
    memset(dp, -1, sizeof(dp));
    dp[1][0] = dp [1][1] = 1;
    for(int c = 0; c < C; c++) {
        cin >> N;
        cout << process(N) << endl;
    }
}
