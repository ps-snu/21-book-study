#include <bits/stdc++.h>
using namespace std;

int maxSq(vector<int>& h, int left, int right);

int main() {
    freopen("input.txt", "r", stdin);
    int C, N;
    cin >> C;

    for (int i = 0; i < C; i++) {
        cin >> N;
        vector<int> h(N, 0);
        for (int j = 0; j < N; j++) {
            cin >> h[j];
        }

        cout << maxSq(h, 0, N - 1) << endl;
    }
}

int maxSq(vector<int>& h, int left, int right) {
    if (left == right)
        return h[left];
    
    int cen = (left + right) / 2;
    int leftSq = maxSq(h, left, cen);
    int rightSq = maxSq(h, cen + 1, right);

    int result = max(leftSq, rightSq);

    int cenR = cen + 1;
    int minH = min(h[cen], h[cenR]);
    int width = 2;
    result = max(result, minH * width);

    while ((cen > left) || (cenR < right)) {
        width++;
        if ((h[cen - 1] > h[cenR + 1]) || (cenR == right)) {
            cen--;
            minH = min(minH, h[cen]);
            result = max(result, minH * width);
        } else {
            cenR++;
            minH = min(minH, h[cenR]);
            result = max(result, minH * width);
        }
    }

    return result;
}