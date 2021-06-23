#include <bits/stdc++.h>
using namespace std;


string line;
int dp[10001];
int N;

int check_difficulty(int si, int length) {
    // case 1: same
    bool pass = true;
    for (int i = 1; i < length && pass; i++)
        if (line[si] != line[si+i])
            pass = false;
    if (pass) return 1;

    // case 2: diff 1
    pass = true;
    int diff = line[si+1] - line[si];
    if (abs(diff) == 1) {
        for (int i = 2; i < length && pass; i++)
            if (line[si+i] - line[si+i-1] != diff)
                pass = false;
        if (pass) return 2;
    }

    // case 3: alternating
    pass = true;
    int first = line[si], second = line[si+1];
    for (int i = 2; i < length && pass; i++) {
        if (i%2==0 && line[si+i]!=first)
            pass = false;
        if (i%2==1 && line[si+i]!=second)
            pass = false;
    }
    if (pass) return 4;

    // case 4: same diff
    pass = true;
    diff = line[si+1] - line[si];
    for (int i = 2; i < length && pass; i++)
        if (line[si+i] - line[si+i-1] != diff)
            pass = false;
    if (pass) return 5;

    // case 5: other
    return 10;
}

int process(int start_index) {
    int& result = dp[start_index];
    if (result != -1) return result;
    result = INT_MAX-100000;
    for (int i = 3; i <= 5 && start_index+i<=N; i++) {
        result = min(result, check_difficulty(start_index, i) + process(start_index+i));
    }
    return result;
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> line;
        N = line.size();
        memset(dp, -1, sizeof(dp));
        dp[N]= 0;
        cout << process(0) << endl;
    }
}
