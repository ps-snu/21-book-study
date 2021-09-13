#include <bits/stdc++.h>
using namespace std;

struct SuffixComparator {
    const string& s;
    SuffixComparator(const string& s) : s(s) {}
    bool operator() (int i, int j) {
        return strcmp(s.c_str() + i, s.c_str() + j) < 0; 
    }
};

vector<int> getSuffixArray(const string& s) {
    vector<int> perm;
    for(int i = 0; i < s.size(); i++) perm.push_back(i);
    sort(perm.begin(), perm.end(), SuffixComparator(s));
    return perm;
}

int solve(const string& s, int k) {
    vector<int> suffixArray = getSuffixArray(s);

    int m = s.size();
    int start = 0;
    int ret = 0;
    while(1) {
        int end = start + k-1;
        if(end >= m) break;

        int start_suffix = suffixArray[start];
        int end_suffix = suffixArray[end];
        int offset = 0;
        while(start_suffix+offset < s.size() && end_suffix+offset < s.size()) {
            if(s[start_suffix+offset] != s[end_suffix+offset]) break;
            offset++;
        }
        ret = max(ret, offset);
        start++;
    }
    return ret;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        int k; cin >> k;
        string s; cin >> s;
        cout << solve(s, k) << endl;
    }
    return 0;
}