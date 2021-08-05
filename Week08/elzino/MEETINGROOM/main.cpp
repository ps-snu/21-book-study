#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;

vector<int> sccId;
vector<int> discovered;
int sccCounter;
int discoverCounter;
stack<int> notYetScc;

int mtime[200][2];
int N;

bool disjoint(int i, int j) {
    if (mtime[i][0] >= mtime[j][1] || mtime[j][0] >= mtime[i][1])
        return true;
    return false;
}

void buildGraph() {
    adj.clear();
    adj.resize(4*N);
    for (int i = 0; i < 2*N; i += 2) {
        int j = i + 1;
        adj[2*i+1].push_back(2*j);
        adj[2*j+1].push_back(2*i);
        adj[2*i].push_back(2*j+1);
        adj[2*j].push_back(2*i+1);
    }
    for (int i = 0; i < 2*N; i++) {
        for (int j = 0; j < i; j++) {
            if (!disjoint(i, j)) {
                adj[2*i].push_back(2*j+1);
                adj[2*j].push_back(2*i+1);
            }
        }
    }
}

int scc(int here) {
    int ret = discovered[here] = discoverCounter++;
    notYetScc.push(here);
    for (int there : adj[here]) {
        if (discovered[there] == -1)
            ret = min(ret, scc(there));
        else if (sccId[there] == -1)
            ret = min(ret, discovered[there]);
    }
    if (ret == discovered[here]) {
        while (true) {
            int t = notYetScc.top();
            notYetScc.pop();
            sccId[t] = sccCounter;
            if (t == here) break;
        }
        sccCounter++;
    }
    return ret;
}

vector<int> tarjanSCC() {
    sccId = discovered = vector<int>(4*N, -1);
    sccCounter = discoverCounter = 0;
    for (int i = 0; i < 4*N; i++)
        if (discovered[i] == -1)
            scc(i);
    return sccId;
}

vector<int> solve2SAT() {
    vector<int> label = tarjanSCC();
    for (int i = 0; i < 4*N; i+=2) {
        if (label[i] == label[i+1])
            return vector<int>();
    }
    vector<int> ret(2*N, -1);
    vector<pair<int, int>> order;

    for (int i = 0; i < 4*N; i++)
        order.push_back({-label[i], i});
    sort(order.begin(), order.end());

    for (auto p : order) {
        int vertex = p.second;
        int var = vertex / 2, isTrue = (vertex % 2) == 0;
        if (ret[var] != -1) continue;
        ret[var] = !isTrue;
    }

    return ret;
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> N;
        for (int i = 0; i < 2 * N; i += 2) {
            cin >> mtime[i][0] >> mtime[i][1];
            cin >> mtime[i+1][0] >> mtime[i+1][1];
        }
        buildGraph();
        vector<int> result = solve2SAT();

        if (result.size() == 0)
            cout << "IMPOSSIBLE" << endl;
        else {
            cout << "POSSIBLE" << endl;
            int i = 0;
            for (int isTrue : result) {
                if (isTrue)
                    cout << mtime[i][0] << " " << mtime[i][1] << endl;
                i++;
            }
        }
    }
}
