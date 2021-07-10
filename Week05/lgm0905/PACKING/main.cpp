#include <bits/stdc++.h>
using namespace std;
#define N_M 100
#define W_M 1000
int n, w;
int d[W_M+1][N_M+1];
int psum[W_M+1];
struct In {
    char name[21];
    int v;
    int p;
} in[N_M];

void solve() {
    for(int i = 0; i <= w; i++) {
        for(int j = 0; j < n; j++) {
            if(i + in[j].v > w) continue;
            if((psum[i + in[j].v] <= psum[i] + in[j].p) && (d[i][j] == 0)) {
                psum[i + in[j].v] = psum[i] + in[j].p;
                for(int k = 0; k < n; k++)
                    d[i + in[j].v][k] = d[i][k];
                d[i + in[j].v][j] = 1;
            }
        }
    }

    int pmax = -1; int wsum = 0;
    for(int i = 0; i <= w; i++) {
        if(pmax < psum[i]) {
            pmax = psum[i];
            wsum = i;
        }
    }
    int allnum = 0;
    for(int i = 0; i < n; i++)
        allnum += d[wsum][i];
    cout << pmax << " " << allnum << endl;
    for(int i = 0; i < n; i++)
        if(d[wsum][i] == 1) cout << in[i].name << endl;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        memset(psum, 0, sizeof(psum));
        memset(d, 0, sizeof(d));
        cin >> n >> w;
        for(int i = 0; i < n; i++) 
            cin >> in[i].name >> in[i].v >> in[i].p;
        solve();
    } 
    return 0;
}