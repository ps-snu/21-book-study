#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > v;
int total, start, fin;

int mask(int state, int n, int stick_n) {
    int tmp = stick_n << 2*n;
    state = state | tmp;
    return state;
}

vector<int> getTop(int state) {
    bool finded[4] = {false, false, false, false};
    vector<int> res(4, -1);
    for(int i = 0; i < total; i++) {
        int stick_n = state >> 2*i & 3;
        if(!finded[stick_n]) {
            res[stick_n] = i;
            finded[stick_n] = true;
        }
    }
    return res;
}

// move i -> j stick
vector<int> move(int state) {
    vector<int> res;
    vector<int> top = getTop(state);

    for(int i = 0; i < 4; i++) {
        if(top[i] == -1) continue;
        for(int j = 0; j < 4; j++) {
            if(i == j) continue;
            if(top[i] < top[j] || top[j] == -1) {
                int new_state;
                new_state = (state & ~(3 << (top[i]*2))) | (j << (top[i]*2));
                res.push_back(new_state);
            }
        }
    }
    return res;
}

int sign(int x) {
    return x > 0 ? 1 : -1;
}

int solve() {
    start = 0;
    for(int i = 0; i < 4; i++) 
        for(auto e : v[i])
            start = mask(start, e, i);
    fin = 0;
    for(int i = 0; i < total; i++)
        fin = mask(fin, i, 3);

    // bidir search
    static int discovered[1<<24]; memset(discovered, 0, sizeof(discovered));
    discovered[start] = 1; discovered[fin] = -1;
    queue<int> q;
    q.push(start); q.push(fin);

    while(!q.empty()) {
        int here = q.front(); q.pop();
        
        vector<int> res = move(here);
        for(auto state : res) {
            if(discovered[state] == 0) {
                discovered[state] = discovered[here] > 0 ? discovered[here]+1 : discovered[here]-1;
                q.push(state);
            }
            else if(sign(discovered[state]) * sign(discovered[here]) < 0) 
                return abs(discovered[state]) + abs(discovered[here]) - 1;
        }
    }
    return -1;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        v = vector<vector<int> >(4, vector<int>());
        cin >> total;
        for(int i = 0; i < 4; i++) {
            int n; cin >> n;
            for(int j = 0; j < n; j++) {
                int one; cin >> one;
                v[i].push_back(one-1);
            }
        }
        cout << solve() << endl;
    }
    return 0;
}