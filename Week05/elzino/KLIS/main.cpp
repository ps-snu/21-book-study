#include <bits/stdc++.h>

using namespace std;

int N, K;
int inputs[501];
int dp[501];
unsigned int LIS_num[501];
pair<int, int> candidate[500];

int process(int start_index) {
    int &result = dp[start_index];
    if (result != -1) return result;
    result = 1;
    unsigned int &lnum = LIS_num[start_index];
    lnum = 1;
    for (int i = start_index+1; i <= N; i++) {
        if (inputs[start_index] < inputs[i]) {
            if (result < 1 + process(i)) {
                result = 1 + process(i);
                lnum = LIS_num[i];
            } else if (result == 1 + process(i)) {
                if (LIS_num[i] == 0)
                    lnum = 0;
                else if (lnum != 0)
                    lnum += LIS_num[i];
                if (lnum > INT_MAX)
                    lnum = 0;
            }
        }
    }
    return result;
}

void print_k_lis(int start_ind, int k, int len) {
    if (len == 0) return;
    int cand_num = 0;
    for (int i = start_ind+1; i <= N; i++) {
        if (dp[start_ind]-1 == dp[i] && inputs[start_ind] < inputs[i]) {
            candidate[cand_num] = {inputs[i], i};
            cand_num += 1;
        }
    }
    sort(candidate, candidate + cand_num);
    for (int i = 0; i < cand_num; i++) {
        if (LIS_num[candidate[i].second] == 0 || k <= LIS_num[candidate[i].second]) {
            cout << candidate[i].first << " ";
            print_k_lis(candidate[i].second, k, len-1);
            break;
        } else {
            k -= LIS_num[candidate[i].second];
        }
    }
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> N >> K;
        for (int i = 1; i <= N; i++) {
            cin >> inputs[i];
        }
        inputs[0] = 0;
        memset(dp, -1, sizeof(dp));
        memset(LIS_num, 0, sizeof(LIS_num));
        cout << process(0) -1 << endl;
        print_k_lis(0, K, process(0) -1);
        cout << endl;
    }
}
