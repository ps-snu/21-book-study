#include <bits/stdc++.h>

using namespace std;

#define UNWATCHED 0
#define WATCHED 1
#define CAMERA 2

int visit[1000];
pair<int, int> dip[1000];

int g, h, totalCamera;


int dfs(int here, vector<vector<int>> &adj) {
    visit[here] = 1;
    int s[3] = {0, 0, 0}; // UNWATCHED, WATCHED, CAMERA
    for (int there : adj[here]) {
        if (!visit[there])
            s[dfs(there, adj)]++;
    }
    if (s[0]) {
        totalCamera++;
        return CAMERA;
    }
    if (s[2])
        return WATCHED;
    return UNWATCHED;
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> g >> h;
        memset(visit, 0, sizeof(visit));
        totalCamera = 0;
        vector<vector<int>> adj = vector<vector<int>>(g, vector<int>());
        for (int i = 0; i < h; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v); adj[v].push_back(u);
        }
        for (int i = 0; i < g; i++) {
            if (!visit[i])
                if (dfs(i, adj) == UNWATCHED)
                    totalCamera++;
        }
        cout << totalCamera << endl;
    }
}
