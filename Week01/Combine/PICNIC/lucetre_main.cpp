#include <bits/stdc++.h>
#define N 10
#define M 55
using namespace std;
pair<int,int> p[M+1];
int a[N+1], chk[M+1];
int n, m, res;

void combination(int lev) {
    if (lev >= n/2) {
        memset(chk, 0, sizeof(chk));
        for (int i = 0; i < n/2; i++) 
            chk[p[a[i]].first] = chk[p[a[i]].second] = 1;
        for (int i = 0; i < n; i++)
            if (chk[i] == 0) return;
        res++;
        return;
    }
    for (int i = (lev?a[lev-1]+1:0); i < m; i++) {
        a[lev] = i;
        combination(lev+1);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n >> m;
        res = 0;
        for (int i = 0; i < m; i++)
            cin >> p[i].first >> p[i].second;
        combination(0);
        cout << res << endl;
    }
    return 0;
}