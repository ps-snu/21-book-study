#include <bits/stdc++.h>

using namespace std;

int adj[50][50];
int degree[50];
int n, d, p;
double oldp[50];
double newp[50];

void process() {
    for (int l = 0; l < d; l++) {
        for (int i = 0; i < n; i++)
            oldp[i] = newp[i];
        for (int i = 0; i < n; i++) {
            newp[i] = 0.0;
            for (int j = 0; j < n; j++)
                newp[i] += oldp[j] * adj[i][j] / (double)degree[j];
        }
    }
}

int main() {
    cout << fixed;
    cout.precision(10);
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> n >> d >> p;
        memset(oldp, 0, sizeof(oldp));
        memset(newp, 0, sizeof(newp));
        newp[p] = 1.0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> adj[i][j];
        for (int i = 0; i < n; i++)
            degree[i] = accumulate(adj[i], adj[i]+n, 0);
        process();
        int t;
        cin >> t;
        for (int i = 0; i < t; i++) {
            int q;
            cin >> q;
            cout << newp[q] << " ";
        }
        cout << endl;
    }
}
