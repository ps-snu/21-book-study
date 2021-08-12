#include <bits/stdc++.h>
using namespace std;

int C, N, in;
vector<int> sorted, num;
map<vector<int>, int> dist;
vector<bool> calculated;

vector<int> reflect(vector<int>& v, int left, int right) {
    vector<int> ret = v;
    reverse(ret.begin() + left, ret.begin() + right);

    return ret;
}

void preCalc() {
    if (calculated[N - 1]) return;
    calculated[N - 1] = true;

    queue<vector<int>> q;
    q.push(sorted);
    dist[sorted] = 0;

    while (!q.empty()) {
        vector<int> v = q.front();
        q.pop();

        int d = dist[v];
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N + 1; j++) {
                vector<int> r = reflect(v, i, j);

                if (dist.find(r) == dist.end()) {
                    q.push(r);
                    dist[r] = d + 1;
                }
            }
        }
    }
}

void rankNum() {
    vector<int> newArray = num;
    sort(newArray.begin(), newArray.end());

    map<int, int> ranks;
    int rank = 1;
    for (int i = 0; i < N; i++) {
        int elm = newArray[i];

        if (ranks[elm] == 0)
            ranks[elm] = rank++;
    }

    for (int i = 0; i < N; i++)
        num[i] = ranks[num[i]];
}

int main() {
    cin >> C;
    calculated = vector<bool>(8, false);

    for (int tc = 0; tc < C; tc++) {
        cin >> N;
        num.clear();
        sorted.clear();
        for (int n = 0; n < N; n++) {
            sorted.push_back(n + 1);
            cin >> in;
            num.push_back(in);
        }

        rankNum();
        preCalc();

        cout << dist[num] << endl;
    }
}