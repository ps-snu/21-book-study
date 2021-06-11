#include <bits/stdc++.h>
using namespace std;

int board[100][100];
int cache[100][100];

int jump(int r, int c, int n) {
    if (r == n - 1 && c == n - 1)
        return 1;
    
    int& ca = cache[r][c];
    if (ca != -1) return ca;

    int ret1 = -1;
    int ret2 = -1;
    int d = board[r][c];
    if (r + d < n) ret1 = jump(r + d, c, n);
    if (c + d < n) ret2 = jump(r, c + d, n);
    if (ret1 == 1 || ret2 == 1) return cache[r][c] = 1;
    return cache[r][c] = 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    int C, n;

    cin >> C;
    for (int i = 0; i < C; i++) {
        cin >> n;
        memset(cache, -1, sizeof(cache));
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                cin >> board[r][c];
            }
        }

        string ret = jump(0, 0, n) == 1 ? "YES" : "NO";
        cout << ret << endl;
    }
}