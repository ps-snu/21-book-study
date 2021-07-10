#include <bits/stdc++.h>

using namespace std;

#define MASK 1<<15
#define BIGNUM 1000000007

int dp[MASK][20][2];
long long ten_pow[16];

long long e;
int m;
string es;

int count_ones(int mask) {
    int result = 0;
    for (int i = 0; i < es.size(); i++) {
        if (mask & 1) result += 1;
        mask = mask >> 1;
    }
    return result;
}

int find_zero_index(int mask) {
    for (int i = 0; i < es.size(); i++) {
        if (!(mask & 1)) return i;
        mask = mask >> 1;
    }
    return 0;
}

int i2d(int index) {
    return es[index] -'0';
}

int process(int mask, int remainder, int less) {
    int &result = dp[mask][remainder][less];
    if (result != -1) return result;
    result = 0;
    int index = count_ones(mask);
    if (index == es.size()-1) {
        if (less) return 0;
        return result = (remainder + i2d(find_zero_index(mask))) % m == 0;
    }
    set<int> done;
    if (less) {
        for (int i = 0; i < es.size(); i++) {
            if (mask >> i & 1 || es[i] > es[index]) continue;
            if (done.find(i2d(i)) != done.end()) continue;
            result += process(mask | 1<<i, (remainder + i2d(i) * ten_pow[es.size()-1-index]) % m, es[i] == es[index]);
            result %= BIGNUM;
            done.insert(i2d(i));
        }
    } else {
        for (int i = 0; i < es.size(); i++) {
            if (mask >> i & 1) continue;
            if (done.find(i2d(i)) != done.end()) continue;
            result += process(mask | 1<<i, (remainder + i2d(i) * ten_pow[es.size()-1-index]) % m, 0);
            result %= BIGNUM;
            done.insert(i2d(i));
        }
    }
    return result;
}

int main() {
    int C;
    cin >> C;
    ten_pow[0] = 1;
    for (int i = 1; i <= 15; i++)
        ten_pow[i] = 10 * ten_pow[i-1];
    for (int c = 0; c < C; c++) {
        cin >> e >> m;
        es = to_string(e);
        memset(dp, -1, sizeof(dp));
        cout << process(0, 0, 1) << endl;
    }
}
