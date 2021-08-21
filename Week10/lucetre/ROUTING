#include <bits/stdc++.h>
#define N 10000
using namespace std;
typedef pair<double, int> pdi;
vector<pdi> adj[N+1];
double dist[N+1];
int n, m;

double process() {
    priority_queue<pdi, vector<pdi>, greater<pdi>> Q;
    
    for (int i = 0; i < n; i++)
        dist[i] = DBL_MAX;
    dist[0] = 1.0;
 
    Q.push(make_pair(1.0, 0));
    
    while (!Q.empty()) {
        double df = Q.top().first;
        int f = Q.top().second;
        Q.pop();
 
        for (int i = 0; i < adj[f].size(); i++) {
            double dv = adj[f][i].first;
            int v = adj[f][i].second;
            if (dist[v] > df * dv) {
                dist[v] = df * dv;
                Q.push(make_pair(dist[v], v));
            }
        }
    }
    return dist[n-1];
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            double c; cin >> c;
            adj[a].push_back(make_pair(c, b));
            adj[b].push_back(make_pair(c, a));
        }
        printf("%0.10f\n", process());
        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }
    }
    return 0;
}
