#include <bits/stdc++.h>
#define MAX_V 12
#define MAX_E 100
using namespace std;
int V, E;
int wins[MAX_V], match[MAX_E][2];
int capacity[2+MAX_V+MAX_E][2+MAX_V+MAX_E], flow[2+MAX_V+MAX_E][2+MAX_V+MAX_E];

int networkFlow(int source, int sink) {
    memset(flow, 0, sizeof(flow));
    int totalFlow = 0;
    while(1) {
        vector<int> parent(2+MAX_V+MAX_E, -1); 
        parent[source] = source;
        queue<int> q; 
        q.push(source);
        while(!q.empty() && parent[sink] == -1) {
            int here = q.front();
            q.pop();
            for(int there = 0; there < 2+V+E; there++) 
                if((capacity[here][there] - flow[here][there] > 0) && (parent[there] == -1)) {
                    q.push(there);
                    parent[there] = here;
                }
        } 
        if(parent[sink] == -1) break;

        int amount = 987654321;
        for(int p = sink; p != source; p = parent[p]) 
            amount = min(amount, capacity[parent[p]][p] - flow[parent[p]][p]);
        for(int p = sink; p != source; p = parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }
        totalFlow += amount;
    }
    return totalFlow;
}

bool solve(int totalWins) {
    if(*max_element(wins+1, wins+V) >= totalWins) return false;
    
    memset(capacity, 0, sizeof(capacity));

    for(int i = 0; i < E; i++) {
        capacity[0][2+i] = 1;   // source(0) to match
        for(int j = 0; j < 2; j++) 
            capacity[2+i][2+E+match[i][j]] = 1; // match to person
    }
    for(int i = 0; i < V; i++) {
        int maxWin = (i == 0) ? totalWins : totalWins-1;
        capacity[2+E+i][1] = maxWin - wins[i];  // person to sink(1)
    }

    return networkFlow(0,1) == E;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> V >> E;
        for(int v = 0; v < V; v++)
            cin >> wins[v];
        for(int e = 0; e < E; e++) {
            int u, v; cin >> u >> v;
            match[e][0] = u;
            match[e][1] = v;
        }
        int totalWins = wins[0];
        while(!solve(totalWins++)) {}
        if(capacity[2+E][1] - flow[2+E][1] > 0) cout <<  -1 << endl;
        else cout << flow[2+E][1] + wins[0] << endl;
    }
    return 0;
}