#include <bits/stdc++.h>
#define M 10000
using namespace std;
int v, e;
vector<pair<int, float> > adj[M+1];

void init() {
    for(int i = 0; i < M+1; i++) 
        adj[i].clear();
}

float solve() {
    auto dist = vector<pair<float, bool> >(v, make_pair(FLT_MAX, false)); 
    dist[0] = make_pair(1, true);

    int cur = 0;
    while(!dist[v-1].second) {
        for(auto i : adj[cur]) {
            int idx = i.first; float weight = i.second;
            if(dist[idx].second) continue;
            dist[idx].first = min(dist[idx].first, dist[cur].first * weight);
        }

        pair<float, int> next = make_pair(FLT_MAX, -1);
        for(int i = 0; i < v; i++) {
            if(dist[i].second || next.first <= dist[i].first) continue;
            next = make_pair(dist[i].first, i);
        }
        
        dist[next.second].second = true;
        cur = next.second;
    }

    return dist[v-1].first;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> v >> e;
        init();
        for(int i = 0; i < e; i++) {
            int start, fin; float w;
            cin >> start >> fin >> w;
            adj[start].push_back(make_pair(fin, w));
            adj[fin].push_back(make_pair(start, w));
        }
        printf("%.10f\n", solve()); 
    }
    return 0;
}