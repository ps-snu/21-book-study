#include <bits/stdc++.h>
#define M 50000
using namespace std;
int a[M+1];
int n;

void process() {
    vector<int> S, v;
    for (int i = n; i >= 1; i--) S.push_back(i);
    for (int i = n-1; i >= 0; i--) {
        auto it = S.begin() + a[i];
        v.push_back(*it);
        S.erase(it);
    }
    for (int i = v.size()-1; i >= 0; i--)
        cout << v[i] << " ";
    cout << endl;
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        process();
    }
    return 0;
}
