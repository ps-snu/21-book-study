#include <bits/stdc++.h>

using namespace std;

int inputs[500];
int memo[500];

int max_len;

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        int N;
        cin >> N;
        max_len = 1;
        for (int i = 0; i < N; i++) {
            cin >> inputs[i];
        }
        memo[0] = 1;
        for (int i = 1; i < N; i++) {
            int cur_max = 0;
            for (int j = 0; j < i; j++) {
                if (inputs[j] < inputs[i] && memo[j] > cur_max)
                    cur_max = memo[j];
            }
            memo[i] = cur_max + 1;
            if (max_len < memo[i])
                max_len = memo[i];
        }
        cout << max_len << endl;
    }
}
