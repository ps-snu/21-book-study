#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N, M;
int wins[12];
pii games[100];

int capacity[114][114];
int flow[114][114];
int totalFlow;

void buildGraph() {
    memset(capacity, 0, sizeof(capacity));
    memset(flow, 0, sizeof(flow));
    totalFlow = 0;

    int source = 0;
    int sink = M + N + 1;
    for (int i = 1; i <= M; i++)
        capacity[source][i] = 1;
    for (int i = 0; i < M; i++) {
        int a = games[i].first;
        int b = games[i].second;
        capacity[i+1][M+a+1] = 1;
        capacity[i+1][M+b+1] = 1;
    }
}

int networkFlow() {
    int v = M + N + 2;
    int source = 0;
    int sink = M + N + 1;
    while (true) {
        vector<int> parents(v, -1);
        queue<int> q;
        parents[source] = source;
        q.push(source);
        while (!q.empty() && parents[sink] == -1) {
            int here = q.front();
            q.pop();
            for (int there = 0; there < v; there++) {
                int restCapacity = capacity[here][there] - flow[here][there];
                if (restCapacity > 0 && parents[there] == -1) {
                    parents[there] = here;
                    q.push(there);
                }
            }
        }
        if (parents[sink] == -1)
            break;
        int amount = 100000;
        for (int i = sink; i != source; i = parents[i])
            amount = min(amount, capacity[parents[i]][i] - flow[parents[i]][i]);
        for (int i = sink; i != source; i = parents[i]) {
            flow[parents[i]][i] += amount;
            flow[i][parents[i]] -= amount;
        }
        totalFlow += amount;
    }
    return totalFlow;
}

bool canWinWith(int totalWin) {
    for (int i = 1; i < N; i++)
        if (wins[i] >= totalWin)
            return false;

    // build last layer of graph
    int source = 0;
    int sink = M + N + 1;
    capacity[M+1][sink] = totalWin - wins[0];
    for (int i = 1; i < N; i++)
        capacity[M+i+1][sink] = totalWin - 1 - wins[i];
    
    if (networkFlow() == M && flow[M+1][sink] == capacity[M+1][sink])
        return true;
    else
        return false;
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> N >> M;
        for (int i = 0; i < N; i++)
            cin >> wins[i];
        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;
            games[i] = {a, b};
        }

        buildGraph();
        bool impossible = true;
        for (int w = wins[0]; w <= wins[0] + M; w++) {
            if (canWinWith(w)) {
                cout << w << endl;
                impossible = false;
                break;
            }
        }
        if (impossible)
            cout << -1 << endl;
    }
}
