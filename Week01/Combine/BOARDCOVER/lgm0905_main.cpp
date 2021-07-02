#include <bits/stdc++.h>

using namespace std;

vector< vector<int> > board;

bool setting(int r, int c, int type, int delta) {
    const int coverType[4][3][2] = {
        {{0,0}, {1,0}, {0,1}},
        {{0,0}, {1,0}, {1,1}},
        {{0,0}, {1,0}, {1,-1}},
        {{0,0}, {0,1}, {1,1}},
    };

    bool is_valid = true;
    for(int i = 0; i < 3; i++) {
        int tmp_r = r + coverType[type][i][0];
        int tmp_c = c + coverType[type][i][1];

        if(tmp_r < 0 || tmp_c < 0 || tmp_r > board.size()-1 || tmp_c > board[0].size() -1 ) {
            is_valid = false;
            break;
        }
        else if((board[tmp_r][tmp_c] += delta) > 1) {
            is_valid = false;
        }
    }

    return is_valid;
}

int cover() {
    int r = -1; int c = -1;

    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(board[i][j] == 0) {
                r = i; c = j;
                break;
            }
        }
        if(c != -1) break;
    } 

    if(c == -1) return 1;

    int res = 0;
    for(int t = 0; t < 4; t++) {
        if(setting(r, c, t, 1)) {
            res += cover();
        }
        setting(r, c, t, -1);
    }

    return res;
}

int main() {
    int C;

    // freopen("input.txt", "r", stdin);

    cin >> C;
    for(int c = 0; c < C; c++) {
        board.clear();
        int H,W;
        cin >> H >> W;
        for(int h = 0; h < H; h++) {
            string point; cin >> point;
            vector<int> v;
            for(int w = 0; w < W; w++) {
                v.push_back((point[w] == '#') ? 1 : 0);
            }
            board.push_back(v);
        }

        printf("%d\n", cover());
    }
}