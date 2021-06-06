#include <bits/stdc++.h>
#define M 100
using namespace std;
int a[M+1], b[M+1];
int d[M+5][M+5];
int n, m;

int process(int prev, int ai, int bi) {
    int &res = d[ai+1][bi+1];
    if (res != -1) return res;
    res = 0;
    for (int i = ai+1; i < n; i++)
        if (prev < a[i])
            res = max(res, process(a[i], i, bi) + 1);
    for (int i = bi+1; i < m; i++)
        if (prev < b[i])
            res = max(res, process(b[i], ai, i) + 1);
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        memset(d, -1, sizeof(int)*(M+5)*(M+5));
        cout << process(INT_MIN, -1, -1) << endl;
    }
    return 0;
}