#include <bits/stdc++.h>
using namespace std;

string s;
char c[10000];
int cache[10000][3];
int len;
int sub[10000];
int tmp[4];
int res[10001];

int eval(int idx, int size) {
    int& e = cache[idx][size - 3];
    if (e != -1) return e;
    if (idx + size > len) return e = 100000;

    for (int i = 0; i < size - 1; i++) {
        int& val = sub[idx + i];
        if (val == 10) val = c[idx + i + 1] - c[idx + i];
        tmp[i] = val;
    }

    bool same = true;
    for (int i = 0; i < size - 2; i++) {
        if (tmp[i] != tmp[i + 1]) {
            same = false;
            break;
        }
    }

    if (same) {
        switch (tmp[0]) {
            case 0:
                return e = 1;
            case 1:
                return e = 2;
            case -1:
                return e = 2;
            default:
                return e = 5;
        }
    }

    bool oppo = true;
    for (int i = 0; i < size - 2; i++) {
        if (tmp[i] != -tmp[i + 1]) {
            oppo = false;
            break;
        }
    }

    if (oppo) return e = 4;
    return e = 10;
}

int difficulty(int idx) {
    int& d = res[idx];
    if (d != -1) return d;
    if (idx == len) return d = 0;
    if (idx > len - 3) return d = 100000;

    d = 100000;
    for (int i = 0; i < 3; i++) {
        d = min(d, cache[idx][i] + difficulty(idx + i + 3));
    }
    return d;
}

int main() {
    freopen("input.txt", "r", stdin);
    int C;
    cin >> C;

    for (int i = 0; i < C; i++) {
        memset(cache, -1, sizeof(cache));
        memset(res, -1, sizeof(res));
        cin >> s;
        strcpy(c, s.c_str());
        len = s.size();

        for (int j = 0; j < len; j++) {
            sub[j] = 10;
        }

        for (int j = 0; j < len; j++) {
            for (int k = 3; k < 6; k++) {
                eval(j, k);
            }
        }
        
        for (int j = 0; j < len; j++) {
            difficulty(j);
        }
        cout << difficulty(0) << endl;
    }
}