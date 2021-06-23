#include <bits/stdc++.h>

using namespace std;

#define INF 987654321

int N, Q;
int inputs[101]; // starts from 1
int psum[101];   // starts from 1
int dp[101][11];

int squareError(int si, int ei) {
    double mean = (double)(psum[ei-1] - psum[si-1]) / (ei - si);
    int q = round(mean);
    int se = 0;
    for (int i = si; i < ei; i++) {
        se += (inputs[i] - q) * (inputs[i] - q);
    }
    return se;
}

int process(int si, int qn) {
    int& result = dp[si][qn];
    if (result != -1) return result;
    result = INF;
    if (qn == 1)
        return result = squareError(si, N+1);
    for (int ei = si+1; ei <= N-(qn-2); ei++) {
        result = min(result, squareError(si, ei) + process(ei, qn-1));
    }
    return result;
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> N >> Q;
        for (int i = 1; i <= N; i++) {
            cin >> inputs[i];
        }
        sort(inputs+1, inputs+N+1);
        psum[0] = 0;
        for (int i = 1; i <= N; i++) {
            psum[i] = psum[i-1] + inputs[i];
        }
        memset(dp, -1, sizeof(dp));
        int result = INF;
        for (int i = 1; i <= Q; i++) {
            result = min(result, process(1, i)); 
        }
        cout << result << endl;
    }
}
