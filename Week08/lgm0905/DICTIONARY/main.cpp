#include <bits/stdc++.h>
#define M 1000
using namespace std;
int n, a[26][26], visited[26];
string in[M+1];
vector<int> res;

void init() {
    memset(a, 0, sizeof(a));
    memset(visited, 0, sizeof(visited));
    res.clear();
}

void makeGraph() {
    for(int i = 0; i < n-1; i++) {
        int loopsize = min(in[i].size(), in[i+1].size());
        for(int j = 0; j < loopsize; j++) {
            if(in[i][j] != in[i+1][j]) {
                int u = in[i][j]-'a'; 
                int v = in[i+1][j]-'a';
                a[u][v] = 1;
                break;
            }
        }
    }
}

void printGraph() {
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) 
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

void dfs(int idx) {
    visited[idx] = 1;
    for(int i = 0; i < 26; i++) {
        if(idx == i) continue;
        if(a[idx][i] && !visited[i]) dfs(i);
    }
    res.push_back(idx);
}

void solve() {    
    for(int i = 0; i < 26; i++) {
        bool trip = false;
        for(int j = 0; j < 26; j++) {
            if(a[i][j] == 1) {
                trip = true;
                break;
            } 
        }
        if(trip && !visited[i]) {
            dfs(i);
        }
    }
    reverse(res.begin(), res.end());

    // 역방향 간선 찾기
    for(int i = 0; i < res.size(); i++) 
        for(int j = i+1; j < res.size(); j++) 
            if(a[res[j]][res[i]]) res = vector<int>();

    // print
    if(res.empty()) {
        cout << "INVALID HYPOTHESIS" << endl;
        return;
    }
    int printed[26]; memset(printed, 0, sizeof(printed));
    for(auto e : res) {
        cout << (char)('a'+e);
        printed[e] = 1;
    }
    for(int i = 0; i < 26; i++) {
        if(!printed[i]) cout << (char)('a'+i);
    }
    cout << endl;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        init();
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> in[i];
        makeGraph();
        solve();
    }
    return 0;
}