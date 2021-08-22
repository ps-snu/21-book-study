#include <bits/stdc++.h>

using namespace std;

int V, E, N, M;

vector<vector<pair<int,int>>> adj;
vector<int> fireStation;
vector<int> fireSpot;

void solve() {
    vector<int> times(V+1, INT_MAX);
    priority_queue<pair<int, int>> pq;
    for (int fs : fireStation) {
        times[fs] = 0;
        pq.push({0, fs});
    }
    while (!pq.empty()) {
        auto entry = pq.top();
        pq.pop();
        int here = entry.second;
        int time = -entry.first;
        if (time > times[here])
            continue;
        for (auto p : adj[here]) {
            int there = p.first;
            int nextTime = time + p.second;
            if (nextTime < times[there]) {
                times[there] = nextTime;
                pq.push({-nextTime, there});
            }
        }
    }
    int ret = 0;
    for (int fire : fireSpot)
        ret += times[fire];
    cout << ret << endl;
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> V >> E >> N >> M;
        adj = vector<vector<pair<int,int>>>(V+1, vector<pair<int,int>>());
        fireStation.clear();
        fireSpot.clear();
        for (int i = 0; i < E; i++) {
            int a, b, t;
            cin >> a >> b >> t;
            adj[a].push_back({b, t});
            adj[b].push_back({a, t});
        }
        for (int i = 0; i < N; i++) {
            int a; cin >> a;
            fireSpot.push_back(a);
        }
        for (int i = 0; i < M; i++) {
            int a; cin >> a;
            fireStation.push_back(a);
        }
        solve();
    }
}
