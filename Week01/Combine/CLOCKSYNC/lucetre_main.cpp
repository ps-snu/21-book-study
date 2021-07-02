#include <bits/stdc++.h>
#define N 16
typedef unsigned int uint;
using namespace std;
vector<vector<int> > button ({
    vector<int>({0, 1, 2}),
    vector<int>({3, 7, 9, 11}),
    vector<int>({4, 10, 14, 15}),
    vector<int>({0, 4, 5, 6, 7}),
    vector<int>({6, 7, 8, 10, 12}),
    vector<int>({0, 2, 14, 15}),
    vector<int>({3, 14, 15}),
    vector<int>({4, 5, 7, 14, 15}),
    vector<int>({1, 2, 3, 4, 5}),
    vector<int>({3, 4, 5, 9, 13})
});
int res = INT_MAX;

uint get_time(uint clk, int num) {
    return ((clk & (3 << num*2)) >> num*2);
}
uint set_time(uint clk, int num, uint time) {
    clk -= (get_time(clk, num) << num*2);
    clk += ((time % 4) << num*2);
    return clk;
}
/* void print_clk(uint clk) {
    for (int i = 0; i < N; i++)
        cout << get_time(clk, i) << " ";
    cout << endl;
} */

void process(uint clk, int lev, int step) {
    if (lev >= button.size()) {
        if (clk == 0) res = min(res, step);
        return;
    }
    for (int i = 0; i < 4; i++) {
        uint tclk = clk;
        for (int j = 0; j < button[lev].size(); j++) {
            int num = button[lev][j];
            tclk = set_time(tclk, num, get_time(tclk, num)+i);
        }
        process(tclk, lev+1, step+i);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        uint clk = 0;
        for (int i = 0; i < N; i++) {
            uint time; cin >> time;
            clk = set_time(clk, i, time/3);
        }
        res = INT_MAX;
        process(clk, 0, 0);
        cout << (res==INT_MAX ? -1 : res) << endl;
    }
    return 0;
}