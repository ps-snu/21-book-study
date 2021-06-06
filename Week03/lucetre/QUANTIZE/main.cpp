#include <bits/stdc++.h>
#define M 100
#define N 10
#define INF (INT_MAX/2)
using namespace std;
int a[M+1], p[M+1], q[M+1][M+1];
int d[N+1][M+1];
int n, s;

int partial_avg(int s, int e) {
    if (s == 0) return (int) round(p[e] / (float)(e+1));
    return (int) round((p[e]-p[s-1]) / (float)(e-s+1));
}

int partial_sqsum(int s, int e) {
    int sum = 0, mu = partial_avg(s, e);
    for (int i = s; i <= e; i++) sum += (a[i]-mu)*(a[i]-mu);
    return sum;
}

int process() {
    for (int i = 0; i < n; i++)
        p[i] = i ? p[i-1]+a[i] : a[i];
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            q[i][j] = partial_sqsum(i, j);

    for (int i = 0; i < n; i++) 
        d[0][i] = q[0][i];
    for (int i = 1; i < s; i++) {
        for (int j = i; j < n; j++) {
            d[i][j] = INF;
            for (int k = 0; k < j; k++)
                d[i][j] = min(d[i][j], d[i-1][k] + q[k+1][j]);
        }
    }

    for (int i = 0; i < s; i++) {
        for (int j = 0; j < n; j++)
            cout << d[i][j] << " ";
        cout << endl;
    }
    return d[s-1][n-1];
}

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n >> s;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a+n);
        cout << process() << endl;
    }
    return 0;
}