#include <bits/stdc++.h>

using namespace std;

#define BIGNUM 1111111111

int diff[51];
int dp[51];

// the number of printed characters
int process(char c, int n, int p, int l) {
    if (p == 0 && n == 0) {
        cout << c; return 1;
    } else if (p != 0 && n == 0)
        return 0;

    int result = 0;
    if (c == 'X') { // X+YF
        if (dp[n-1] != -1 && dp[n-1] < p) {
            p -= dp[n-1];
        } else {
            int printed_num = process('X', n-1, p, l);
            if (printed_num == -1) return -1;
            p = 0;
            l -= printed_num;
            result += printed_num;
            if (l <= 0) return -1;
        }

        if (p == 0) {
            cout << "+";
            l--; result++;
            if (l <= 0) return -1;
        } else {
            p--;
        }

        if (dp[n-1] != -1 && dp[n-1] < p) {
            p -= dp[n-1];
        } else {
            int printed_num = process('Y', n-1, p, l);
            if (printed_num == -1) return -1;
            p = 0;
            l -= printed_num;
            result += printed_num;
            if (l <= 0) return -1;
        }

        if (p == 0) {
            cout << "F";
            l--; result++;
            if (l <= 0) return -1;
        } else {
            p--;
        }

    } else { // FX-Y
        if (p == 0) {
            cout << "F";
            l--; result++;
            if (l <= 0) return -1;
        } else {
            p--;
        }

        if (dp[n-1] != -1 && dp[n-1] < p) {
            p -= dp[n-1];
        } else {
            int printed_num = process('X', n-1, p, l);
            if (printed_num == -1) return -1;
            p = 0;
            l -= printed_num;
            result += printed_num;
            if (l <= 0) return -1;
        }

        if (p == 0) {
            cout << "-";
            l--; result++;
            if (l <= 0) return -1;
        } else {
            p--;
        }

        if (dp[n-1] != -1 && dp[n-1] < p) {
            p -= dp[n-1];
        } else {
            int printed_num = process('Y', n-1, p, l);
            if (printed_num == -1) return -1;
            p = 0;
            l -= printed_num;
            result += printed_num;
            if (l <= 0) return -1;
        }
    }
    return result;
}

int main() {
    int C;
    cin >> C;

    dp[0] = 1;
    diff[0] = 3;
    for (int i = 1; i < 50; i++) {
        if (diff[i-1] < 1000000000 && diff[i-1] != -1)
            diff[i] = diff[i-1] * 2;
        else
            diff[i] = -1;
    }
    for (int i = 1; i < 50; i++) {
        if (dp[i-1] < 1000000000 && diff[i-1] < 1000000000 && dp[i-1] != -1 && diff[i-1] != -1)
            dp[i] = dp[i-1] + diff[i-1];
        else
            dp[i] = -1;
    }

    for (int c = 0; c < C; c++) {
        int n, p, l;
        cin >> n >> p >> l;
        if (p==1) {
            cout << 'F';
            process('X', n, p-1, l-1);
        } else {
            process('X', n, p-2, l);
        }
        cout << endl;
    }
}
