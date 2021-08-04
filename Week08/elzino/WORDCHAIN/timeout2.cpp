#include <bits/stdc++.h>

using namespace std;

int N;

string words[100];

vector<vector<pair<int, int>>> adj;
vector<vector<pair<int, int>>> tempAdj;

vector<int> result;

void getEulerCircuit(int from) {
    while (tempAdj[from].size() > 0) {
        auto p = tempAdj[from].back();
        tempAdj[from].pop_back();
        getEulerCircuit(p.first);
    }
    result.push_back(from);
    return;
}

void solve() {
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++) {
            // check if starting from i and finishing at j is possible
            result.clear();
            tempAdj = vector<vector<pair<int, int>>>(adj);
            tempAdj[j].push_back({i, 0});
            getEulerCircuit(i);
            reverse(result.begin(), result.end());
            if (result.size() == N + 2 && result[0] == i && result[result.size()-1] == i) {
                int endIndex = -1;
                int index = 0;
                while (true) {
                    int p = index;
                    int q = (index+1) % (N+2);
                    if (result[p] == j && result[q] == i) {
                        endIndex = p;
                        break;
                    }
                    index = q;
                }
                index = (endIndex+1) % (N+1);
                tempAdj = vector<vector<pair<int, int>>>(adj);
                while (index != endIndex) {
                    int p = index;
                    int q = (index+1) % (N+1);
                    auto &edges = tempAdj[result[p]];
                    auto iter = edges.begin();
                    while (iter != edges.end()) {
                        if (iter->first == result[q])
                            break;
                        iter++;
                    }
                    cout << words[iter->second] << " ";
                    edges.erase(iter);
                    index = q;
                }
                cout << endl;
                return;
            }
        }
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    int C;
    cin >> C;
    words[0] = "";
    for (int c = 0; c < C; c++) {
        cin >> N;
        adj = vector<vector<pair<int, int>>>(26, vector<pair<int, int>>());
        for (int i = 1; i <= N; i++) {
            cin >> words[i];
            int wlen = words[i].length();
            adj[words[i][0]-'a'].push_back({words[i][wlen-1]-'a', i});
        }
        solve();
    }
}
