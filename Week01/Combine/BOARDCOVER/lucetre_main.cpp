#include <bits/stdc++.h>
using namespace std;
#define M 20
int a[M+1][M+1];
int dy[4][3] = {{0, 1, 1}, {0, 1, 0}, {0, 0, 1}, {0, 1, 1}};
int dx[4][3] = {{0, 0, -1}, {0, 0, 1}, {0, 1, 1}, {0, 0, 1}};
int h, w, res;

void process(int cnt, int f) {
    if (cnt == 0) {
        res++;
        return;
    }
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (a[y][x]) {
                if (y*w+x <= f) return;
                for (int type = 0; type < 4; type++) {
                    bool flag = true;
                    for (int d = 0; d < 3; d++) {
                        int ty = y + dy[type][d];
                        int tx = x + dx[type][d];
                        if (ty < 0 || tx < 0 || ty >= h || tx >= w || !a[ty][tx]) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        for (int d = 0; d < 3; d++)
                            a[y + dy[type][d]][x + dx[type][d]] = 0;
                        process(cnt-3, y*w+x);
                        for (int d = 0; d < 3; d++)
                            a[y + dy[type][d]][x + dx[type][d]] = 1;
                    }
                }
            }
        }
    }

}

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> h >> w;
        res = 0;
        int cnt = 0;
        for (int i = 0; i < h; i++) {
            string s; cin >> s;
            for (int j = 0; j < w; j++) 
                cnt += a[i][j] = (s[j] == '.');
        }
        process(cnt, -1);
        cout << res << endl;
    }
    return 0;
}