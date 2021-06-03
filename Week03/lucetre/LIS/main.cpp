#include <bits/stdc++.h>
#define M 500
using namespace std;
int d[M+1], a[M+1];
int n;

int process() {
    memset(d, 0, n*sizeof(int));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[i] > a[j]) 
                d[i] = max(d[i], d[j]+1);
    return *max_element(d, d+n) + 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << process() << endl;
    }
    return 0;
}