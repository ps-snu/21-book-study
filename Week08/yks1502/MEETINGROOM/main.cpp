#include <bits/stdc++.h>
using namespace std;

int C, N, sc, vc;
int a[100], b[100], c[100], d[100];
vector<vector<int>> adj;
vector<int> sccId, discovered;
stack<int> s;

int scc(int v) {
    int ret = discovered[v] = vc++;
    s.push(v);

    for (int i = 0; i < adj[v].size(); i++) {
        int u = adj[v][i];

        if (discovered[u] == -1)
            ret = min(ret, scc(u));
        else if (sccId[u] == -1)
            ret = min(ret, discovered[u]);
    }

    if (ret == discovered[v]) {
        while (true) {
            int t = s.top();
            s.pop();
            sccId[t] = sc;
            if (t == v) break;
        }
        sc++;
    }

    return ret;
}

void tarjanSCC() {
    sccId = discovered = vector<int>(N * 2, -1);
    sc = vc = 0;
    while (!s.empty()) s.pop();

    for (int i = 0; i < N * 2; i++) {
        if (discovered[i] == -1)
            scc(i);
    }
}

bool disjoint(int i, int j) {
    return b[i] <= c[i] || d[i] <= a[i];
}

void setAdj() {
    adj = vector<vector<int>>(100, vector<int>());

    for (int i = 0; i < N * 2; i += 2) {
        int j = i + 1;
        adj[i * 2 + 1].push_back(j * 2);
        adj[j * 2 + 1].push_back(i * 2);
    }

    for (int i = 0; i < N * 2; i++) {
        for (int j = i + 1; j < N; j++) {
            if (!disjoint(i, j)) {
                adj[i * 2].push_back(j * 2 + 1);
                adj[j * 2].push_back(i * 2 + 1);
            }
        }
    }
}

void print(vector<bool>& value) {
    cout << "POSSIBLE" << endl;

    for (int i = 0; i < N; i++) {
        if (value[i * 2])
            cout << a[i] << " " << b[i] << endl;
        else
            cout << c[i] << " " << d[i] << endl;
    }
}

void solve2SAT() {
    tarjanSCC();

    for (int i = 0; i < N * 2; i += 2)
        if (sccId[i] == sccId[i + 1]) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    
    vector<bool> value(N * 2, false);
    vector<pair<int, int>> order;

    for (int i = 0; i < N * 2; i++)
        order.push_back(make_pair(-sccId[i], i));
    sort(order.begin(), order.end());

    for (int i = 0; i < N * 2; i++) {
        int v = order[i].second;
        int team = v / 2;
        bool isTrue = v % 2 == 0;

        if (value[team] != -1) continue;
        value[team] = !isTrue;
    }

    print(value);
}

int main() {
    cin >> C;
    for (int tc = 0; tc < C; tc++) {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> a[i] >> b[i] >> c[i] >> d[i];

        setAdj();
        solve2SAT();
    }
}