#include <bits/stdc++.h>
using namespace std;
#define maxP 1000000050

int n, p, l;
string dc, sub1, sub2;

void calcDc() {
    dc = "FX+YF";
    sub1 = "FX";
    sub2 = "YF";
    while (dc.size() < maxP) {
        string tmp1 = dc;
        string tmp2 = sub1 + "-" + sub2;
        dc += "+" + sub1 + "-" + sub2;
        sub1 = tmp1;
        sub2 = tmp2;
    }
}

int main() {
    int c;
    cin >> c;

    calcDc();
    for (int i = 0; i < c; i++) {
        cin >> n >> p >> l;

        cout << dc.substr(p - 1, l) << endl;
    }
}