#include <bits/stdc++.h>
#define M 1000
using namespace std;
int n, m;
double c[M][M];

double solve() {
    double ret = 0;
    fill(&c[0][0], &c[M-1][M], (double)1);
    for(int i = 2; i <= m; i++) 
        for(int j = 1; j < i; j++) 
            c[i][j] = c[i-1][j] + c[i-1][j-1];
    for(int i = 0; i <= m; i++)
        ret += m+i >= n ? pow(0.75, i) * pow(0.25, m-i) * c[m][i] : 0;
    return ret;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> n >> m;
        printf("%.10f\n", solve());
    }
    return 0;
}