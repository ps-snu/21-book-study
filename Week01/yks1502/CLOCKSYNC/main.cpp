#include <iostream>
#include <vector>
using namespace std;

void pushSwitch(int* clock, int sw);
int sync(int* clock, int idx);

vector<vector<int>> switches = {
    {0, 1, 2},
    {3, 7, 9, 11},
    {4, 10, 14, 15},
    {0, 4, 5, 6, 7},
    {6, 7, 8, 10, 12},
    {0, 2, 14, 15},
    {3, 14, 15},
    {4, 5, 7, 14, 15},
    {1, 2, 3, 4, 5},
    {3, 4, 5, 9, 13}
};

int main() {
    int C;
    int clock[16];
    cin >> C;

    for (int i = 0; i < C; i++) {
        for (int j = 0; j < 16; j++) {
            cin >> clock[j];
            clock[j] %= 12;
        }
        
        int result = sync(clock, 0);
        result = result == INT_MAX ? -1 : result;
        cout << result << endl;
    }
}

void pushSwitch(int* clock, int sw) {
    int wiredClocks = switches[sw].size();
    for (int i = 0; i < wiredClocks; i++) {
        int wiredClock = switches[sw][i];
        clock[wiredClock] = (clock[wiredClock] + 3) % 12;
        cout << sw << " " << wiredClocks << " " << wiredClock << endl;
    }
}

int sync(int* clock, int idx) {
    bool allSync = true;

    for (int i = 0; i < 16; i++) {
        if (clock[i] != 0) {
            allSync = false;
            break;
        }
        if (!allSync) break;
    }

    if (allSync) return 0;
    if (idx == 10) return INT_MAX;

    int result = INT_MAX;

    for (int i = 0; i < 4; i++) {
        result = min(i + sync(clock, idx + 1), result);
        pushSwitch(clock, idx);
    }

    return result;
}
