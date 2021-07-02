#include <iostream>
#include <vector>
using namespace std;

int pairFriend(vector<vector<int>>& friends, bool* paired, int n);

int main() {
    int C, n, m;
    int p1, p2;

    cin >> C;
    for (int i = 0; i < C; i++) {
        cin >> n >> m;
        vector<vector<int>> friends(n, vector<int> (n, 0));
        bool paired[10] = {false};

        for (int j = 0; j < m; j++) {
            cin >> p1 >> p2;
            friends[p1][p2] = 1;
            friends[p2][p1] = 1;
        }

        cout << pairFriend(friends, paired, n) << endl;
    }

    return 0;
}

int pairFriend(vector<vector<int>>& friends, bool* paired, int n) {
    bool done = true;
    int minFriend;
    for (int i = 0; i < n; i++) {
        if (!paired[i]) {
            done = false;
            minFriend = i;
            break;
        }
    }
    if (done) return 1;

    int result = 0;
    
    for (int i = minFriend + 1; i < n; i++) {
        if (friends[minFriend][i] && !paired[i]) {
            paired[minFriend] = paired[i] = true;
            result += pairFriend(friends, paired, n);
            paired[minFriend] = paired[i] = false;
        }
    }

    return result;
}