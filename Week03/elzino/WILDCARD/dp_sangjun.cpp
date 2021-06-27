#include <bits/stdc++.h>

using namespace std;

bool memo[101][101];
string inputs[50];

string wildcard;
string input;
static int wsize;
static int isize;

bool checkMatch() {
    memset(memo, 0, sizeof(memo));
    memo[0][0] = 1;
    for (int i = 1; i <= wsize; i++) {
        memo[i][0] = (wildcard[i-1] == '*') ? memo[i-1][0] : 0;
        for (int j = 1; j <= isize; j++) {
            if (wildcard[i-1] == '*') {
                memo[i][j] = memo[i-1][j] || memo[i][j-1];
            } else if (wildcard[i-1] == '?') {
                memo[i][j] = memo[i-1][j-1];
            } else {
                memo[i][j] = (wildcard[i-1] == input[j-1]) && memo[i-1][j-1];
            }
        }
    }
    return memo[wsize][isize];
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> wildcard;
        wsize = wildcard.size();
        int N;
        cin >> N;
        for (int n = 0; n < N; n++) {
            cin >> inputs[n];
        }
        sort(inputs, inputs+N);
        for (int n = 0; n < N; n++) {
            input = inputs[n];
            isize = input.size();
            if (checkMatch()) cout << inputs[n] << endl;
        }
    }
}
