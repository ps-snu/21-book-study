#include <bits/stdc++.h>
using namespace std;

int C, V, E, n, m, a, b, t;
int fired[1000], station[1000];
vector<map<int, int>> adj;
vector<vector<int>> dist;

void dijkstra(int idx) {
    priority_queue<pair<int, int>> pq;
    
    int src = station[idx];
    dist[idx][src] = 0;
    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int d = -pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[idx][u]) continue;

        for (auto it : adj[u]) {
            int v = it.first;
            int nextDist = d + it.second;

            if (nextDist < dist[idx][v]) {
                dist[idx][v] = nextDist;
                pq.push(make_pair(-nextDist, v));
            }
        }
    }
}

int main() {
    cin >> C;
    for (int tc = 0; tc < C; tc++) {
        cin >> V >> E >> n >> m;

        adj = vector<map<int, int>>(V, map<int, int>());
        for (int i = 0; i < E; i++) {
            cin >> a >> b >> t;

            if (adj[a - 1].count(b - 1) > 0) {
                if (t > adj[a - 1][b - 1])
                    continue;
            }

            adj[a - 1][b - 1] = t;
            adj[b - 1][a - 1] = t;
        }
        for (int i = 0; i < n; i++) {
            cin >> fired[i];
            fired[i]--;
        }

        dist = vector<vector<int>>(m, vector<int>(V, INT_MAX));
        for (int i = 0; i < m; i++) {
            cin >> station[i];
            station[i]--;
            dijkstra(i);
        }

        vector<int> res = vector<int>(n, INT_MAX);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j] = min(res[j], dist[i][fired[j]]);
            }
        }
        
        cout << accumulate(res.begin(), res.end(), 0) << endl;
    }
}