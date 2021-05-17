#include <bits/stdc++.h>
#define M 1000
#define INF 9e9
using namespace std;
int n, l;
int a[M+1];

int main() {
    // freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n >> l;
        for (int i = 0; i < n; i++) cin >> a[i];
        double res = INF;
        for (int i = 0; i < n-l+1; i++) {
            double sum = 0.0;
            for (int j = i; j < n; j++) {
                sum += a[j];
                if (j-i+1 >= l) {
                    res = min(res, sum / (j-i+1));
                }
            }
        }
        printf("%.10lf\n", res);
    }
    return 0;
}