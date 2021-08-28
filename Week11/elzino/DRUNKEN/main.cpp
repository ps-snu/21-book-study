#include <bits/stdc++.h>

#define BIGNUM 500000

using namespace std;

int V, E;

vector<int> T;

vector<pair<int, int>> piv;

int adj[500][500];
int adj_p[500][500];


void solve() {
    for (int i = 0; i < V; i++) {
        adj[i][i] = 0;
    }

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj_p[i][j] = adj[i][j];

    sort(piv.begin(), piv.end());

    for (auto p : piv) {
        int k = p.second;
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                adj_p[i][j] = min(adj_p[i][j], adj[i][k] + T[k] + adj[k][j]);
            }
    }
}

int main() {
    cin >> V >> E;
    for (int i = 0; i < V; i++) {
        int t;
        cin >> t;
        T.push_back(t);
        piv.push_back({t, i});
    }
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++) {
            adj[i][j] = BIGNUM;
        }

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a-1][b-1] = c;
        adj[b-1][a-1] = c;
    }

    solve();

    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        int a, b;
        cin >> a >> b;
        cout << adj_p[a-1][b-1] << endl;
    }
}
