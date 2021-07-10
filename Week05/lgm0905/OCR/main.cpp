#include<bits/stdc++.h>
#define MAX 500
#define N_MAX 100
using namespace std;
int m, q, n;
string w[MAX+1], in[N_MAX+1], seg[MAX];
double B[MAX+1] ,T[MAX+1][MAX+1], M[MAX+1][MAX+1];
int choice[MAX+1][MAX+1], r[N_MAX+1];
double d[MAX+1][MAX+1];

double solve(int seg, int prev) {
    if(seg == n) return 1;
    if(d[seg][prev] != -1) return d[seg][prev];
    for(int i = 0; i < m; i++) {
        double c = T[prev][i] + M[i][r[seg]] + solve(seg+1, i);
        if(d[seg][prev] < c) {
            d[seg][prev] = c;
            choice[seg][prev] = i;
        }
    }
    return  d[seg][prev];
}

void reconstruct() {
    double max = -1;
    int idx;
    for(int i = 0; i < m; i++) {
        double tmp = B[i] * M[i][r[0]] * solve(1,i);
        if(max < tmp) {
            max = tmp;
            idx = i;
        }
    }
    cout << w[idx] << " ";
    for(int i = 1; i < n; i++) {
        idx = choice[i][idx];
        cout << w[idx] << " "; 
    } 
    cout << endl;
 }

int main() {
    cin >> m >> q;
    for(int i = 0; i < m; i++) 
        cin >> w[i];
    for(int i = 0; i < m; i++)
        cin >> B[i];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++) 
            cin >> T[i][j];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++) 
            cin >> M[i][j];
    for(int i = 0; i < q; i++) {
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> in[j];
            for(int k = 0; k < m; k++)
                if(w[k] == in[j]) {
                    r[j] = k;
                    break;
                }
        }
        memset(d, -1, sizeof(d));
        reconstruct();
    }
    return 0;
}