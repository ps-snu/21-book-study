#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int M;
vector<pii> player;

void init() { player = vector<pii>(M); }

int vertex(int val) { return val + 199; }

string solve() {
    // initalize
    int adj[400][400];
    for(int i = 0; i < 400; i++) 
        for(int j = 0; j < 400; j++) 
            adj[i][j] = 1024;

    // make graph
    const int start = vertex(200);
    for(auto p : player) 
        adj[start][vertex(p.first-p.second)] = min(adj[start][vertex(p.first-p.second)], p.first);

    for(int i = vertex(-199); i <= vertex(199); i++) 
        for(auto p : player) {
            int v = vertex((i-199)+(p.first-p.second));
            if(vertex(-199) <= v && v <= vertex(199)) 
                adj[i][v] = min(adj[i][v], p.first);
        }  
    
    // dijkstra
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    int dist[400]; fill(dist, dist+400, 987654321);
    bool check[400]; fill(check, check+400, false);
    dist[start] = 0;
    pq.push(pii(0, start));

    while(!pq.empty()) {
        int idx = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if(check[idx]) continue;
        check[idx] = true;

        for(int i = 0; i < 399; i++) {
            if(adj[idx][i] > 200) continue;
            if(dist[i] > dist[idx] + adj[idx][i]) {
                dist[i] = dist[idx] + adj[idx][i];
                pq.push(pii(dist[i], i));
            }
        }
    }
    return dist[vertex(0)] == 987654321 ? "IMPOSSIBLE" : to_string(dist[vertex(0)]);
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> M;
        init();
        for(int i = 0; i < M; i++) {
            int fir, sec; cin >> fir >> sec;
            player[i] = pii(fir, sec);
        }
        cout << solve() << endl;
    }
    return 0;
}