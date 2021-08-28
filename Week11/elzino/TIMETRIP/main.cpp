#include <bits/stdc++.h>

using namespace std;

#define INF 1000000
typedef pair<int, int> pii;

int V, W;


vector<vector<pii>> adj;
bool visitied[1000];


bool dfs(int src, int target, vector<bool>& visited) {
    if (visited[src])
        return false;
    visited[src] = true;
    if (src == target)
        return true;
    for (pii p : adj[src]) {
        int there = p.first;
        if (!visited[there] && dfs(there, target, visited))
            return true;
    }
    return false;
}

bool reachable(int src, int target) {
    vector<bool> visited(V, false);
    return dfs(src, target, visited);
}

string bellman(int src, int target, int sign) {
    vector<int> upper(V, INF);
    upper[src] = 0;
    for (int i = 0; i < V-1; i++) {
        for (int here = 0; here < V; here++) {
            for (pii p : adj[here]) {
                int there = p.first;
                int w = p.second;
                if (upper[here]  + w*sign < upper[there])
                    upper[there] = upper[here] + w * sign;
            }
        }
    }
    for (int here = 0; here < V; here++) {
        for (pii p : adj[here]) {
            int there = p.first;
            int w = p.second;
            if (upper[here]  + w*sign < upper[there] && reachable(src, here) && reachable(here, target))
                return "INFINITY";
        }
    }
    if (upper[target] > (INF / 2))
        return "UNREACHABLE";
    return to_string(sign * upper[target]);
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> V >> W;
        adj = vector<vector<pii>>(V, vector<pii>());
        for (int i = 0; i < W; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            adj[a].push_back({b, d});
        }
        string result = bellman(0, 1, 1);
        cout << result;
        if (result != "UNREACHABLE")
            cout << " " << bellman(0, 1, -1);
        cout << endl;
    }
}
