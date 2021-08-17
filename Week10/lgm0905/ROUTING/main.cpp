#include <bits/stdc++.h>
#define M 10000
using namespace std;
typedef pair<double, int> pdi;
int V, E;
vector<pdi> adj[M+1];
double dist[M+1];
bool check[M+1];

void init() {
    for(int i = 0; i < M+1; i++) {
        adj[i].clear();
        dist[i] = DBL_MAX;
        check[i] = false;
    }
}

double solve() {
    priority_queue<pdi, vector<pdi>,  greater<pdi> > pq;
    pq.push(pdi(1, 0));
    dist[0] = 1;

    while(!pq.empty()) {
        int idx = pq.top().second;
        double weight = pq.top().first;
        pq.pop();
        if(check[idx]) continue;
        check[idx] = true;

        for(auto nd : adj[idx]) {
            int next_idx = nd.second;
            double next_weight = nd.first;
            double next_dist = weight * next_weight;
            if(dist[next_idx] > next_dist) {
                dist[next_idx] = next_dist;
                pq.push(pdi(next_dist, next_idx));
            }
        }
    }

    return dist[V-1];
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> V >> E;
        init();
        for(int e = 0; e < E; e++) {
            int u, v; double w;
            cin >> u >> v >> w;
            adj[u].push_back(pdi(w, v));
            adj[v].push_back(pdi(w, u));
        }
        printf("%.10lf\n", solve());
    }
    return 0;
}