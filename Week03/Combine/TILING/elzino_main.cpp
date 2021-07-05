#include <bits/stdc++.h>

using namespace std;

#define Q 1000000007;

int dp[101];

int process(int n) {
    int& result = dp[n];
    if (result != -1) return result;
    result = (process(n-1) + process(n-2)) % Q;
    return result;
}

int main() {
    int C;
    cin >> C;
    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    dp[2] = 2;
    for (int c = 0; c < C; c++) {
        int n;
        cin >> n;
        cout << process(n) << endl;
    }
}
