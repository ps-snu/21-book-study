#include <bits/stdc++.h>
#define M 100
using namespace std;
int n, a[M][M], d[M][M], p[M][M];

int solve() {
    d[0][0] = a[0][0]; p[0][0] = 1;
    for(int i = 1; i < n; i++) {
        d[i][0] = d[i-1][0] + a[i][0]; p[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            d[i][j] = max(d[i-1][j-1] + a[i][j],  d[i-1][j] + a[i][j]);
            if(d[i-1][j-1] == d[i-1][j]) p[i][j] = p[i-1][j-1] + p[i-1][j];
            else if(d[i-1][j-1] > d[i-1][j]) p[i][j] = p[i-1][j-1];
            else p[i][j] = p[i-1][j];
        }
    }
    int m = 0, ret = 0;
    for(int i = 0; i < n; i++) {
        if(m == d[n-1][i]) ret += p[n-1][i];
        else if(m < d[n-1][i]) {
            ret = p[n-1][i];
            m = d[n-1][i];
        }
    }
    return ret;
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n; memset(d, 0, sizeof(d));
        for(int i = 0; i < n; i++) 
            for(int j = 0; j <= i; j++) 
                cin >> a[i][j];
        printf("%d\n",solve());
    }
    return 0;
}