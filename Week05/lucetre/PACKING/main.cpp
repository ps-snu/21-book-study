#include <bits/stdc++.h>
#define N 100
#define W 1000
using namespace std;
typedef pair<int, int> pii;
pair<string , pii> a[N+1];
pii dy[N+1][W+1];
int n, w;

void process() {
    int wi = a[0].second.first;
    int vi = a[0].second.second;
    for (int j = 0; j <= w; j++)
        dy[0][j] = j < wi ? make_pair(0, 0) : make_pair(vi, 1);
        
    for (int i = 1; i < n; i++) {
        wi = a[i].second.first;
        vi = a[i].second.second;
        for (int j = 0; j <= w; j++) {
            int dy0 = dy[i-1][j].first;
            int dy1 = vi + dy[i-1][j-wi].first;
            if (j >= wi && dy0 < dy1)
                dy[i][j] = make_pair(dy1, 1);
            else
                dy[i][j] = make_pair(dy0, 0);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= w; j++)
            printf("%3d(%d)", dy[i][j].first, dy[i][j].second);
        printf("\n");
    }
    
    cout << dy[n-1][w].first << " ";
    vector<string> v;
    for (int i = n-1; i >= 0; i--) {
        if (dy[i][w].second) {
            w -= a[i].second.first;
            v.push_back(a[i].first);
        }
    }
    cout << v.size() << endl;
    for (auto vi: v) cout << vi << endl;
}

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n >> w;
        for (int i = 0; i < n; i++)
            cin >> a[i].first >> a[i].second.first >> a[i].second.second;
        process();
    }
    return 0;
}
