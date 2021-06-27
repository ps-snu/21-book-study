#include <bits/stdc++.h>
#define M 100
using namespace std;
int a[M+1][M+1];
pair<int,int> d[M+1][M+1];
int n;

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                cin >> a[i][j];
                if (i*j) {
                    if (d[i-1][j-1].first > d[i-1][j].first)        
                                d[i][j] = make_pair(d[i-1][j-1].first+a[i][j], d[i-1][j-1].second); 
                    else if (d[i-1][j-1].first < d[i-1][j].first)   
                                d[i][j] = make_pair(d[i-1][j].first+a[i][j], d[i-1][j].second);  
                    else        d[i][j] = make_pair(d[i-1][j].first+a[i][j], d[i-1][j-1].second+d[i-1][j].second); 
                }
                else if (i)     d[i][j] = make_pair(d[i-1][j].first+a[i][j], d[i-1][j].second);
                else            d[i][j] = make_pair(a[i][j], 1);
            }
        }
        int maxVal = max_element(d[n-1], d[n-1]+n)->first;
        int res = 0;
        for (int i = 0; i < n; i++)
            if (d[n-1][i].first == maxVal)
                res += d[n-1][i].second;
        cout << res << endl;
    }
    return 0;
}