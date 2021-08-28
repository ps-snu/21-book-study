#include <bits/stdc++.h>
using namespace std;

const int INF = 100000000;
const int M = 1000000;
int C, V, W, a, b, d;
vector<vector<pair<int, int>>> adj;
vector<int> upper, lower;
bool reachable[100][100];

void floyd() {
    for (int i = 0; i < V; i++) {
        reachable[i][i] = true;
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                reachable[i][j] = reachable[i][j] || (reachable[i][k] && reachable[k][j]);
            }
        }
    }
}

void bellmanFord() {
    upper = vector<int>(V, INF);
    lower = vector<int>(V, -INF);
    upper[0] = 0;
    lower[0] = 0;

    for (int iter = 0; iter < V - 1; iter++) {
        for (int u = 0; u < V; u++) {
            for (int i = 0; i < adj[u].size(); i++) {
                int v = adj[u][i].first;
                int cost = adj[u][i].second;

                upper[v] = min(upper[v], upper[u] + cost);
                lower[v] = max(lower[v], lower[u] + cost);
            }
        }
    }

    for (int u = 0; u < V; u++) {
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int cost = adj[u][i].second;

            if (upper[u] + cost < upper[v]) {
                if (reachable[0][u] && reachable[u][1]) {
                    upper[1] = -INF;
                }
            }

            if (lower[u] + cost > lower[v]) {
                if (reachable[0][u] && reachable[u][1]) {
                    lower[1] = INF;
                }
            }
        }
    }
}

void print() {
    if (!reachable[0][1]) {
        cout << "UNREACHABLE" << endl;
        return;
    }

    if (upper[1] == -INF) {
        cout << "INFINITY ";
    } else {
        cout << upper[1] << " ";
    }

    if (lower[1] == INF) {
        cout << "INFINITY" << endl;
    } else {
        cout << lower[1] << endl;
    }
}

int main() {
    cin >> C;
    for (int tc = 0; tc < C; tc++) {
        cin >> V >> W;
        adj = vector<vector<pair<int, int>>>(V, vector<pair<int, int>>());
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
                reachable[i][j] = false;
        }

        for (int w = 0; w < W; w++) {
            cin >> a >> b >> d;
            adj[a].push_back(make_pair(b, d));
            reachable[a][b] = true;
        }

        floyd();
        bellmanFord();
        print();
    }
}