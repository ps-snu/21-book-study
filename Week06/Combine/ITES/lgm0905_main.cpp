#include <bits/stdc++.h>
#define N_MAX 50000000
using namespace std;
int n, k, sig;
long long a;
queue<int> q;

int gen() {
    long long mod = 4294967296;
    sig = a % 10000 + 1;
    a = (a * 214013 + 2531011) % mod;
    return sig;
}

int solve() {
    int sum, tail, ret;
    tail = 1; sum = 0; ret = 0;
    for(int i = 1; i <= n; i++) {
        while(sum < k && tail < n+1) {
            int gennum = gen();
            sum += gennum;
            q.push(gennum);
            tail++;
        }
        if(sum == k) ret++;
        sum -= q.front();
        q.pop();
    }
    return ret;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        a = 1983;
        q = queue<int>();
        cin >> k >> n;
        cout << solve() << endl;
    }
    return 0;
}