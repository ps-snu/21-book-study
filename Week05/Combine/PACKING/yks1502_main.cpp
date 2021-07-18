#include <bits/stdc++.h>
using namespace std;

int N, W;
string names[100];
int vol[100], dsp[100], cache[1001][100];

int combination(int w, int idx) {
    int& c = cache[w][idx];
    if (c != -1) return c;
    if (idx == N) return c = 0;

    c = combination(w, idx + 1);
    if (vol[idx] <= w)
        c = max(c, dsp[idx] + combination(w - vol[idx], idx + 1));

    return c;
}

int main() {
    int C;
    cin >> C;

    for (int i = 0; i < C; i++) {
        vector<int> items;
        cin >> N >> W;

        for (int j = 0; j < N; j++) {
            cin >> names[j] >> vol[j] >> dsp[j];
        }
        memset(cache, -1, sizeof(cache));

        int sum = combination(W, 0);
        int w = W;
        for (int item = 0; item < N; item++) {
            if (combination(w, item) == combination(w, item + 1))
                continue;
            
            items.push_back(item);
            w -= vol[item];
        }

        cout << sum << " " << items.size() << endl;
        for (int item = 0; item < items.size(); item++)
            cout << names[items[item]] << endl;
    }
}