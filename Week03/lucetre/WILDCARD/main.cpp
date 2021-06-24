#include <bits/stdc++.h>
#define M 100
using namespace std;
bool d[M+5][M+5];
int n, m;

bool process(string source, string target) {
    n = source.size();
    m = target.size();
    for (int i = 0; i <= n; i++)
        memset(d[i], 0, (m+1)*sizeof(int));
    d[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        char src = source[i-1];
        d[i][0] = (src == '*') ? d[i-1][0] : 0;
        for (int j = 1; j <= m; j++) {
            char tar = target[j-1];
            if (src == '*')
                d[i][j] = d[i-1][j] + d[i][j-1];
            else
                d[i][j] = (src == '?' || src == tar) * d[i-1][j-1];
        }
    }

    cout << endl << "  " << target << endl;
    for (int i = 0; i <= n; i++) {
        cout << (i ? source[i-1] : ' '); 
        for (int j = 0; j <= m; j++)
            cout << d[i][j];
        cout << endl;
    }
    
    return d[n][m];
}

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        string source, targets[M+1];
        cin >> source;
        int N; cin >> N;

        for (int i = 0; i < N; i++)
            cin >> targets[i];

        sort(targets, targets+N);
        for (int i = 0; i < N; i++)
            if (process(source, targets[i]))
                cout << targets[i] << endl;
    }
    return 0;
}