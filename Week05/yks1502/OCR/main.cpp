#include <bits/stdc++.h>
using namespace std;

int m, q, n, first, recInt[100], footprint[100][500];
string words[500], rec[100];
double B[500], T[500][500], M[500][500];
double initP[500][500], cache[101][500];

double initProb(int curr, int target) {
    double& c = initP[curr][target];
    if (c != -1.0) return c;
    return c = B[target] * M[target][curr];
}

double combination(int idx, int prev) {
    if (idx == n) return 1;
    double& c = cache[idx][prev];
    if (c != -1.0) return c;

    c = 0;
    for (int curr = 0; curr < m; curr++) {
        double resP = T[prev][curr] * M[curr][recInt[idx]] * combination(idx + 1, curr);
        if (c < resP) {
            c = resP;
            footprint[idx][prev] = curr;
        }
    }

    return c;
}

void init() {
    for (int r = 0; r < m; r++)
        for (int c = 0; c < m; c++) {
            initP[r][c] = -1.0;
            cache[r][c] = -1.0;
        }

    double maxP = 0;
    for (int i = 0; i < m; i++) {
        double resP = initProb(recInt[0], i) * combination(1, i);
        if (maxP < resP) {
            maxP = resP;
            first = i;
        }
    }
}

int main() {
    cin >> m >> q;
    for (int i = 0; i < m; i++)
        cin >> words[i];
    for (int i = 0; i < m; i++)
        cin >> B[i];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cin >> T[i][j];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cin >> M[i][j];

    for (int i = 0; i < q; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> rec[j];
            for (int k = 0; k < m; k++) {
                if (rec[j] == words[k])
                    recInt[j] = k;
            }
        }
        init();

        int prev = first;
        cout << words[first] << " ";
        for (int j = 1; j < n - 1; j++) {
            cout << words[footprint[j][prev]] << " ";
            prev = footprint[j][prev];
        }
        cout << words[footprint[n - 1][prev]] << endl;
    }
}