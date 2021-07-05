#include <bits/stdc++.h>
#define M 20000
using namespace std;
int a[M+1];
int n;

int process() {
    int res = 0;
    stack<int> S;
    S.push(0);
    S.push(a[0]);
    for (int i = 1; i <= n; i++) {
        int ind = i;
        while (! S.empty() && S.top() > a[i]) {
            int fh = S.top(); S.pop();
            int fi = S.top(); S.pop();
            ind = min(ind, fi);
            res = max(res, (i-fi)*fh);
        }
        S.push(ind);
        S.push(a[i]);
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        for (int i = 0; i < n; i++) 
            cin >> a[i];
        a[n] = 0;
        cout << process() << endl;
    }
    return 0;
}