#include <bits/stdc++.h>
#define M 100
using namespace std;
typedef pair<int, int> pii;
vector<vector<pii> > adj;
int V, W;

void init() {
    adj = vector<vector<pii> >(M, vector<pii>());
}

bool findPath() {
    int visited[M]; memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(0);

    while(!q.empty()) {
        int here = q.front();
        visited[here] = 1;
        q.pop();

        for(auto there_pair : adj[here]) {
            int there = there_pair.first;
            if(!visited[there]) q.push(there);
        }
    }
    return visited[1] ? true : false;
}

string bellmanFord() {
    vector<int> upper(V, 87654321); // past
    vector<int> lower(V, -87654321);
    upper[0] = 0; 
    lower[0] = 0;

    int upper_updated, lower_updated;
    for(int i = 0; i < V; i++) {
        upper_updated = lower_updated = 0;
        for(int here = 0; here < V; here++) 
            for(int j = 0; j < adj[here].size(); j++) {
                int there = adj[here][j].first;
                int cost = adj[here][j].second;
                if(upper[there] > upper[here] + cost) {
                    upper[there] = upper[here] + cost;
                    upper_updated = 1;
                }
                if(lower[there] < lower[here] + cost) {
                    lower[there] = lower[here] + cost;
                    lower_updated = 1;
                }
            }
        if((!upper_updated) && (!lower_updated)) break;
    }

    // unreached
    if(upper[1] == 87654321 || (!findPath())) return "UNREACHABLE";
    
    // else case
    string ret = "";
    ret += upper_updated ? "INFINITY" : to_string(upper[1]);
    ret += " ";
    ret += lower_updated ? "INFINITY" : to_string(lower[1]);
    return ret;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        init();
        cin >> V >> W;
        for(int w = 0; w < W; w++) {
            int u, v, d; cin >> u >> v >> d;
            adj[u].push_back(pii(v, d));
        }
        cout << bellmanFord() << endl;
    }
    return 0;
}