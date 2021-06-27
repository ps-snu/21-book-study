#include <bits/stdc++.h>
#define M 1000
using namespace std;
double C[M+1][M+1];
/*
2*r1 + r0 >= n
r1 + r0 = m

(1) n < m           P = 1
(2) n >= m >= n/2   P = SUM C(m,r0) * (3/4)^r1 * (1/4)^r0       where 0 <= r0 <= 2m-n
(3) m < n/2         P = 0
*/
int main() {
    int T; cin >> T;
    C[0][0] = 1;
    for (int n = 1; n <= M; n++) {
        C[n][0] = 1;
        for (int k = 1; k <= n; k++)
            C[n][k] = C[n-1][k-1] + C[n-1][k];
    }
    for (int t = 0; t < T; t++){
        int n, m; cin >> n >> m;
        double res = 0.0;
        if (n < m) res = 1;
        else if (m*2 < n) res = 0;
        else
            for (int r0 = 0; r0 <= 2*m-n; r0++) 
                res += C[m][r0] * pow(0.75, m-r0) * pow(0.25, r0);
        printf("%.10f\n", res);
    }
    return 0;
}

