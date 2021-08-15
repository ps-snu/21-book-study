#include <bits/stdc++.h>
using namespace std;
map<vector<int>, int> M;

void init(int v_size) {
    vector<int> v;
    queue<vector<int>> Q;
    
    for(int i = 0; i < v_size; i++)
        v.push_back(i+1);
    
    M[v] = 0;
    Q.push(v);
    while(!Q.empty()){
        vector<int> f = Q.front(); Q.pop();
        int cost = M[f];
        
        for(int i = 0 ; i < v_size ; i++){
            for(int j = i+2; j <= v_size ; j++){
                reverse(f.begin()+i, f.begin()+j);
                if(M.count(f) == 0){
                    M[f] = cost + 1;
                    Q.push(f);
                }
                reverse(f.begin()+i, f.begin()+j);
            }
        }
    }
}

int main() {
    for(int v_size = 1; v_size <= 8; v_size++)
        init(v_size);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int n; cin >> n;
        vector<int> v(n);
        pair<int, int> p[8];
        for (int i = 0; i < n; i++) {
            cin >> p[i].first;
            p[i].second = i;
        }
        sort(p, p+n);
        for (int i = 0; i < n; i++)
            v[p[i].second] = i+1;
        cout << M[v] << endl;
    }
    return 0;
}
