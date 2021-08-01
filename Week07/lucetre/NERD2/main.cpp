#include <bits/stdc++.h>
using namespace std;
int n;

int process(map<int, int>& M) {
    int a, b;
    cin >> a >> b;
    auto it = M.lower_bound(a);
    if (it != M.end() && b < it->second) return M.size();
    if (it != M.begin()) {
        it--;
        while (true) {
            if (it->second > b) break;
            if (it == M.begin()) {
                M.erase(it);
                break;
            }
            else M.erase(it--);
        }
    }
    M[a] = b;
    return M.size();
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        int res = 0;
        map<int, int> M;
        for (int i = 0; i < n; i++)
            res += process(M);
        cout << res << endl;
    }
    return 0;
}
