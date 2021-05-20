#include <bits/stdc++.h>
#define N 5
#define M 10
using namespace std;
char a[N+1][N+1];
int b[N+1][N+1][M+1];
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};

bool isPossible(string word, int y, int x, int lev) {
    if (lev >= word.size()) return true;
    if (y < 0 || x < 0 || y >= N || x >= N) return false;
    if (a[y][x] != word[lev]) return false;
    if (b[y][x][lev] != -1) return b[y][x][lev];
    for (int i = 0; i < 8; i++) {
        if (isPossible(word, y + dy[i], x + dx[i], lev+1)) {
            b[y][x][lev] = true;
            return true;
        }
    }
    b[y][x][lev] = false;
    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < N; i++)
            cin >> a[i];

        int W; cin >> W;
        for (int i = 0; i < W; i++) {
            string word;
            cin >> word;
            memset(b, -1, sizeof(b));
            bool flag = false;
            for (int y = 0; y < 5; y++) {
                for (int x = 0; x < 5; x++)
                    if (isPossible(word, y, x, 0)) {
                        flag = true;
                        break;
                    }
                if (flag) break;
            }
            cout << word << " " << (flag ? "YES" : "NO") << endl;
        }
    }

    return 0;
}