#include <bits/stdc++.h>
#define M 1000000000
#define GEN 50
using namespace std;
int n, p, l, genlen[GEN+1];
string w;

void calc_genlen() {
    genlen[0] = 1;
    for(int i = 1; i <= 50; i++) 
        genlen[i] = min(M, 2 * genlen[i-1] + 2);
}

void solve(string str, int gen) {
    if(gen > 50) {
        cout << "genret" << endl;
        return;
    }
    if(l < 0) return;

    for(int i = 0; i < str.size(); i++) {
        if(str[i] == 'X' || str[i] == 'Y') {
            if(p > genlen[gen]) {
                p -= genlen[gen];
                l -= genlen[gen];
            }
            else if(str[i] == 'X') return solve("X+YF", gen+1);
            else return solve("FX-Y", gen+1);
        }
        else {
            if(p <= 0 && l >= 0) cout << str[i];
            l--; p--;
        }
    }
}

int main() {
    calc_genlen();
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> n >> p >> l;
        p -= 1; l -= 1;
        solve();
    }
}