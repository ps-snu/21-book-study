#include <bits/stdc++.h>

using namespace std;

int N, W;
string names[101];
int volumes[101];
int need[101];

int dp[101][1001];
int next_item[101][1001];

int process(int start, int capacity) {
    int &result = dp[start][capacity];
    if (result != -1) return result;
    result = need[start];
    int rest = capacity - volumes[start];
    for (int i = start+1; i <= N; i++) {
        if (rest >= volumes[i]) {
            int temp = need[start] + process(i, rest);
            if (result < temp) {
                result = temp;
                next_item[start][capacity] = i;
            }
        }
    }
    return result;
}

vector<int> get_items() {
    vector<int> items;
    int index = 0;
    int rest = W;
    while(next_item[index][rest] != -1) {
        items.push_back(next_item[index][rest]);
        int prev_index = index;
        index = next_item[prev_index][rest];
        rest -= volumes[prev_index];
    }
    return items;
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> N >> W;
        volumes[0] = need[0] = 0;
        for (int i = 1; i <= N; i++)
            cin >> names[i] >> volumes[i] >> need[i];
        memset(dp, -1, sizeof(dp));
        memset(next_item, -1, sizeof(next_item));
        process(0, W);
        vector<int> items = get_items();
        cout << dp[0][W] << " " << items.size() << endl;
        for (int i = 0; i < items.size(); i++) cout << names[items[i]] << endl;
    }
}
