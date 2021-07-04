#include <bits/stdc++.h>

using namespace std;

#define BIGNUM 1000000007

int tile[101];
int symtile[101];

int process(int n) {
    int& result = tile[n];
    if (result != -1) return result;
    result = (process(n-1) + process(n-2)) % BIGNUM;
    return result;
}

int process_sym(int n) {
    int& result = symtile[n];
    if (result != -1) return result;
    result = (process_sym(n-2) + process_sym(n-4)) % BIGNUM;
    return result;
}

int main() {
    int C;
    cin >> C;
    memset(tile, -1, sizeof(tile));
    memset(symtile, -1, sizeof(symtile));
    tile[1] = 1;
    tile[2] = 2;
    symtile[0] = 1;
    symtile[1] = 1;
    symtile[2] = 2;
    symtile[3] = 1;
    for (int c = 0; c < C; c++) {
        int n;
        cin >> n;
        cout << (process(n) - process_sym(n) + BIGNUM) % BIGNUM << endl;
    }
}
