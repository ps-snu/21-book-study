#include <bits/stdc++.h>
#define M 1000
using namespace std;
int n, k;
vector<int> p;

void solve() {
    for(int i = 1; i <= n; i++)
        p.push_back(i);

    int kill = 0;
    for(int i = 0; i < n-2; i++) {
        p.erase(p.begin()+kill);
        kill = (kill+k-1) % (p.size());
    }

    for(int i = 0; i < p.size(); i++) 
        cout << p[i] << " ";
    cout << endl;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        p.clear();
        cin >> n >> k;
        solve();
    }
    return 0;
}