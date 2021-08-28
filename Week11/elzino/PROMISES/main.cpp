#include <bits/stdc++.h>

#define BIGNUM 100000000

using namespace std;

int V, M, N;

int adj[200][200];

void floyd() {
    for (int i = 0; i < V; i++)
        adj[i][i] = 0;

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

int checkValidAndAdd(int a, int b, int c) {
    if (adj[a][b] <= c)
        return 1;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = min({adj[i][j], adj[i][a] + c + adj[b][j], adj[i][b] + c + adj[a][j]});
    return 0;
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> V >> M >> N;
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adj[i][j] = BIGNUM;
        for (int i = 0; i < M; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a][b] = min(c, adj[a][b]);
            adj[b][a] = min(c, adj[b][a]);
        }

        floyd();
        int ret = 0;
        for (int i = 0; i < N; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            ret += checkValidAndAdd(a, b, c);
        }
        cout << ret << endl;
    }
}
