#include <bits/stdc++.h>
using namespace std;

int T, N, M;
string D;
vector<int> d, parent, choice;

bool checkValid(int num) { return num >= N + M; }

int next(int u, int x) {
    int v = 10 * u + x;
    if (v >= N) return N + v % N;
    return v % N;
}

void makeGraph() {
    queue<int> q;
    q.push(0);
    parent[0] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < d.size(); i++) {
            int v = next(u, d[i]);
            if (parent[v] == -1) {
                q.push(v);
                parent[v] = u;
                choice[v] = d[i];
            }
        }
    }
}

int main() {
    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> D >> N >> M;
        d.clear();
        sort(D.begin(), D.end());
        for (int i = 0; i < D.size(); i++)
            d.push_back(D[i] - '0');
        
        parent = vector<int>(2 * N, -1);
        choice = vector<int>(2 * N, -1);
        makeGraph();

        if (parent[N + M] == -1) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            string ret;
            int v = N + M;

            while (parent[v] != v) {
                ret += (char)(choice[v] + '0');
                v = parent[v];
            }
            reverse(ret.begin(), ret.end());
            cout << ret << endl;
        }
    }
}