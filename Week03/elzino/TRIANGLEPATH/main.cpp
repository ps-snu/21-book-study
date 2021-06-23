#include <bits/stdc++.h>

using namespace std;

int input[100][100];
int memo[100];


int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                cin >> input[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            memo[i] = input[n-1][i];
        }
        for (int i = n-2; i >=0; i--) {
            for (int j = 0; j <= i; j++) {
                memo[j] = input[i][j] + max(memo[j], memo[j+1]);
            }
        }
        cout << memo[0] << endl;
    }
}
