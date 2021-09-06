#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> i_pii;


int N, M;

struct DisjointSet {
    vector<int> parents;
    vector<int> ranks;
    DisjointSet(int N) : parents(N), ranks(N, 1) {
        for (int i = 0; i < N; i++)
            parents[i] = i;
    }
    int find(int u) {
        if (parents[u] == u)
            return u;
        else
            return parents[u] = find(parents[u]);
    }
    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        if (ranks[u] > ranks[v])
            swap(u, v);
        parents[u] = v;
        if (ranks[u] == ranks[v])
            ranks[v]++;
    }
};

int minUpperBound(vector<i_pii>& adj, int low) {
    int ret;
    DisjointSet ds(N);
    for (i_pii p : adj) {
        int distance = p.first;
        int u = p.second.first, v = p.second.second;
        if (distance < low)
            continue;
        if (ds.find(u) == ds.find(v))
            continue;
        ret = distance;
        ds.merge(u, v);
        if (ds.find(0) == ds.find(N-1))
            break;
    }
    if (ds.find(0) == ds.find(N-1))
        return ret;
    else
        return 100000;
}



int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> N >> M;
        vector<i_pii> adj;
        for (int i = 0; i < M; i++) {
            int u, v, d;
            cin >> u >> v >> d;
            adj.push_back({d, {u, v}});
        }
        sort(adj.begin(), adj.end());

        int result = 100000;
        int lastLow = -1;
        for (i_pii p : adj) {
            int low = p.first;
            if (lastLow == low)
                continue;
            result = min(result, minUpperBound(adj, low) - low);
            lastLow = low;
        }
        cout << result << endl;
    }
}
