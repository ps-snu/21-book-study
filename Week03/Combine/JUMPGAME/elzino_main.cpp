#include <bits/stdc++.h>

using namespace std;

int input[100][100];
int dp[100][100];
int N;

bool startJumping(int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= N) return false;
    if (i == N-1 && j == N-1) return true;
    int& ret = dp[i][j];
    if (ret != -1) return dp[i][j];
    int distance = input[i][j];
    ret = startJumping(i + distance, j) || startJumping(i, j + distance);
    return ret;
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> input[i][j];
            }
            memset(dp, -1, sizeof(dp));
        }
        if (startJumping(0, 0)) cout << "YES\n";
        else cout << "NO\n";
    }
}
