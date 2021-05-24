#include <bits/stdc++.h>

using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

char board[5][5];
int memo[10][5][5];

string s;

bool check_match(int i, int j, int index) {
    if (index == s.size())
        return true;
    if (i < 0 || i >= 5 || j < 0 || j >= 5)
        return false;
    if (board[i][j] != s[index])
        return false;
    if (memo[index][i][j] == 0)
        return false;
    if (memo[index][i][j] == 1)
        return true;
    bool matching = false;
    for (int k = 0; k < 8; k++) {
        if (check_match(i+dy[k], j+dx[k], index+1)) {
            matching = true;
            break;
        }
    }
    memo[index][i][j] = matching ? 1 : 0;
    return matching;
}

int main() {
    freopen("input.txt", "r", stdin);
    int c;
    cin >> c;
    for (int w = 0; w < c; w++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                char alphabet;
                cin >> alphabet;
                board[i][j] = alphabet;
            }
        }
        int n;
        cin >> n;
        for (int k = 0; k < n; k++) {
            memset(memo, -1, sizeof(memo));
            cin >> s;
            bool matching = false;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (check_match(i, j, 0)) {
                        matching = true;
                        break;
                    }
                }
                if (matching)
                    break;
            }
            if (matching) {
                cout << s << " " << "YES" << endl;
            } else {
                cout << s << " " << "NO" << endl;
            }
        }
    }
}
