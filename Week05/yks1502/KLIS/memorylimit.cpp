#include <bits/stdc++.h>
using namespace std;

int C, N, K, maxLen;
int arr[500], len[500];
vector<vector<int>> result;
vector<vector<int>> cache[500];

void klis() {
    len[0] = 1;
    cache[0].clear();
    vector<int> s;
    s.push_back(arr[0]);
    cache[0].push_back(s);

    for (int i = 1; i < N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] > arr[j]) {
                if (len[i] < len[j] + 1) {
                    len[i] = len[j] + 1;

                    cache[i].clear();
                    for (int k = 0; k < cache[j].size(); k++) {
                        s = cache[j][k];
                        s.push_back(arr[i]);
                        cache[i].push_back(s);
                    }
                } else if (len[i] == len[j] + 1) {
                    for (int k = 0; k < cache[j].size(); k++) {
                        s = cache[j][k];
                        s.push_back(arr[i]);
                        cache[i].push_back(s);
                    }
                }
            }
        }

        if (len[i] == 0) {
            len[i] = 1;
            s.clear();
            s.push_back(arr[i]);
            cache[i].clear();
            cache[i].push_back(s);
        }

        maxLen = max(maxLen, len[i]);
    }

    result.clear();
    for (int i = 0; i < N; i++) {
        if (len[i] == maxLen) {
            for (int j = 0; j < cache[i].size(); j++)
                result.push_back(cache[i][j]);
        }
    }
    sort(result.begin(), result.end());
}

int main() {
    cin >> C;
    for (int tc = 0; tc < C; tc++) {
        cin >> N >> K;
        for (int n = 0; n < N; n++)
            cin >> arr[n];

        maxLen = 0;
        memset(len, 0, sizeof(len));

        klis();

        cout << maxLen << endl;
        for (int i = 0; i < maxLen; i++) {
            cout << result[K - 1][i] << " ";
        }
        cout << endl;
    }
}