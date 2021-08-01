#include <bits/stdc++.h>
#define M 100
using namespace std;
int n;

void printPost(vector<int>& pre, vector<int>& in) {
    if(pre.empty()) return;

    int root = pre[0];
    int in_root_idx = find(in.begin(), in.end(), root) - in.begin();

    vector<int> pre_left = vector<int>(pre.begin()+1, pre.begin()+in_root_idx+1);
    vector<int> pre_right = vector<int>(pre.begin()+in_root_idx+1, pre.end());
    vector<int> in_left = vector<int>(in.begin(), in.begin()+in_root_idx);
    vector<int> in_right = vector<int>(in.begin()+in_root_idx+1, in.end());

    printPost(pre_left, in_left);
    printPost(pre_right, in_right);
    cout << root << " ";

    return;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        int _pre[M+1], _in[M+1];
        cin >> n;
        for(int _n = 0; _n < n; _n++)
            cin >> _pre[_n];
        vector<int> pre = vector<int>(_pre, _pre+n);
        for(int _n = 0; _n < n; _n++)
            cin >> _in[_n];
        vector<int> in = vector<int>(_in, _in+n);

        printPost(pre, in);
        cout << endl;
    }
    return 0;
}