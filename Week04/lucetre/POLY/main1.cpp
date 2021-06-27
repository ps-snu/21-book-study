#include <bits/stdc++.h>
#define MOD 10000000
#define M 100
using namespace std;
int P[M+1];

int main() {
	P[1] = 1;
	P[2] = 2;
	P[3] = 6;
	P[4] = 19;
    for (int i = 5; i <= M; i++)
        P[i] = ((5*P[i-1])%MOD - (7*P[i-2])%MOD + (4*P[i-3])%MOD + MOD)%MOD;
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int n; cin >> n;
        cout << P[n] << endl;
    }
}
