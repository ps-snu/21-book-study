#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<double, pii> d_pii;

int N, M;

int x[500];
int y[500];

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

double compute_distance (int u, int v) {
    return sqrt(pow(x[u] - x[v], 2) + pow(y[u] - y[v], 2));
}

vector<d_pii> build_adj() {
    vector<d_pii> adj;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            double dist = compute_distance(i, j);
            adj.push_back({dist, {i, j}});
        }
    }
    return adj;
}

int main() {
    cout << fixed;
    cout.precision(10);

    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> N >> M;
        for (int i = 0; i < N; i++)
            cin >> x[i];
        for (int i = 0; i < N; i++)
            cin >> y[i];

        auto adj = build_adj();
        sort(adj.begin(), adj.end());
        DisjointSet ds(N);
        double result = 0;

        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            ds.merge(u, v);
        }
        for (d_pii p : adj) {
            double distance = p.first;
            int u = p.second.first, v = p.second.second;
            if (ds.find(u) == ds.find(v))
                continue;
            result += distance;
            ds.merge(u, v);
        }
        cout << result << endl;
    }
}
