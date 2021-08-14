#include <bits/stdc++.h>
using namespace std;

int C, N, n, num;
int steps[1 << 24];

int getState(int state, int no) {
    return (state >> (2 * no)) & 3;
}

int setState(int state, int no, int value) {
    return (state & ~(3 << (2 * no))) | (value << (2 * no));
}

vector<int> adjs(int state) {
    vector<int> adj;

    int top[4] = {-1, -1, -1, -1};
    for (int i = N - 1; i >= 0; i--) {
        top[getState(state, i)] = i;
    }

    // i -> j
    for (int i = 0; i < 4; i++) {
        if (top[i] == -1) continue;

        for (int j = 0; j < 4; j++) {
            if (top[j] == -1 || top[i] < top[j]) {
                int v = setState(state, top[i], j);
                adj.push_back(v);
            }
        }
    }

    return adj;
}

int sgn(int x) { if (!x) return 0; return x < 0 ? -1 : 1; }
int inc(int x) { return x < 0 ? x - 1 : x + 1; }

int bfs(int init, int final) {
    if (init == final) return 0;
    queue<int> q;
    memset(steps, 0, sizeof(steps));
    
    q.push(init);
    q.push(final);
    steps[init] = 1;
    steps[final] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vector<int> adj = adjs(u);

        for (int i = 0; i < adj.size(); i++) {
            int v = adj[i];

            if (steps[v] == 0) {
                steps[v] = inc(steps[u]);
                q.push(v);
            } else if (sgn(steps[u]) * sgn(steps[v]) < 0) {
                return abs(steps[u]) + abs(steps[v]) - 1;
            }
        }
    }

    return -1;
}

int main() {
    cin >> C;
    for (int tc = 0; tc < C; tc++) {
        cin >> N;
        int init = 0;
        int final = 0;

        for (int i = 0; i < 4; i++) {
            cin >> n;
            for (int j = 0; j < n; j++) {
                cin >> num;
                init = setState(init, num - 1, i);
            }
        }

        for (int i = 0; i < N; i++) {
            final = setState(final, i, 3);
        }

        int result = bfs(init, final);
        cout << result << endl;
    }
}