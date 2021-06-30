#include <bits/stdc++.h>
#define M 100
#define N 10
using namespace std;
int n, s, res;
int a[M], d[N][M], p[M], q[M][M];



void solve() {
    sort(a, a+n);
    memset(q, 0, sizeof(q));
    for(int i = 0; i < n; i++) {
        if(i == 0) p[i] = a[i];
        else p[i] = p[i-1] + a[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int avg;
            if(i == 0) avg = (int)round((p[j])/(float)(j+1));
            else avg = (int)round((p[j]-p[i-1])/(float)(j-i+1));
            // printf("%d %d, %d\n", i, j, avg);
            for(int k = i; k <= j; k++) {
                q[i][j] += (avg-a[k]) * (avg-a[k]);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        d[0][i] = q[0][i];
    }
    for(int i = 1; i < s; i++) {
        for(int j = i; j < n; j++) {
            d[i][j] = INT_MAX;
            for(int k = 0; k < j; k++) {
                d[i][j] = min(d[i][j], d[i-1][k] + q[k+1][j]);
            }
        }
    }

    printf("%d\n", d[s-1][n-1]);
}

int main() {
    // freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n >> s;
        for(int i = 0; i < n; i++) cin >> a[i];
        solve();

        // for(int i = 0; i < n; i++) {
        //     printf("%d ", p[i]);
        // }
        // printf("\n");
        // for(int i = 0 ; i < n; i++) {
        //     for(int j = i+1; j < n; j++) {
        //         printf("%d %d : %d\n ", i, j, q[i][j]);
        //     }
        // }
        // printf("\n");
    }
    return 0;
}