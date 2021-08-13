#include <bits/stdc++.h>
using namespace std;
vector<int> input;

map<vector<int>, int> preCalc(int n) {
    queue<vector<int> > q;
    map<vector<int>, int> g;
    vector<int> finalSeq(n, 0);
    for(int i = 0; i < n; i++) finalSeq[i] = i+1;

    g[finalSeq] = 0; 
    q.push(finalSeq);
    while(!q.empty()) {
        vector<int> here = q.front();
        int dist = g[here];
        q.pop();

        for(int i = 0; i <= n-2; i++) 
            for(int j = i+2; j <= n; j++) {
                reverse(here.begin()+i, here.begin()+j);
                if(g.count(here) == 0) {
                    g[here] = dist+1;
                    q.push(here);
                }
                reverse(here.begin()+i, here.begin()+j);
            }
    }
    return g;
}

void normalize() {
    vector<int> old = input;
    input = vector<int>(old.size(),1);
    for(int i = 0; i < old.size(); i++) {
        for(int j = 0; j < old.size(); j++) {
            if(i == j) continue;
            if(old[i] > old[j]) input[i]++;
        }
    }
}

int main() {
    int T; cin >> T;
    vector<map<vector<int>, int> > res(9, map<vector<int>, int>());
    for(int i = 1; i <= 8; i++) 
        res[i] = preCalc(i);
    for(int t = 0; t < T; t++) {
        int n; cin >> n;
        input = vector<int>(n, 0);
        for(int i = 0; i < n; i++) cin >> input[i];
        normalize();
        cout << res[n][input] << endl;
    }
    return 0;
}