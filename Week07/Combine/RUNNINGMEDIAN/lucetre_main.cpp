#include <bits/stdc++.h>
#define MOD 20090711
using namespace std;
priority_queue<int, vector<int>> L;
priority_queue<int, vector<int>, greater<int>> R;
long long A;
int n, a, b;

int next(long long prev) {
    if (prev == -1) return 1983;
    return (prev*a + b) % MOD;
}

void process() {
    if (L.size() == 0) {
        L.push(A);
        return;
    }
    if (L.size() == R.size()) {
        if (R.top() < A) {
            L.push(R.top()); R.pop();
            R.push(A);
        }
        else L.push(A);
    }
    else if (L.size() > R.size()) {
        if (L.top() > A) {
            R.push(L.top()); L.pop();
            L.push(A);
        }
        else R.push(A);
    }
    
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n >> a >> b;
        int res = 0;
        A = -1;
        for (int i = 0; i < n; i++) {
            A = next(A);
            process();
            res = (res + L.top()) % MOD;
        }
        cout << res << endl;
        L = priority_queue<int, vector<int>>();
        R = priority_queue<int, vector<int>, greater<int>>();
    }
    return 0;
}
