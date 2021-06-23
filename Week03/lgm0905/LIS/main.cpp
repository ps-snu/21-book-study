#include <bits/stdc++.h>
#define M 500
using namespace std;

int a[M]; int d[M];
int N;

void solve(int idx) {
    if(idx == N-1) return;
    for(int i = idx; i < N; i++) 
        if(a[idx] < a[i]) d[i] = max(d[idx]+1, d[i]);
    solve(idx+1);
}

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        fill(d, d + M, 1); cin >> N;
        for (int n = 0; n < N; n++) cin >> a[n];
        solve(0);
        int res = -1;
        for(int i = 0; i < N; i++) res = max(res, d[i]);
        printf("%d\n", res);
    }
    return 0;
}