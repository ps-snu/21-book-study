#include <bits/stdc++.h>
#define INF (INT_MAX/2)
#define M 10000
using namespace std;
int n, d[M+1]; vector<int> a;

int calDiff(vector<int> v) {
    int tmp[5];
    int pass[6] = {1,2,2,4,5,10};

    for(int i = 0; i < v.size()-1; i++) 
        tmp[i] = v[i+1] - v[i];
    for(int i = 0; i < v.size()-1; i++) {
        if(tmp[i] != 0) pass[0] = INT_MAX;
        if(tmp[i] != 1) pass[1] = INT_MAX;
        if(tmp[i] != -1) pass[2] = INT_MAX;  
    }
    int prev = tmp[0];
    for(int i = 1; i < v.size()-1; i++) {
        if(prev != -1 * tmp[i]) pass[3] = INT_MAX;
        if(prev != tmp[i]) pass[4] = INT_MAX;
        prev = tmp[i];
    }
    return *min_element(pass, pass+6);
}

void solve() {
    for(int i = 3; i <= 5; i++) 
        d[i] = calDiff(vector<int>(a.begin(), a.begin()+i));
    for(int i = 6; i <= n; i++) {
        for(int j = 3; j <= 5; j++) {
            if(i-j >= 3) 
                d[i] = min(d[i], d[i-j] + calDiff(vector<int>(a.begin()+i-j, a.begin()+i)));
        }
    }
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        a.clear();
        fill(d, d+M, INT_MAX);
        string s; cin >> s;
        n = s.size();
        for (int i = 0; i < n; i++) a.push_back(s[i]-'0');
        solve(); printf("%d\n", d[n]);  
    }
    return 0;
}