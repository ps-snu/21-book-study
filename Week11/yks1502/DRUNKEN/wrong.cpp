#include <bits/stdc++.h>
using namespace std;

const int INF = 100000000;
int V, E, T, A, B, C;
int v[500];
int adj[500][500][2];

int sumCost1(int i, int j) {
    return adj[i][j][0] + adj[i][j][1];
}

int sumCost2(int i, int j, int k) {
    return adj[i][k][0] + adj[k][j][0] + max(max(adj[i][k][1], adj[k][j][1]), v[k]);
}

void initAdj() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j][0] = INF;
            adj[i][j][1] = 0;

            if (i == j) {
                adj[i][j][0] = 0;
            }
        }
    }
}

void floyd() {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (sumCost1(i, j) > sumCost2(i, j, k)) {
                    adj[i][j][0] = adj[i][k][0] + adj[k][j][0];
                    adj[i][j][1] = max(max(adj[i][k][1], adj[k][j][1]), v[k]);
                }
            }
        }
    }
}

int main() {
    cin >> V >> E;

    initAdj();
    for (int i = 0; i < V; i++) {
        cin >> v[i];
    }
    
    for (int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        if (adj[A - 1][B - 1][0] > C) {
            adj[A - 1][B - 1][0] = C;
            adj[B - 1][A - 1][0] = C;
        }
    }

    floyd();

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> A >> B;

        cout << sumCost1(A - 1, B - 1) << endl;
    }
}