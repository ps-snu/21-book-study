// https://remocon33.tistory.com/565
#include <bits/stdc++.h>
using namespace std;
string D;
int N, M;

void process() {
    vector<int> parent(2*N, -1), choice(2*N, -1);
    queue<int> Q;
    Q.push(0);
    parent[0] = 0;

    while (!Q.empty()) {
        int f = Q.front(); Q.pop();
        for (auto d : D) {
            int v = 10*f + d-'0';
            v = (v < N) ? v : (N + v%N);
            if (parent[v] == -1) {
                Q.push(v);
                parent[v] = f;
                choice[v] = d-'0';
            }
        }
    }
    int v = N + M;
    if (parent[v] == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    
    string res = "";
    while (parent[v] != v) {
        res += (choice[v] + '0');
        v = parent[v];
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> D >> N >> M;
        sort(D.begin(), D.end());
        process();
    }
    return 0;
}
