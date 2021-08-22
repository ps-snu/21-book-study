#include <bits/stdc++.h>

using namespace std;

#define MAX_DISK_NUM 12

int N;

int getPos(int state, int index) {
    return (state >> (2*index)) & 3;
}

int setPos(int state, int index, int value) {
    return (state & ~ (3 << (2 * index))) | (value << (2 * index));
}

int convert(vector<int>& pos) {
    int state = 0;
    for (int i = 0; i < pos.size(); i++) {
        state |= setPos(state, i, pos[i]);
    }
    return state;
}

int getFinalState() {
    int state = 0;
    for (int i = 0; i < N; i++)
        state |= setPos(state, i, 3);
    return state;
}

int getSign(int num) {
    return num > 0;
}

int incr(int num) {
    return (num > 0) ? num + 1 : num - 1;
}

void solve(int start) {
    vector<int> distances(1 << (2*MAX_DISK_NUM), 0);
    queue<int> q;
    int end = getFinalState();
    distances[start] = 1;
    q.push(start);
    distances[end] = -1;
    q.push(end);
    while(!q.empty()) {
        int here = q.front();
        q.pop();
        vector<int> top(4, -1);
        for (int i = N-1; i >= 0; i--) {
            top[getPos(here, i)] = i;
        }
        for (int i = 0; i < 4; i++) {
            if (top[i] == -1) continue;
            for (int j = 0; j < 4; j++) {
                if (top[j] != -1 && top[i] >= top[j])
                    continue;
                int there = setPos(here, top[i], j);
                if (distances[there] == 0) {
                    distances[there] = incr(distances[here]);
                    q.push(there);
                } else if (getSign(distances[here]) != getSign(distances[there])) {
                    cout << abs(distances[here]) + abs(distances[there]) - 1 << endl;
                    return;
                }
            }
        }
    }
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> N;
        vector<int> diskPos(N, -1);
        for (int i = 0; i < 4; i++) {
            int num, id;
            cin >> num;
            for (int j = 0; j < num; j++) {
                cin >> id;
                diskPos[id-1] = i;
            }
        }
        int state = convert(diskPos);
        solve(state);
    }
}
