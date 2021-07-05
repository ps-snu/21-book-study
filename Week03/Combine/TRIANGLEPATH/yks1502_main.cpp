#include <bits/stdc++.h>
using namespace std;

int n;
int tri[100][100];
int cache[100][100];

int maxTri(int r, int c) {
    if (r == n - 1) return tri[r][c];
    int& ca = cache[r][c];
    if (ca != -1) return ca;
    ca = tri[r][c] + max(maxTri(r + 1, c), maxTri(r + 1, c + 1));
    return ca;
}

int main() {
    freopen("input.txt", "r", stdin);
    int C;
    cin >> C;
    for (int i = 0; i < C; i++) {
        cin >> n;
        memset(cache, -1, sizeof(cache));
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < r + 1; c++) {
                cin >> tri[r][c];
            }
        }
        cout << maxTri(0, 0) << endl;
    }
}