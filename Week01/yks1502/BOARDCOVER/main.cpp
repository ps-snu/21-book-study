#include <iostream>
#include <vector>
#include <string>
using namespace std;

int cover(vector<string>& board, int h, int w);

int block[4][3][2] = {
    {{0, 0}, {0, 1}, {1, 0}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}}
};

int main() {
    int C, H, W;
    cin >> C;

    for (int i = 0; i < C; i++) {
        cin >> H >> W;
        vector<string> board(H);
        for (int j = 0; j < H; j++) {
            cin >> board[j];
        }

        int initR = -1, initC = -1;

        for (int r = 0; r < H; r++) {
            for (int c = 0; c < W; c++) {
                if (board[r][c] == '.') {
                    initR = r;
                    initC = c;
                    break;
                }
            }
            if (initR != -1) break;
        }

        cout << cover(board, H, W) << endl;
    }


}

int cover(vector<string>& board, int h, int w) {
    int r = -1, c = -1;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (board[i][j] == '.') {
                r = i;
                c = j;
                break;
            }
        }
        if (r != -1) break;
    }

    if (r == -1) return 1;

    int result = 0;

    for (int i = 0; i < 4; i++) {
        bool fullyCovered = true;
        for (int j = 0; j < 3; j++) {
            int blockR = r + block[i][j][0];
            int blockC = c + block[i][j][1];

            if (blockR < 0 || blockC < 0 || blockR == h || blockC == w) {
                fullyCovered = false;
                break;
            }
            if (board[blockR][blockC] == '#') {
                fullyCovered = false;
                break;
            }
        }

        if (fullyCovered) {
            for (int j = 0; j < 3; j++) {
                int blockR = r + block[i][j][0];
                int blockC = c + block[i][j][1];
                board[blockR][blockC] = '#';
            }

            result += cover(board, h, w);

            for (int j = 0; j < 3; j++) {
                int blockR = r + block[i][j][0];
                int blockC = c + block[i][j][1];
                board[blockR][blockC] = '.';
            }
        }
    }

    return result;
}
