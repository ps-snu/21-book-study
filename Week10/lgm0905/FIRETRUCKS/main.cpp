#include <bits/stdc++.h>
#define MAX_V 1000
using namespace std;
typedef pair<int, int> pii;
int V, E, N, M, adj[MAX_V+1][MAX_V+1];
vector<int> fire, water;

void init() {
    for(int i = 0; i < V+1; i++) 
        for(int j = 0; j < V+1; j++) 
            adj[i][j] = 987654321;
    
    fire.clear();
    water.clear();
}

int solve() {
    // connect dummy vertex to water
    for(auto w : water) {
        adj[0][w] = 0;
        adj[w][0] = 0;
    }

    // dijkstra
    int dist[MAX_V+1]; fill(dist, dist+MAX_V+1, INT_MAX);
    bool check[MAX_V+1]; fill(check, check+MAX_V+1, false);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0, 0));
    dist[0] = 0;
    
    while(!pq.empty()) {
        int idx = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        
        if(check[idx]) continue;
        check[idx] = true;

        for(int i = 0; i < V+1; i++) {
            if(dist[i] > dist[idx] + adj[idx][i]) {
                dist[i] = dist[idx] + adj[idx][i];
                pq.push(pii(dist[i], i));
            }
        }
    }

    int res = 0;
    for(auto f : fire) 
        res += dist[f];
    return res;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> V >> E >> N >> M;
        init();
        for(int e = 0; e < E; e++) {
            int u, v, w; cin >> u >> v >> w;
            adj[u][v] = w; adj[v][u] = w;
        }
        for(int n = 0; n < N; n++) {
            int firev; cin >> firev;
            fire.push_back(firev);
        }
        for(int m = 0; m < M; m++) {
            int waterv; cin >> waterv;
            water.push_back(waterv);
        }
        cout << solve() << endl;
    }
    return 0;
}