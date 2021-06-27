#include <bits/stdc++.h>

using namespace std;

// 0 : 0, 3, 5
// 1 : 0, 8
// 2 : 0, 5, 8
// 3 : 1, 6, 8, 9
// 4 : 2, 3, 7, 8, 9
// 5 : 3, 7, 8, 9
// 6 : 3, 4
// 7 : 1, 3, 4, 7
// 8 : 4
// 9 : 1, 9
// 10 : 2, 4
// 11 : 1
// 12 : 4
// 13 : 9
// 14 : 2, 5, 6, 7
// 15 : 2, 5, 6, 7
vector<vector<int> > swit ({
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
vector<int> clk;

// 1 to go, 0 to back
void move(int n, int go) {
    for(vector<int>::iterator iter = swit[n].begin(); iter != swit[n].end(); iter++) {
        if(go) clk[*iter] = (clk[*iter] + 3) > 12 ? 3 : (clk[*iter] + 3);
        else clk[*iter] = (clk[*iter] - 3) == 0 ? 12 : (clk[*iter] - 3);
    }
}

bool check() {
    for(int i = 0; i < 16; i++) {
        if(clk[i] != 12) return false;
    }
    return true;
}

// void p() {
//     for(int i = 0; i < clk.size(); i++)
//         printf("%d ", clk[i]);
//     printf("\n");
// } 

int solve(int n) {
    if(n == 10) {
        return check() ? 0 : 31;
    }
    int res = 31;

    for(int j = 0; j <= 3; j++) {
        for(int k = 0; k < j; k++) {
            move(n,1); 
        }
        // p();
        res = min(res, solve(n+1) + j);
        for(int k = 0; k < j; k++) {
            move(n,0);
        }
    }

    return res;
}


int main() {
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T; 
    for(int t = 0; t < T; t++) {
        clk.clear();

        for(int i = 0; i < 16; i++) {
            int c; 
            cin >> c; 
            clk.push_back(c);
        }
        int res = solve(0);
        res = res >= 31 ? -1 : res;
        printf("%d\n", res);
    }
}