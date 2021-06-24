#include <bits/stdc++.h>
using namespace std;

int c, n, m;
long long A[101], B[101];
int cache[101][101];
set<long long> jl;

int jlis(int idxA, int idxB, set<long long> rst) {
    int& ca = cache[idxA + 1][idxB + 1];
    if (ca != -1) return ca;
    rst.insert(A[idxA]);
    rst.insert(B[idxB]);
    ca = rst.size();

    for (int i = idxA + 1; i <= n; i++) {
        if (A[idxA] < A[i]) {
            ca = max(ca, jlis(i, idxB, rst));
        }
    }
    for (int i = idxB + 1; i <= m; i++) {
        if (B[idxB] < B[i]) {
            ca = max(ca, jlis(idxA, i, rst));
        }
    }

    return ca;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> c;
    A[0] = LLONG_MIN;
    B[0] = LLONG_MIN;
    for (int i = 0; i < c; i++) {
        cin >> n >> m;
        for (int j = 0; j < n; j++) cin >> A[j + 1];
        for (int j = 0; j < m; j++) cin >> B[j + 1];

        memset(cache, -1, sizeof(cache));
        jl.clear();
        int res = jlis(0, 0, jl) - 1;
        cout << res << endl;
    }
}