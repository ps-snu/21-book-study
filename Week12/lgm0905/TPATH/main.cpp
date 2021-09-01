#include <bits/stdc++.h>
#define MAX_V 2000
using namespace std;
typedef pair<int, int> pii;
int V, E;
vector<vector<pii> > adj;
vector<pair<int ,pii> > edges;

void init() {
    adj = vector<vector<pii> >(V);
    edges = vector<pair<int ,pii> >(E);
}

// checks path between 0 to V-1
bool hasPath(int lo, int hi) {
    vector<vector<int> > g(V);
    for(int i = lo; i <= hi; i++) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int visited[MAX_V]; memset(visited, 0, sizeof(visited)); 
    visited[0] = 1;

    queue<int> q; q.push(0);
    while(!q.empty()) {
        int here = q.front();
        if(here == V-1) return true;
        visited[here] = 1;
        q.pop();

        for(auto there : g[here]) {
            if(!visited[there]) q.push(there);
        }
    }
    return false;
}

int solve() {
    sort(edges.begin(), edges.end());

    int lo = 0, hi = 0;
    int ret = 987654321;    // BIG_NUM
    while(lo < edges.size() && hi < edges.size()) {
        if(hasPath(lo, hi)) {
            ret = min(ret, edges[hi].first - edges[lo].first);
            lo++;
        }
        else hi++;
    }
    return ret;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> V >> E;
        init();
        for(int e = 0; e < E; e++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back(pii(v, w));
            adj[v].push_back(pii(u, w));
            edges[e] = pair<int, pii>(w, pii(u,v));
        }
        cout << solve() << endl;
    }
    return 0;
}