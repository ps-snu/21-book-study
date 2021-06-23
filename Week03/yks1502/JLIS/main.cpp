#include <bits/stdc++.h>
using namespace std;

int c, n, m;
<<<<<<< HEAD
long long A[100], B[100];
int cacheA[100], cacheB[100];
int fpA[101], fpB[101];
int idxA, idxB, maxRst;
set<long long> result;
bool bA[100], bB[100];
set<long long> tmp;

int lisN(int idx) {
    if (idx == n - 1) return 1;

    int& ca = cacheA[idx];
    if (ca != -1) return ca;
    ca = 1;
    for (int i = idx + 1; i < n; i++) {
        if (A[idx] < A[i]) {
            if (ca < 1 + lisN(i)) {
                ca = 1 + lisN(i);
                fpA[idx] = i;
            }
        }
    }
    return ca;
}

int lisM(int idx) {
    if (idx == m - 1) return 1;

    int& ca = cacheB[idx];
    if (ca != -1) return ca;
    ca = 1;
    for (int i = idx + 1; i < m; i++) {
        if (B[idx] < B[i]) {
            if (ca < 1 + lisM(i)) {
                ca = 1 + lisM(i);
                fpB[idx] = i;
            }
        }
    }
=======
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

>>>>>>> fde6cb7b3208e64e090b97f20b8791093ca4c155
    return ca;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> c;
<<<<<<< HEAD
    for (int i = 0; i < c; i++) {
        cin >> n >> m;
        for (int j = 0; j < n; j++) {
            cin >> A[j];
        }
        for (int j = 0; j < m; j++) {
            cin >> B[j];
        }
        memset(cacheA, -1, sizeof(cacheA));
        memset(cacheB, -1, sizeof(cacheB));
        memset(fpA, -1, sizeof(fpA));
        memset(fpB, -1, sizeof(fpB));

        for (int j = 0; j < n; j++) lisN(j);
        for (int j = 0; j < m; j++) lisM(j);

        memset(bA, false, sizeof(bA));
        maxRst = 0;
        for (int j = 0; j < n; j++) {
            memset(bB, false, sizeof(bB));
            if (!bA[j]) {
                for (int k = 0; k < m; k++) {
                    if (!bB[k]) {
                        result.clear();
                        idxA = j; idxB = k;
                        while (idxA != -1) {
                            result.insert(A[idxA]);
                            bA[idxA] = true;
                            idxA = fpA[idxA];
                        }
                        while (idxB != -1) {
                            result.insert(B[idxB]);
                            bB[idxB] = true;
                            idxB = fpB[idxB];
                        }
                        int tmpRst = result.size();
                        if (maxRst < tmpRst) {
                            tmp = result;
                            maxRst = tmpRst;
                        }
                        //maxRst = max(maxRst, tmpRst);
                    }
                }
            }
        }
        cout << i << ": " << endl;
        set<long long>::iterator iter;
        for (iter = tmp.begin(); iter != tmp.end(); iter++) {
            cout << *iter << " ";
        }
        cout << endl;
        cout << maxRst << endl;
        cout << endl;
=======
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
>>>>>>> fde6cb7b3208e64e090b97f20b8791093ca4c155
    }
}