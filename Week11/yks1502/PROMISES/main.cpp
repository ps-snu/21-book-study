#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;
int C, V, M, N, a, b, c;
int adj[200][200];

void initAdj() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = INF;

            if (i == j) {
                adj[i][j] = 0;
            }
        }
    }
}

void floyd() {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
}

void update() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = min(min(adj[i][j], adj[i][a] + c + adj[b][j]), adj[i][b] + c + adj[a][j]);
        }
    }
}

int main() {
    cin >> C;
    for (int tc = 0; tc < C; tc++) {
        cin >> V >> M >> N;

        initAdj();
        for (int m = 0; m < M; m++) {
            cin >> a >> b >> c;
            adj[a][b] = min(adj[a][b], c);
            adj[b][a] = min(adj[b][a], c);
        }

        floyd();

        int count = 0;
        for (int n = 0; n < N; n++) {
            cin >> a >> b >> c;
            if (c >= adj[a][b]) {
                count++;
            } else {
                update();
            }
        }

        cout << count << endl;
    }
}