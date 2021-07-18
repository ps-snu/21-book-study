#include <bits/stdc++.h>

using namespace std;

int bino[201][201];

void process(int n, int m, int k) {
    if (n == 0) {
        for (int i = 0; i < m; i++) cout << "o";
        return;
    }
    else if (m == 0) {
        for (int i = 0; i < n; i++) cout << "-";
        return;
    }
    int num = bino[n+m-1][m];
    if (num == -1 || num >= k) {
        cout << "-";
        process(n-1, m, k);
    }
    else {
        cout << "o";
        process(n, m-1, k-num);
    }
}

int main() {
    bino[0][0] = 1;
    for (int n = 1; n <= 200; n++) {
        bino[n][0] = 1;
        for (int k = 1; k <= n; k++) {
            if (bino[n-1][k-1] > 1000000000 || bino[n-1][k] > 1000000000 || bino[n-1][k-1] == -1 || bino[n-1][k] == -1)
                bino[n][k] = -1;
            else
                bino[n][k] = bino[n-1][k-1] + bino[n-1][k];
        }
    }

    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        int n, m, k;
        cin >> n >> m >> k;
        process(n, m, k);
        cout << endl;
    }
}
