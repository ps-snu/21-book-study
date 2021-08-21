#include <bits/stdc++.h>
#define N 400
using namespace std;
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> Q;
vector<pii> adj[N+1];
int dist[N+1];

void process() {
    for (int i = 0; i <= N; i++)
        dist[i] = INT_MAX;
    
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
    
    if (dist[N/2] == INT_MAX)
        cout<< "IMPOSSIBLE" << endl;
    else
        cout << dist[N/2] << '\n';
}


int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            int z = x - y;
            dist[z + N/2] = x;
            Q.push(make_pair(x, z + N/2));
            for (int w = 0; w < N; w++) {
                if (w+z > 0 && w+z < N)
                    adj[w].push_back(make_pair(x, w+z));
            }
        }
        process();
        for (int i = 0; i <= N; i++)
            adj[i].clear();
    }
}
