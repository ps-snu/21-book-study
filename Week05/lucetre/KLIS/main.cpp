#include <bits/stdc++.h>
#define M 500
#define INF INT_MAX
using namespace std;
int dy[M+1][M+1];
int a[M+1];
int n, m, l;

void trace(int l, int s) {
    if (l == 0) return;
    vector<pair<int, int>> v;
    int i;
    for (i = s+1; i < n; i++)
        if ((s == -1 || a[s] < a[i]) && dy[l][i])
            v.push_back(make_pair(a[i], i));
    sort(v.begin(), v.end());
    for (i = 0; i < v.size(); i++) {
        if (m <= dy[l][v[i].second])
            break;
        m -= dy[l][v[i].second];
    }
    cout << v[i].first << " ";
    trace(l-1, v[i].second);
}

void process() {
    for (int i = 0; i < n; i++)
        dy[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        l = 0;
        for (int j = 0; j < n; j++) {
            dy[i][j] = 0;
            for (int k = j+1; k < n; k++)
                if (a[j] < a[k])
                    if (dy[i][j] - INF + dy[i-1][k] > 0)
                        dy[i][j] = INF;
                    else
                        dy[i][j] += dy[i-1][k];
            l |= dy[i][j];
        }
        if (l == 0) {
            l = i-1;
            break;
        }
        l = i;
    }
    cout << l << endl;
    trace(l, -1);
    cout << endl;
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        process();
    }
    return 0;
}