#include <bits/stdc++.h>
using namespace std;
#define maxP 1000000050

int n, p, l;
string dc[50][2];

void calcDc() {
    dc[0][0] = "FX";
    dc[0][1] = "";
    dc[1][0] = "FX+YF";
    dc[1][1] = "YF";

    for (int i = 1; i <= 50; i++) {
        if (dc[i][0].size() > maxP) break;

        dc[i + 1][0] = dc[i][0] + "+";
        dc[i + 1][1] = dc[i - 1][0] + "-" + dc[i][1];
        dc[i + 1][0] += dc[i + 1][1];
    }
}

int main() {
    int c;
    cin >> c;

    calcDc();
    for (int i = 0; i < c; i++) {
        cin >> n >> p >> l;
        cout << dc[29][0].substr(p - 1, l) << endl;
    }
}