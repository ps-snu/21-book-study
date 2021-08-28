#include <bits/stdc++.h>
#define M 500
using namespace std;
typedef pair<int, int> pii;
int V, E;
int delay[M], adj[M][M], shortest[M][M];

void adj_init() {
    const int INF = 1000000;
    for(int i = 0; i < V; i++) 
        for(int j = 0; j < V; j++) 
            adj[i][j] = i == j ? 0 : INF;
}

void shortest_init() {
    for(int i = 0; i < V; i++) 
        for(int j = 0; j < V; j++) 
            shortest[i][j] = adj[i][j];
}

void solve() {
    vector<pii> inspect_time(V);
    for(int i = 0; i < V; i++) 
        inspect_time[i] = pii(delay[i], i);
    sort(inspect_time.begin(), inspect_time.end());

    // floyd
    for(int k = 0; k < V; k++) {
        int v_delay = inspect_time[k].first;
        int v = inspect_time[k].second;
        for(int i = 0; i < V; i++) 
            for(int j = 0; j < V; j++)
                if(adj[i][j] > adj[i][v]+adj[v][j]) {
                    adj[i][j] = adj[i][v]+adj[v][j];
                    shortest[i][j] = min(shortest[i][j], adj[i][v]+v_delay+adj[v][j]);
                }
    }
}

int main() {
    cin >> V >> E;
    adj_init();
    for(int i = 0; i < V; i++) {
        int w; cin >> w;
        delay[i] = w;
    }
    for(int e = 0; e < E; e++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u-1][v-1] = w;
        adj[v-1][u-1] = w;
    }
    shortest_init();
    solve();    // precalc
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        int u, v; cin >> u >> v;
        cout << shortest[u-1][v-1] << endl;
    }
    return 0;
}