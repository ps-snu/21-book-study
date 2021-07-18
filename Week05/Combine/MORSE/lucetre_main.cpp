#include <bits/stdc++.h>
#define K 1000000000
#define M 200
using namespace std;
int n, m, k;
int C[M+1][M+1];

void process() {
    int l = n + m;
    for (int i = 0; i < l; i++) {
        int c = C[n+m-1][m];
        if (c < 0 || k <= c) {
            cout << "-";
            n--;
        }
        else {
            cout << "o";
            m--;
            k -= c;
        }
    }
    cout << endl;
}

int main() {
    C[0][0] = 1;
    for (int i = 1; i <= M; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            if (C[i-1][j] < 0 || C[i-1][j-1] < 0) C[i][j] = -1;
            else C[i][j] = (C[i-1][j] + C[i-1][j-1] > K) ? -1 : C[i-1][j] + C[i-1][j-1];
        }
    }
    
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n >> m >> k;
        process();
    }
    return 0;
}
