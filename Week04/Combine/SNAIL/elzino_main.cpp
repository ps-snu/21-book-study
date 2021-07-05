#include <bits/stdc++.h>

using namespace std;

double p[1000][1000] = {0.0,};


// aCb * 0.75^b * 0.25^(a-b)
double process(int a, int b) {
    if (a < b) return 0;
    if (b == 0) return 1;
    double &result = p[a][b];
    if (result != 0) return result;
    return result = 0.75 * process(a-1, b-1) + 0.25 * process(a-1, b);
}

int main() {
    cout << fixed;
    cout.precision(10);
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        int n, m;
        cin >> n >> m;
        cout << process(m, n-m) << endl;
    }
}
