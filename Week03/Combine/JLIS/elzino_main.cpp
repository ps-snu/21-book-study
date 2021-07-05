#include <bits/stdc++.h>

using namespace std;

int A[100];
int B[100];
int dp[101][101];

int N, M;

int JLIS(int ai, int bi) {
    int& result = dp[ai][bi];
    if (result != -1) return result;
    result = 0;
    int last_elem = max(A[ai], B[bi]);
    for (int i = ai+1; i <= N; i++)
        if (last_elem < A[i])
            result = max(result, JLIS(i, bi) + 1);
    for (int i = bi+1; i <= M; i++)
        if (last_elem < B[i])
            result = max(result, JLIS(ai, i) + 1);
    return result;
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> N >> M;
        A[0] = INT_MIN;
        B[0] = INT_MIN;
        for (int i = 1; i <= N; i++)
            cin >> A[i];
        for (int i = 1; i <= M; i++)
            cin >> B[i];
        memset(dp, -1, sizeof(dp));
        cout << JLIS(0, 0) << endl;
    }
}
