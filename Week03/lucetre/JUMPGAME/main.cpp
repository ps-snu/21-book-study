#include <bits/stdc++.h>
#define M 100
using namespace std;
int a[M+1][M+1], d[M+1][M+1];
int N;

string process() {
    d[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int k = i + a[i][j];
            if (k < N) d[k][j] += d[i][j];
            k = j + a[i][j];
            if (k < N) d[i][k] += d[i][j];
        }
    }
    return d[N-1][N-1] ? "YES" : "NO";
}

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                cin >> a[i][j];
                d[i][j] = 0;
            }
        cout << process() << endl;
    }

    return 0;
}