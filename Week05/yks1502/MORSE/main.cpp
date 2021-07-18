#include <bits/stdc++.h>
using namespace std;
#define maxK 1000000000

int n, m, k;
int cache[201][201];

void calcBino() {
    memset(cache, 0, sizeof(cache));
    for (int i = 0; i < 200; i++) {
        cache[i][0] = 1;
        cache[i][i] = 1;
        for (int j = 0; j < i; j++) {
            cache[i][j] = min(maxK, cache[i -1][j - 1] + cache[i - 1][j]);
        }
    }
}

void combination(int idx, int r, vector<int>& picked) {
    if (k == 0) return;
    if (r == 0) {
        k--;
        if (k == 0) {
            int pos = 0;
            for (int i = 0; i < n + m; i++) {
                if (i == picked[pos]) {
                    cout << "o";
                    pos++;
                } else {
                    cout << "-";
                }
            }
            cout << endl;
        }
        return;
    }
    if (idx == n + m) return;

    if (cache[n + m - idx][r] < k) {
        k -= cache[n + m - idx][r];
        return;
    }
    
    combination(idx + 1, r, picked);
    picked.push_back(idx);
    combination(idx + 1, r - 1, picked);
    picked.pop_back();
}

int main() {
    int C;
    cin >> C;
    calcBino();

    for (int i = 0; i < C; i++) {
        cin >> n >> m >> k;
        vector<int> picked;
        combination(0, m, picked);
    }
}