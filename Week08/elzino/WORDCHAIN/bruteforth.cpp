#include <bits/stdc++.h>

using namespace std;

int N;

string words[100];

int adj[100][100];
int visit[100];

vector<int> result;


bool getPath(int from, int to) {
    visit[from] = 1;
    result.push_back(from);
    if (from == to) {
        if (result.size() == N) return true;
    } else {
        for (int neighbor = 0; neighbor < N; neighbor++)
            if (adj[from][neighbor] && !visit[neighbor])
                if (getPath(neighbor, to)) return true;
    }
    visit[from] = 0;
    result.pop_back();
    return false;
}

void solve() {
    result.clear();
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < N-1; i++)
        for (int j = i+1; j < N; j++) {
            // check if starting from i and finishing at j is possible
            if (getPath(i, j)) {
                for (auto index : result)
                    cout << words[index] << " ";
                cout << endl;
                return;
            }
        }
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> N;
        memset(adj, 0, sizeof(adj));
        for (int i = 0; i < N; i++)
            cin >> words[i];
        for (int i = 0; i < N-1; i++)
            for (int j = i+1; j < N; j++) {
                int iwlen = words[i].length();
                int jwlen = words[j].length();
                if (words[i][iwlen-1] == words[j][0])
                    adj[i][j] = 1;
                if (words[i][0] == words[j][jwlen-1])
                    adj[j][i] = 1;
            }
        solve();
    }
}
