#include <bits/stdc++.h>
using namespace std;
int k, n;

int process() {
    queue<int> Q;
    unsigned int t = 1983;
    int s = 0, c = 0;
    for (int i = 0; i < n; i++) {
        int sig = t % 10000 + 1;
        Q.push(sig);
        s += sig;
        t = (t*214013 + 2531011);
        while (s > k && !Q.empty()) {
            s -= Q.front(); Q.pop();
        }
        if (s == k) c++;
    }
    return c;
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> k >> n;
        cout << process() << endl;
    }
    return 0;
}
