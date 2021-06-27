#include <bits/stdc++.h>
#define M 50
using namespace std;
int n, d, p;
vector<vector<double> > A;

vector<vector<double> > power_mat(int d) {
    if (d == 1) return vector<vector<double> >(A);
    vector<vector<double> > B = power_mat(d/2);
    vector<vector<double> > C(n, vector<double>(n));
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                C[i][j] += B[i][k] * B[k][j];
    if (d % 2) {
        vector<vector<double> > D(n, vector<double>(n));
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    D[i][j] += C[i][k] * A[k][j];
        return D;
    }
    return C;
}

int main() {
    int C; cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> n >> d >> p;
        A = vector<vector<double> >(n, vector<double>(n));
        for (int i = 0; i < n; i++) {
            double outdeg = 0;
            for (int j = 0; j < n; j++) {
                cin >> A[i][j];
                outdeg += A[i][j];
            }
            for (int j = 0; j < n; j++)
                A[i][j] /= outdeg;
        }
        vector<vector<double> > P = power_mat(d);
        int T; cin >> T;
        for (int t = 0; t < T; t++) {
            int k; cin >> k;
            printf("%.8lf ", P[p][k]);
        }
        cout << endl;
    }
    return 0;
}