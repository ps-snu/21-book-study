#include <bits/stdc++.h>
#define M 100
using namespace std;
int b[M+1][M+1], m[M+1][M+1];
int N;

int solve(int i, int j) {
    if(i >= N || j >= N) return 0;
    if(i == N-1 && j == N-1) return 1;
    if(m[i][j] != -1) return m[i][j];
    int jmp = b[i][j];
    m[i][j] = (solve(i+jmp, j) || solve(i, j+jmp)) ? 1 : 0;
    return m[i][j];
}

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> b[i][j];
                m[i][j] = -1;
            }
        }
        printf("%s\n", solve(0,0) ? "YES" : "NO");
    }

    return 0;
}