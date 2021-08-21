#include <bits/stdc++.h>
#define N 1000
using namespace std;
typedef pair<int, int> pii;
vector<pii> adj[N+1];
int dist[N+1], fire[N+1];
int V, E, n, m;

int process() {
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    
    for (int i = 0; i < V; i++) dist[i] = INT_MAX;
    for (int i = 0; i < n; i++) cin >> fire[i];
    
    for (int i = 0; i < m; i++) {
        int s; cin >> s;
        dist[s-1] = 0;
        Q.push(make_pair(0, s-1));
    }
    
    while (!Q.empty()) {
        int df = Q.top().first;
        int f = Q.top().second;
        Q.pop();
 
        for (int i = 0; i < adj[f].size(); i++) {
            int dv = adj[f][i].first;
            int v = adj[f][i].second;
            if (dist[v] > df + dv) {
                dist[v] = df + dv;
                Q.push(make_pair(dist[v], v));
            }
        }
    }
    
    int res = 0;
    for (int i = 0; i < n; i++)
        res += dist[fire[i]-1];
        
    return res;
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> V >> E >> n >> m;
        for (int i = 0; i < E; i++) {
            int a, b, t; cin >> a >> b >> t;
            adj[a-1].push_back(make_pair(t, b-1));
            adj[b-1].push_back(make_pair(t, a-1));
        }
        cout << process() << endl;
        for (int i = 0; i < V; i++) {
            adj[i].clear();
        }
    }
    return 0;
}
