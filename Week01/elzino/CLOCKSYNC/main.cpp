#include <bits/stdc++.h>

using namespace std;

int clocks[17];
int switch_to_clock[10][5] = {{0,1,2,16,16}, {3,7,9,11,16}, {4,10,14,15,16}, {0,4,5,6,7}, {6,7,8,10,12},
                                {0,2,14,15,16}, {3,14,15,16,16}, {4,5,7,14,15}, {1,2,3,4,5}, {3,4,5,9,13}};

int find_min_switch_num(int switch_index) {
    if (switch_index == 2 && clocks[11])
        return 987654321;
    if (switch_index == 5 && (clocks[8] || clocks[12]))
        return 987654321;
    if (switch_index == 10) {
        for (int i = 0; i < 16; i++) {
            if (clocks[i])
                return 987654321;
        }
        return 0;
    }
    int min_num = 987654321;
    for (int i = 0; i < 4; i++) {
        int num = find_min_switch_num(switch_index+1);
        if (num < 987654321 && num+i < min_num) {
            min_num = num + i;
        }
        for (int k = 0; k < 5; k++) {
            clocks[switch_to_clock[switch_index][k]] = (clocks[switch_to_clock[switch_index][k]]+1) % 4;
        }
    }
    return min_num;
}

int main() {
    freopen("input.txt", "r", stdin);
    int c;
    cin >> c;
    for (int w = 0; w < c; w++) {
        memset(clocks, 0, sizeof(clocks));
        for (int i = 0; i < 16; i++) {
            int t;
            cin >> t;
            clocks[i] = (t / 3) % 4;
        }
        int result = find_min_switch_num(0);
        if (result < 987654321) {
            cout << result << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
