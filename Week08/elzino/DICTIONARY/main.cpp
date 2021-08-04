#include <bits/stdc++.h>

using namespace std;

int N;

string result;
int visited[26];

void dfs(vector<set<int>>& adjlist, int index) {
    if (visited[index]) return;
    visited[index] = true;
    set<int>& edges = adjlist[index];
    for (auto i : edges)
        if (!visited[i])
            dfs(adjlist, i);
    result += ('a' + index);
    return;
}

void dfs_total(vector<set<int>>& adjlist) {
    for (int i = 0; i < 26; i++)
        if (!visited[i])
            dfs(adjlist, i);
}

bool isThereDependency(vector<set<int>>& adjlist) {
    int len = result.size();
    for (int i = 0; i < len-1; i++) {
        auto edges = adjlist[result[i]-'a'];
        for (int j = i+1; j < len; j++) {
            if (edges.count(result[j]-'a') > 0)
                return true;
        }
    }
    return false;
}

int main() {
    int C;
    cin >> C; 
    for (int c = 0; c < C; c++) {
        cin >> N;
        string prev;
        cin >> prev;
        set<int> empty;
        vector<set<int>> adjlist(26, empty);
        for (int i = 1; i < N; i++) {
            string current;
            cin >> current;
            for (int j = 0; j < min(prev.size(), current.size()); j++) {
                if (prev[j] == current[j]) continue;
                adjlist[current[j]-'a'].insert(prev[j]-'a');
                break;
            }
            prev = current;
        }
        memset(visited, 0, sizeof(visited));
        result = "";
        dfs_total(adjlist);
        if (isThereDependency(adjlist))
            cout << "INVALID HYPOTHESIS" << endl;
        else
            cout << result << endl;
    }
}
