#include <bits/stdc++.h>
#define M 100
using namespace std;
typedef pair<int,int> pii;
int pre[M+1], in[M+1];
int n;

void process(pair<pii, pii> R) {
    pii R1 = R.first;
    pii R2 = R.second;
    if (R1.first > R1.second || R2.first > R2.second) return;
    
    int root = in[R.first.first];
    for (; pre[R2.second] != root; R2.second--);
    R1 = make_pair(R1.first+1, R1.first+R2.second-R2.first);
    R2.second--;
    process(make_pair(R1, R2));
    
    R1 = make_pair(R1.second+1, R.first.second);
    R2 = make_pair(R2.second+2, R.second.second);
    process(make_pair(R1, R2));
    
    cout << root << " ";
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> pre[i];
        process(make_pair(make_pair(0, n-1), make_pair(0, n-1)));
        cout << endl;
    }
    return 0;
}
