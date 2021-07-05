#include <bits/stdc++.h>

using namespace std;

int N;
int inputs[100][100];
int memo[100][100];
int memo2[100][100];

int process1() {
    for (int i = 0; i < N; i++)
        memo[N-1][i] = inputs[N-1][i];
    for (int i = N-2; i >= 0; i--)
        for (int j = 0; j <= i; j++) {
            if (memo[i+1][j] > memo[i+1][j+1]) memo[i][j] = inputs[i][j] + memo[i+1][j];
            else memo[i][j] = inputs[i][j] + memo[i+1][j+1];
        }
}

int process2(int i, int j) {
    int &result = memo2[i][j];
    if (result != -1) return result;
    if (i == N-1) return result = 1;
    if (memo[i+1][j] > memo[i+1][j+1]) result = process2(i+1, j);
    else if (memo[i+1][j] < memo[i+1][j+1]) result = process2(i+1, j+1);
    else result = process2(i+1, j) + process2(i+1, j+1);
    return result;
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        memset(memo2, -1, sizeof(memo2));
        cin >> N;
        for (int i = 0; i < N; i++)
            for (int j = 0; j <= i; j++)
                cin >> inputs[i][j];
        process1();
        cout << process2(0, 0) << endl;
    }
}
