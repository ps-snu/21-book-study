#include <bits/stdc++.h>
using namespace std;

int C, N, K, maxLen;
int arr[500], len[500];
vector<string> cache[500], result;
vector<int> parents[500];

void preCalc() {
    len[0] = 1;
    parents[0].clear();

    for (int i = 1; i < N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[i] > arr[j]) {
                if (len[i] < len[j] + 1) {
                    len[i] = len[j] + 1;

                    parents[i].clear();
                    parents[i].push_back(j);
                } else if (len[i] == len[j] + 1) {
                    parents[i].push_back(j);
                }
            }
        }

        if (len[i] == 0) {
            len[i] = 1;
            parents[i].clear();
        }

        maxLen = max(maxLen, len[i]);
    }
}

vector<string> klis(int idx) {
    vector<string>& s = cache[idx];
    if (s.size() > 0)
        return s;

    if (len[idx] == 1) {
        s.push_back(to_string(arr[idx]) + " ");
        return s;
    }
    
    for (int i = 0; i < parents[idx].size(); i++) {
        vector<string> v = klis(parents[idx][i]);
        for (auto p : v) {
            string next = p;
            next += to_string(arr[idx]) + " ";
            s.push_back(next);
        }
    }

    return s;
}

int main() {
    cin >> C;
    for (int tc = 0; tc < C; tc++) {
        cin >> N >> K;
        for (int n = 0; n < N; n++)
            cin >> arr[n];

        maxLen = 0;
        memset(len, 0, sizeof(len));

        preCalc();
        for (int i = 0; i < N; i++)
            cache[i].clear();

        result.clear();
        for (int i = N - 1; i >= 0; i--) {
            if (len[i] == maxLen) {
                vector<string> s = klis(i);
                for (auto p : s)
                    result.push_back(p);
            }
        }
        sort(result.begin(), result.end());

        cout << maxLen << endl;
        cout << result[K - 1] << endl;
    }
}