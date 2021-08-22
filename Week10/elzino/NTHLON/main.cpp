#include <bits/stdc++.h>

using namespace std;

int M;
map<int,int> edges;

void solve() {
    if (edges.find(0) != edges.end()) {
        cout << edges[0] << endl;
        return;
    }
    vector<int> distances(400, INT_MAX);
    priority_queue<pair<int, int>> pq;
    for (auto const& entry : edges) {
        distances[entry.first+200] = entry.second;
        pq.push({-(entry.second), entry.first + 200});
    }
    while (!pq.empty()) {
        auto entry = pq.top();
        pq.pop();
        int distance = -entry.first;
        int here = entry.second;
        if (distances[here] < distance)
            continue;
        for (auto const& entry : edges) {
            int there = here + entry.first;
            int nextDist = distance + entry.second;
            if (there <= 0 || there >= 400)
                continue;
            if (distances[there] > nextDist) {
                distances[there] = nextDist;
                pq.push({-nextDist, there});
            }
        }
    }
    if (distances[200] == INT_MAX)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << distances[200] << endl;
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> M;
        edges.clear();
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            int diff = a - b;
            if (edges.find(diff) == edges.end())
                edges[diff] = a;
            else
                if (edges[diff] > a)
                    edges[diff] = a;
        }
        solve();
    }
}