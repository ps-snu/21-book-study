#include <bits/stdc++.h>
using namespace std;

vector<int> Karatsuba(vector<int> x, vector<int> y) {
    int lenX = x.size();
    int lenY = y.size();
	int len = lenX + lenY - 1;
    vector<int> res(len);
    for (int i = 0; i < x.size(); i++) {
        for (int j = 0; j < y.size(); j++) {
            res[i + j] += x[i] * y[j];
        }
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        string a, b;
        cin >> a >> b;
        vector<int> A, B, C;
        for (int i = 0; i < a.size(); A.push_back(a[i] == 'M'), i++);
        for (int i = 0; i < b.size(); B.push_back(b[i] == 'M'), i++);
        reverse(A.begin(), A.end());
        C = Karatsuba(A, B);
        
        for (auto c: C)
            cout << c << " ";
        cout << endl;

        int ans = 0;
        for (int i = A.size()-1; i < B.size(); ans += (C[i]==0), i++);
        cout << ans << endl;
    }
    return 0;
}