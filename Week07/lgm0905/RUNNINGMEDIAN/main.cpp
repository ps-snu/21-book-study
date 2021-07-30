#include <bits/stdc++.h>
#define M 200000
#define MOD 20090711
using namespace std;
int n, a, b, seq[M+1];
priority_queue< int, vector<int>, less<int> > max_h;
priority_queue< int, vector<int>, greater<int> > min_h;

void genSeq() {
    memset(seq, 0, sizeof(seq));
    seq[0] = 1983;
    for(int i = 1; i < n; i++) {
        long long tmp = ((long long)seq[i-1] * a + b) % MOD;
        seq[i] = (int)tmp;
    }
}

void solve() {
    int ret = 0;  

    max_h.push(seq[0]);
    ret += max_h.top();
    for(int i = 1; i < n; i++) {
        if(i%2 == 1) {
            if(max_h.top() > seq[i]) {
                min_h.push(max_h.top());
                max_h.pop();
                max_h.push(seq[i]);
            }
            else min_h.push(seq[i]);
        }
        else {
            max_h.push(seq[i]);
            if(max_h.top() > min_h.top()) {
                int maxtop = max_h.top();
                int mintop = min_h.top();
                max_h.pop(); min_h.pop();
                max_h.push(mintop); min_h.push(maxtop);
            }
        }
        ret += max_h.top();
        ret %= MOD;
    }
    cout << ret << endl;

    // clear
    priority_queue< int, vector<int>, less<int> > new_max_h;
    priority_queue< int, vector<int>, greater<int> > new_min_h;
    swap(max_h, new_max_h);
    swap(min_h, new_min_h);
    return;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> n >> a >> b;
        genSeq();
        solve();
        
    }
    return 0;
}