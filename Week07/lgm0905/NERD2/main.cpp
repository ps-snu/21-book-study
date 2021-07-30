#include<bits/stdc++.h>
using namespace std;
map<int, int> a;

bool isDominated(int p, int q) {
    map<int, int>::iterator it = a.lower_bound(p);
    if(it == a.end()) return false;
    return q < it->second;
}

void removeElem(int p, int q) {
    map<int, int>::iterator it = a.lower_bound(p);
    if(it == a.begin()) return;
    it--;

    while(true) {
        if(it->second > q) break;
        if(it == a.begin()) {
            a.erase(it);
            break;
        }
        else {
            map<int, int>::iterator jt = it;
            jt--;
            a.erase(it);
            it = jt;
        }
    }
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        a.clear();
        int ret = 0;
        int n; cin >> n;
        for(int i = 0; i < n; i++) {
            int p, q; cin >> p >> q;
            if(i == 0) a[p] = q; 
            else if(!isDominated(p, q)) {
                removeElem(p, q);
                a[p] = q;
            }
            ret += a.size();
        }
        cout << ret << endl;
    }
    return 0;
}