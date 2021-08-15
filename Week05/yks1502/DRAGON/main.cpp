#include <bits/stdc++.h>
using namespace std;

const int MAX_P = 1000000050;
int c, n, p, l;
int a[50], maxGen;
string dc0 = "FX";
string dc1 = "FX+YF";
string dc2 = "FX+YF+FX-YF";

void preCalc() {
    a[0] = 2;
    for (int i = 1; i < 50; i++) {
        a[i] = 2 * a[i - 1] + 1;
        
        if (a[i] > MAX_P) {
            maxGen = i;
            return;
        }
    }
}

char getCurve(int gen, int idx) {
    if (gen == 0) return dc0[idx];
    if (gen == 1) return dc1[idx];
    if (gen == 2) return dc2[idx];
    if (gen > maxGen) return getCurve(maxGen, idx);

    if (idx == a[gen - 1]) return '+';
    if (idx < a[gen - 1]) return getCurve(gen - 1, idx);
    if (idx - (a[gen - 1] + 1) == a[gen - 2]) return '-';
    return getCurve(gen - 1, idx - (a[gen - 1] + 1));
}

int main() {
    cin >> c;
    preCalc();

    for (int tc = 0; tc < c; tc++) {
        cin >> n >> p >> l;

        for (int i = 0; i < l; i++) {
            cout << getCurve(n, p - 1 + i);
        }

        cout << endl;
    }
}