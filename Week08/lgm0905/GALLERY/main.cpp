#include <bits/stdc++.h>
#define M 1000
#define UNWATCHED 0
#define WATCHED 1
#define INSTALLED 2
using namespace std;
int G, H, visited[M+1], installed;
vector< vector<int> > adj;

void init() {
    adj = vector< vector<int> >(G, vector<int>());
    memset(visited, 0, sizeof(visited));
    installed = 0;
}

int dfs(int u) {
    visited[u] = 1;
    int ch[3] = {0, 0, 0};
    for(auto v : adj[u]) {
        if(!visited[v]) {
            ch[dfs(v)]++;
        }
    }
    if(ch[UNWATCHED]) {
        installed++;
        return INSTALLED;
    }
    if(ch[INSTALLED])
        return WATCHED;
    return UNWATCHED;
}

int solve() {
    for(int i = 0; i < G; i++) 
        if(!visited[i] && dfs(i) == UNWATCHED)
            installed++;
    return installed;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> G >> H;
        init();
        for(int i = 0; i < H; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout << solve() << endl;
    }
}
