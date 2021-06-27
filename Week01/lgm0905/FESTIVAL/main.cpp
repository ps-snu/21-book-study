#include <bits/stdc++.h>
#define MAX 1000
#define INF 9e9

using namespace std;

int main() {
    int T; 
    int n; int l;
    int cost[MAX];

    freopen("input.txt", "r", stdin);

    cin >> T;

    for(int t = 0; t < T; t++) {
        double res = INF;
        double tmp;
        cin >> n >> l;

        for(int i = 0; i < n; i++) {
            cin >> cost[i];
        }
        
        // using brute force
        for(int i = 0; i < n-l+1; i++) {
            tmp = 0;

            for(int j = i; j < n; j++) {
                tmp += cost[j];
                if(l <= j-i+1) res = res < tmp / (j-i+1) ? res : tmp / (j-i+1);
            }
        }
        printf("%.10lf\n", res);
    }
}