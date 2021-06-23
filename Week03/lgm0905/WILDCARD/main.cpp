#include <bits/stdc++.h>
#define M 100
using namespace std;

int solve(string s, string t, int s_idx, int t_idx) {
    if(s_idx == s.size()) return t_idx == t.size() ? 1 : 0;
    if(t_idx == t.size()) {
        while(1) {
            if(s_idx == s.size()) return 1;
            if(s[s_idx] != '*') return 0;
            s_idx++;
        }
        
    }

    if(s[s_idx] == '?') {
        return solve(s, t, s_idx+1, t_idx+1);
    }
    else if(s[s_idx] == '*') {
        int c = 0;
        while(1) {
            if(s_idx+1 >= s.size()) return 1;
            if(t[t_idx+c] == s[s_idx+1] || s[s_idx+1] == '*' || s[s_idx+1] == '?') {
                if(solve(s, t, s_idx+1, t_idx+c) == 1) return 1; 
            }
            if(t_idx+c >= t.size()) return 0;
            c++;
        }
    }
    else {
        if(s[s_idx] == t[t_idx]) return solve(s, t, s_idx+1, t_idx+1);
        else return 0;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        string s; cin >> s;
        int T2; cin >> T2;
        string targets[M+1];
        for (int t2 = 0; t2 < T2; t2++)
            cin >> targets[t2];

        sort(targets, targets+T2);
        for (int t2 = 0; t2 < T2; t2++)
            if (solve(s, targets[t2], 0, 0))
                cout << targets[t2] << endl;

    }
    return 0;
}