#include <bits/stdc++.h>
using namespace std;

int C, M;
int t[500][2];
vector<map<int, int>> adj;
vector<int> dist;

int idx(int i) {
    return i + 199;
}

void dijkstra() {
    priority_queue<pair<int, int>> pq;
    dist = vector<int>(400, INT_MAX);
    dist[399] = 0;
    pq.push(make_pair(0, 399));

    while (!pq.empty()) {
        int d = -pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto it : adj[u]) {
            int v = it.first;
            int nextDist = d + it.second;

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
        cin >> M;

        adj = vector<map<int, int>>(400, map<int, int>());
        for (int m = 0; m < M; m++) {
            cin >> t[m][0] >> t[m][1];
            int diff = t[m][0] - t[m][1];

            if (adj[399].count(idx(diff)) > 0) {
                if (t[m][0] > adj[399][idx(diff)])
                    continue;
            }

            adj[399][idx(diff)] = t[m][0];
        }

        for (int v = -199; v <= 199; v++) {
            for (int m = 0; m < M; m++) {
                int next = v + t[m][0] - t[m][1];
                if (abs(next) > 199)
                    continue;

                if (adj[idx(v)].count(idx(next)) > 0) {
                    if (t[m][0] > adj[idx(v)][idx(next)])
                        continue;
                }

                adj[idx(v)][idx(next)] = t[m][0];
            }
        }

        dijkstra();

        int res = dist[idx(0)];
        if (res == INT_MAX)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << res << endl;
    }
}