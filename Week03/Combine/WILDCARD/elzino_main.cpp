#include <bits/stdc++.h>

using namespace std;

int dp[101][101];
string inputs[50];

string wildcard;
string input;
static int wsize;
static int isize;

bool checkMatch(int wcIndex, int inputIndex) {
    if (wcIndex == wsize && inputIndex == isize) return true;
    if (wcIndex == wsize-1 && inputIndex == isize && wildcard[wcIndex] == '*') return true;
    if (wcIndex >= wsize || inputIndex >= isize) return false;
    if (dp[wcIndex][inputIndex] != -1) return dp[wcIndex][inputIndex];
    int& result = dp[wcIndex][inputIndex];

    if (wcIndex < wsize && inputIndex < isize &&
            (wildcard[wcIndex] == '?' || wildcard[wcIndex] == input[inputIndex]))
        return result = checkMatch(wcIndex+1, inputIndex+1);

    if (wildcard[wcIndex] == '*') {
        result = checkMatch(wcIndex, inputIndex+1) || checkMatch(wcIndex+1, inputIndex);
        return result;
    }
    return result = false;
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
            memset(dp, -1, sizeof(dp));
            if (checkMatch(0, 0)) cout << inputs[n] << endl;
        }
    }
}
