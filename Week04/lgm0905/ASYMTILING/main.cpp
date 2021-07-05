#include <bits/stdc++.h>
#define MOD 1000000007
#define M 100
using namespace std;
int n;
long as[M], s[M];

int solve() {
    s[0] = 0; s[1] = 1; s[2] = 2;
    for(int i = 3; i <= n; i++) {
        s[i] = (s[i-1] + s[i-2]) % MOD;
        if(i % 2 == 0) as[i] = (s[i/2] * (s[i/2]-1)) + (s[(i-2)/2] * (s[(i-2)/2]-1));
        else as[i] = (s[(i-1)/2] * (s[(i-1)/2]-1))+ (s[(i-1)/2] * s[(i+1)/2] * 2);
        as[i] %= MOD;
    }
    return as[n];
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        memset(as, 0, sizeof(as));
        cin >> n;
        cout << solve() << endl;
    }
    return 0;
}