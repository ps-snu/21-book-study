#include <bits/stdc++.h>

using namespace std;

int res = 0;

void findPair(int n, int cur_n, int m, int iter,
                set<int> matched, vector< pair<int,int> > pv) {
    set<int> _matched = matched;
    int _cur_n = cur_n; 

    for(int i = iter; i < m; i++) {
        cur_n = _cur_n;
        matched = _matched;

        if(!matched.insert(pv.at(i).first).second) continue;
        if(!matched.insert(pv.at(i).second).second) continue;   

        cur_n += 2;

        if(n == cur_n) {
            if(matched.size() == n) res += 1;
            continue;
        }
        findPair(n, cur_n, m, i, matched, pv);
    }
}

int main(){
    int C, m, n;
    int f1,f2;
    vector< pair<int,int> > pv;
    set<int> matched;

    freopen("input.txt", "r", stdin);

    cin >> C;
    for(int c = 0; c < C; c++) {
        res = 0;
        matched.clear();
        pv.clear();
        cin >> n >> m;

        for(int p = 0; p < m; p++) {
            cin >> f1 >> f2;
            pv.push_back(make_pair(f1,f2));
        }
        findPair(n, 0, m, 0, matched, pv);

        printf("%d\n", res);
    }   
}