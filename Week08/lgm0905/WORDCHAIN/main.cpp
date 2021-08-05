#include <bits/stdc++.h>
#define M 100
using namespace std;
int n;
int adj[26][26], in[26], out[26];
vector<string> edges[26][26];

void init() {
    memset(adj, 0, sizeof(adj));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    for(int i = 0; i < 26; i++) 
        for(int j = 0; j < 26; j++)
            edges[i][j].clear();
}

void dfs(int idx, vector<int>& circuit) {
    for(int i = 0; i < 26; i++) {
        while(adj[idx][i] > 0) {
            adj[idx][i]--;
            dfs(i, circuit);
        }
    }
    circuit.push_back(idx);
}

vector<int> findEuler() {
    vector<int> circuit;
    // euler trail
    for(int i = 0; i < 26; i++) {
        if(out[i] == in[i]+1) {
            dfs(i, circuit);
            return circuit;
        }
    }

    // euler circuit
    for(int i = 0; i < 26; i++) {
        if(out[i]) {
            dfs(i, circuit);
            return circuit;
        }
    }

    return circuit;
}

bool checkEuler() {
    int plus1 = 0, minus1 = 0;
    for(int i = 0; i < 26; i++) {
        int delta = out[i]-in[i];
        if(delta < -1 || 1 < delta) return false;
        if(delta == 1) plus1++;
        if(delta == -1) minus1++;
    }
    return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}

string solve() {
    if(!checkEuler()) return "IMPOSSIBLE";
    vector<int> circuit = findEuler();
    if(circuit.size() != n+1) return "IMPOSSIBLE";

    reverse(circuit.begin(), circuit.end());
    string ret;
    for(int i = 1; i < circuit.size(); i++) {
        int a = circuit[i-1], b = circuit[i];
        if(ret.size()) ret += " ";
        ret += edges[a][b].back();
        edges[a][b].pop_back();
    }
    return ret;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        init(); cin >> n;
        for(int i = 0; i < n; i++) {
            string w; cin >> w;
            int u = w[0]-'a';
            int v = w[w.size()-1]-'a';
            adj[u][v]++; 
            out[u]++; in[v]++;
            edges[u][v].push_back(w);
        }
        cout << solve() << endl;
    }
}