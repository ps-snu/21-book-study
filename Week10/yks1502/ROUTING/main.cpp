#include <bits/stdc++.h>
using namespace std;

int C, N, M, a, b;
double c;
vector<map<int, double>> adj;
vector<double> dist;

void dijkstra() {
    priority_queue<pair<double, int>> pq;
    dist = vector<double>(N, numeric_limits<double>::max());
    dist[0] = 1;
    pq.push(make_pair(-1, 0));

    while (!pq.empty()) {
        double d = -pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto it : adj[u]) {
            int v = it.first;
            double nextDist = d * it.second;

            if (nextDist < dist[v]) {
                dist[v] = nextDist;
                pq.push(make_pair(-nextDist, v));
            }
        }
    }
}

int main() {
    cin >> C;
    for (int tc = 0; tc < C; tc++) {
        cin >> N >> M;
        
        adj = vector<map<int, double>>(N, map<int, double>());
        for (int m = 0; m < M; m++) {
            cin >> a >> b >> c;

            if (adj[a].count(b) > 0) {
                if (c > adj[a][b])
                    continue;
            }
            
            adj[a][b] = c;
            adj[b][a] = c;
        }

        dijkstra();
        
        printf("%.10f\n", dist[N - 1]);
    }
}