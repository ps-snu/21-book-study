#include <bits/stdc++.h>
using namespace std;

int C, N;
string words[1000];
bool acyclic;
int adj[26][26];
bool visited[26];
vector<int> sorted;

int alphaNum(char c) {
    return c - 'a';
}

char numAlpha(int n) {
    return 'a' + n;
}

void setAdj() {
    for (int i = 0; i < N - 1; i++) {
        int len1 = words[i].size();
        int len2 = words[i + 1].size();

        for (int j = 0; j < min(len1, len2); j++) {
            if (words[i][j] == words[i + 1][j])
                continue;
            
            int alpha1 = alphaNum(words[i][j]);
            int alpha2 = alphaNum(words[i + 1][j]);
                adj[alpha1][alpha2] =1;
            break;
        }
    }
}

void dfs(int v) {
    visited[v] = true;

    for (int i = 0; i < 26; i++) {
        if (!visited[i] && adj[v][i])
            dfs(i);
    }
    sorted.push_back(v);
}

void topologicalSort() {
    for (int i = 0; i < 26; i++) {
        if (!visited[i])
            dfs(i);
    }
    reverse(sorted.begin(), sorted.end());

    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (adj[sorted[j]][sorted[i]]) {
                acyclic = false;
                return;
            }
        }
    }
}

int main() {
    cin >> C;
    for (int i = 0; i < C; i++) {
        cin >> N;
        for (int j = 0; j < N; j++)
            cin >> words[j];

        memset(adj, 0, sizeof(adj));
        memset(visited, false, sizeof(visited));
        sorted.clear();
        acyclic = true;

        setAdj();
        topologicalSort();

        if (!acyclic) {
            cout << "INVALID HYPOTHESIS" << endl;
        } else {
            for (int i = 0; i < 26; i++)
                cout << numAlpha(sorted[i]);
            cout << endl;
        }
    }
}