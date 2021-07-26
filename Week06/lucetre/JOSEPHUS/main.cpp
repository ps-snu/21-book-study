#include <bits/stdc++.h>
using namespace std;
int n, k;

void process(vector<int>& v) {
    int i = 0;
    while (v.size() != 2) {
        v.erase(v.begin() + i);
        i = (i + k-1) % v.size();
    }
    for (auto vi : v)
        cout << vi << " ";
    cout << endl;
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n >> k;
        vector<int> v;
        for (int i = 0; i < n; i++) v.push_back(i+1);
        process(v);
    }
    return 0;
}
