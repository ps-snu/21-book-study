#include <bits/stdc++.h>

using namespace std;

char board[5][5];
int memo[10][5][5];

void print_msg(bool is_exist, char* wd) {
    printf("%s ", wd);
    if(is_exist) printf("YES\n");
    else printf("NO\n");
}

vector< pair<int, int> > first_find(char target) {
    vector< pair<int, int> > pv;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(board[i][j] == target) {
                pv.push_back(make_pair(i,j));
            }
        }
    }
    return pv;
}

bool find(char* wd, int idx, pair<int,int> point) {
    if(wd[idx] == '\0') {
        return true;
    }

    int x_mv[3] = {-1,0,1};
    int y_mv[3] = {-1,0,1};
    int x; int y;

    vector< pair<int,int> > pv;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(x_mv[i] == 0 && y_mv[j] == 0) continue;

            x = point.first + x_mv[i];
            y = point.second + y_mv[j];
            if(x > 4 || y > 4 || x < 0 || y < 0) continue;

            if(board[x][y] == wd[idx]) pv.push_back(make_pair(x,y)); 
        }
    }

    for(int i = 0; i < pv.size(); i++) {
        if(memo[idx][point.first][point.second] == 1) return true;
        else if(memo[idx][point.first][point.second] == 0) return false;

        if(find(wd, idx+1, pv.at(i))) {
            memo[idx][point.first][point.second] = 1;
            return true;
        }
    } 
    
    memo[idx][point.first][point.second] = 0;
    return false;
}

int main() {
    int T; int T_W;
    freopen("input.txt", "r", stdin);

    cin >> T;
    for(int t = 0; t < T; t++) {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                cin >> board[i][j];
            }
        }

        cin >> T_W;
        for(int t_w = 0; t_w < T_W; t_w++) {
            memset(memo, -1, sizeof(memo));

            char wd[10];
            int idx = 0;
            vector< pair<int, int> > points;

            cin >> wd;
            points = first_find(wd[idx++]);
            if(points.empty()) {
                print_msg(false, wd);
                continue;
            }

            for(int p = 0; p < points.size(); p++) {
                if(find(wd, idx, points.at(p))) {
                    print_msg(true, wd);
                    break;
                }
                else if(p == points.size()-1) {
                    print_msg(false, wd);
                }
                else continue;
            }
        }
    }
}