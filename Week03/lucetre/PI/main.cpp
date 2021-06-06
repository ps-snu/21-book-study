#include <bits/stdc++.h>
#define INF (INT_MAX/2)
#define M 10000
using namespace std;
int n, a[M+1], d[M+1];

int difficulty(int s, int e) {
    bool flag = true;
    for (int i = s; i < e; i++)
        flag &= (a[i+1] == a[i]);
    if (flag) return 1;

    flag = true;
    for (int i = s; i < e; i++)
        flag &= (a[i+1]-a[i] == 1);
    if (flag) return 2;
    flag = true;
    for (int i = s; i < e; i++)
        flag &= (a[i+1]-a[i] == -1);
    if (flag) return 2;

    flag = true;
    for (int i = s; i < e-1; i++)
        flag &= (a[i+2] == a[i]);
    if (flag) return 4;

    flag = true;
    int d = a[s+1]-a[s];
    for (int i = s+1; i < e; i++)
        flag &= (a[i+1]-a[i] == d);
    if (flag) return 5;

    return 10;
}

int process() {
    d[0] = 0;
    for (int i = 1; i <= n; i++) { 
        d[i] = INF;
        for (int j = 3; j <= 5; j++)
            if (i-j >= 0)
                d[i] = min(d[i], d[i-j] + difficulty(i-j, i-1));
    }
    return d[n];
}

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        string s; cin >> s;
        n = s.size();
        for (int i = 0; i < n; i++) a[i] = s[i]-'0';
        cout << process() << endl;
    }
    return 0;
}