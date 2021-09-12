#include <bits/stdc++.h>

using namespace std;

struct Comparator {
    const vector<int>& group;
    int t;
    Comparator(const vector<int>& _group, int _t): group(_group), t(_t) {};
    bool operator () (int a, int b) {
        if (group[a] != group[b])
            return group[a] < group[b];
        return group[a+t] < group[b+t];
    }
};

vector<int> getSuffixArray(const string& s) {
    int n = s.size();
    int t = 1;
    vector<int> group(n+1);
    for (int i = 0; i < n; i++)
        group[i] = s[i];
    group[n] = -1;
    vector<int> perm(n);
    for (int i = 0; i < n; i++)
        perm[i] = i;
    while (t < n) {
        Comparator compareUsing2T(group, t);
        sort(perm.begin(), perm.end(), compareUsing2T);
        t *= 2;
        if (t >= n)
            break;
        vector<int> newGroup(n+1);
        newGroup[n] = -1;
        newGroup[perm[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (compareUsing2T(perm[i-1], perm[i]))
                newGroup[perm[i]] = newGroup[perm[i-1]] + 1;
            else
                newGroup[perm[i]] = newGroup[perm[i-1]];
        }
        group = newGroup;
    }
    return perm;
}

int commonPrefixLen(string &S, int i, int j) {
    int k = 0;
    int m = S.size();
    while (i < m && j < m && S[i] == S[j]) {
        i++; j++; k++;
    }
    return k;
}

int solve(string &S, vector<int>& perm, int K) {
    int m = S.size();
    int ret = 0;
    for (int i = K-1; i < m; i++) {
        int l = commonPrefixLen(S, perm[i-(K-1)], perm[i]);
        ret = max(ret, l);
    }
    return ret;
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        int K;
        string S;
        cin >> K;
        cin >> S;
        vector<int> perm = getSuffixArray(S);
        cout << solve(S, perm, K) << endl;
    }
}
