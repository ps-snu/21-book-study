#include <bits/stdc++.h>
using namespace std;

int N, wlen, flen, plen;
string wc, fn;
string pass[50];
char w[101], f[101];
int cache[101][101];

int match(int wi, int fi) {
    if ((fi == flen) && (wi == wlen)) return 1;
    if (wi == wlen) return 0;
    int& c = cache[wi][fi];
    if (c != -1) return c;

    char a = w[wi];
    char b = f[fi];
    if ((a == b) || (a == '?')) return c = match(wi + 1, fi + 1);
    if (a == '*') {
        for (int i = fi; i < flen + 1; i++) {
            if (match(wi + 1, i) == 1) return c = 1;
        }
    }
    return c = 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    int C;
    cin >> C;
    for (int i = 0; i < C; i++) {
        cin >> wc;
        cin >> N;
        strcpy(w, wc.c_str());
        wlen = wc.size();
        plen = 0;
        for (int j = 0; j < N; j++) {
            memset(cache, -1, sizeof(cache));
            cin >> fn;
            strcpy(f, fn.c_str());
            flen = fn.size();
            int res = match(0, 0);
            if (res == 1) pass[plen++] = fn;
        }
        sort(pass, pass + plen);
        for (int j = 0; j < plen; j++) {
            cout << pass[j] << endl;
        }
    }
}