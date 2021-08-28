#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<vector<pair<int, double>>> adj;

void solve() {
    vector<double> distances(N, DBL_MAX);
    priority_queue<pair<double, int>> q;
    distances[0] = 0;
    q.push({0.0, 0});
    while(!q.empty()) {
        auto entry = q.top();
        q.pop();
        double distance = -entry.first;
        int here = entry.second;
        if (distance > distances[here])
            continue;
        for (auto p : adj[here]) {
            int there = p.first;
            double nextDist = distance + p.second;
            if (nextDist < distances[there]) {
                distances[there] = nextDist;
                q.push({-nextDist, there});
            }
        }
    }
    cout << exp(distances[N-1]) << endl;
}

int main() {
    cout << fixed;
    cout.precision(10);
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> N >> M;
        adj = vector<vector<pair<int, double>>>(N, vector<pair<int, double>>());
        for (int i = 0; i < M; i++) {
            int x, y;
            double z;
            cin >> x >> y >> z;
            adj[x].push_back({y, log(z)});
            adj[y].push_back({x, log(z)});
        }
        solve();
    }
}
