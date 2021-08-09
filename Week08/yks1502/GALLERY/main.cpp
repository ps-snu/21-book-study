#include <bits/stdc++.h>
using namespace std;

int C, G, H, e1, e2, installed;
vector<vector<int>> adj;
vector<bool> visited;

enum State {
    UNWATCHED,
    WATCHED,
    INSTALLED
};

State dfs(int v) {
    visited[v] = true;
    int children[3] = {0, 0, 0};
    
    for (int i = 0; i < adj[v].size(); i++) {
        int u = adj[v][i];
        if (!visited[u])
            children[dfs(u)]++;
    }

    if (children[UNWATCHED] > 0) {
        installed++;
        return INSTALLED;
    }

    if (children[INSTALLED] > 0) {
        return WATCHED;
    }

    return UNWATCHED;
}

int main() {
    cin >> C;
    for (int tc = 0; tc < C; tc++) {
        cin >> G >> H;
        
        adj = vector<vector<int>>(1000, vector<int>());
        for (int i = 0; i < H; i++) {
            cin >> e1 >> e2;
            adj[e1].push_back(e2);
            adj[e2].push_back(e1);
        }

        visited = vector<bool>(1000, false);
        installed = 0;

        for (int i = 0; i < G; i++) {
            if (!visited[i] && dfs(i) == UNWATCHED)
                installed++;
        }

        cout << installed << endl;
    }
}