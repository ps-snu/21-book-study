#include <bits/stdc++.h>
using namespace std;

const int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int cache[5][5][10];
string board[5];
string word;
int C, N;

bool find(int r, int c, int idx) {
    if (r < 0 || c < 0 || r == 5 || c == 5) return false;

    int& ca = cache[r][c][idx];
    if (ca != -1) return ca;
    if (board[r][c] != word[idx]) return ca = 0;
    if (idx + 1 == word.size()) return ca = 1;

    for (int i = 0; i < 8; i++) {
        int new_r = r + dr[i];
        int new_c = c + dc[i];
        if (find(new_r, new_c, idx + 1) == 1) {
            return ca = 1;
        };
    }

    return ca = 0;
}

int main() {
    cin >> C;
    for (int tc = 0; tc < C; tc++) {
        for (int i = 0; i < 5; i++) {
            cin >> board[i];
        }

        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> word;
            memset(cache, -1, sizeof(cache));

            bool found = false;
            for (int r = 0; r < 5; r++) {
                for (int c = 0; c < 5; c++) {
                    if (find(r, c, 0) == 1) {
                        found = true;
                        break;
                    }
                }
            }

            if (found) {
                cout << word << " YES" << endl;
            } else {
                cout << word << " NO" << endl;
            }
        }
    }
}
