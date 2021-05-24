#include <bits/stdc++.h>

using namespace std;

int board[20][20];
int h, w;

int dx[4][2] = {{-1, 0}, {0, 1}, {1, 1}, {1, 0}};
int dy[4][2] = {{1, 1}, {1, 1}, {0, 1}, {0, 1}};

bool put_tile(int i, int j, int shape) {
    int row = i+dy[shape][0];
    int col = j+dx[shape][0];
    if (row >= h || col >= w)
        return false;
    if (board[row][col])
        return false;
    row = i+dy[shape][1];
    col = j+dx[shape][1];
    if (row >= h || col >= w)
        return false;
    if (board[row][col])
        return false;

    board[i][j] = 1;
    board[row][col] = 1;
    board[i+dy[shape][0]][j+dx[shape][0]] = 1;
    return true;
}

void remove_tile(int i, int j, int shape) {
    board[i][j] = 0;
    board[i+dy[shape][0]][j+dx[shape][0]] = 0;
    board[i+dy[shape][1]][j+dx[shape][1]] = 0;
}

int count() {
    int result = 0;
    int i, j;
    for (i = 0; i < h; i++) {
        bool break_loop = false;
        for (j = 0; j < w; j++) {
            if (!board[i][j]) {
                break_loop = true;
                break;
            }
        }
        if (break_loop)
            break;
    }
    if (i == h && j == w) {
        return 1;
    }
    for (int k = 0; k < 4; k++) {
        if (!put_tile(i, j, k))
            continue;
        result += count();
        remove_tile(i, j, k);
    }
    return result;
}

int main() {
    freopen("input.txt", "r", stdin);
    int c;
    cin >> c;
    for (int q = 0; q < c; q++) {
        memset(board, -1, sizeof(board));
        cin >> h >> w;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char temp;
                cin >> temp;
                if (temp == '#') {
                    board[i][j] = 1;
                } else {
                    board[i][j] = 0;
                }
            }
        }
        cout << count() << endl;
    }
}
