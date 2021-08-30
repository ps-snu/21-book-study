#include <bits/stdc++.h>
using namespace std;

const int INF = 100000000;
int V, E, T, A, B, C;
vector<pair<int, int>> v;
int delay[500];
int adj[500][500][2];

int sumCost1(int i, int j) {
    return adj[i][j][0] + adj[i][j][1];
}

int sumCost2(int i, int j, int w) {
    return adj[i][w][0] + adj[w][j][0] + max(max(adj[i][w][1], adj[w][j][1]), v[w].first);
}

void initAdj() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j][0] = INF;
            adj[i][j][1] = INF;

            if (i == j) {
                adj[i][j][0] = 0;
                adj[i][j][1] = 0;
            }
        }
    }
}

void floyd() {
    for (int k = 0; k < V; k++) {
        int w = v[k].second;

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                adj[i][j][0] = min(adj[i][j][0], adj[i][w][0] + adj[w][j][0]);
                adj[i][j][1] = min(adj[i][j][1], adj[i][w][0] + adj[w][j][0] + delay[w]);
            }
        }
    }
}

int main() {
    cin >> V >> E;

    initAdj();
    v.clear();

    for (int i = 0; i < V; i++) {
        cin >> delay[i];
        v.push_back(make_pair(delay[i], i));
    }

    sort(v.begin(), v.end());
    
    for (int i = 0; i < E; i++) {
        cin >> A >> B >> C;
        if (adj[A - 1][B - 1][0] > C) {
            adj[A - 1][B - 1][0] = C;
            adj[B - 1][A - 1][0] = C;
            adj[A - 1][B - 1][1] = C;
            adj[B - 1][A - 1][1] = C;
        }
    }

    floyd();

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> A >> B;

        cout << adj[A - 1][B - 1][1] << endl;
    }
}