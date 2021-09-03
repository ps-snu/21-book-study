#include <bits/stdc++.h>
#define MAX_V 2000
using namespace std;
typedef pair<int, int> pii;
int V, E;
vector<pair<int ,pii> > edges;
vector<vector<int> > g;

void init() {
    edges = vector<pair<int ,pii> >(E);
}

bool hasPath() {
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

    g = vector<vector<int> >(V);
    int lo = 0, hi = 0;
    g[edges[0].second.first].push_back(edges[0].second.second);
    g[edges[0].second.second].push_back(edges[0].second.first);

    int ret = 987654321;    // BIG_NUM
    while(lo < edges.size() && hi < edges.size()) {
        if(hasPath()) {
            ret = min(ret, edges[hi].first - edges[lo].first);
            int u = edges[lo].second.first, v = edges[lo].second.second;
            g[u].erase(g[u].begin());
            g[v].erase(g[v].begin());
            lo++;
        }
        else {
            hi++;
            if(hi < edges.size()) {
                int u = edges[hi].second.first, v = edges[hi].second.second;
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
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
            edges[e] = pair<int, pii>(w, pii(u,v));
        }
        cout << solve() << endl;
    }
    return 0;
}