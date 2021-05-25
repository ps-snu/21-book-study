#include <bits/stdc++.h>

using namespace std;

int heights[20000];

int divide_conquer(int start, int end) {
    if (start == end) {
        return heights[start];
    }
    int mid = start + (end - start) / 2;
    int result_l = divide_conquer(start, mid);
    int result_r = divide_conquer(mid+1, end);

    int left = mid;
    int right = mid+1;
    int height = min(heights[left], heights[right]);
    int result_m = height * (right + 1 -left);

    while (start < left || right < end) {
        if (start == left) {
            right++;
            height = min(height, heights[right]);
        } else if (right == end) {
            left--;
            height = min(height, heights[left]);
        } else {
            if (heights[left-1] < heights[right+1]) {
                right++;
                height = min(height, heights[right]);
            } else {
                left--;
                height = min(height, heights[left]);
            }
        }
        result_m = max(result_m, height * (right + 1 - left));
    }
    return max({result_m, result_l, result_r});
}

int main() {
    freopen("input.txt", "r", stdin);
    int c;
    cin >> c;
    for (int w = 0; w < c; w++) {
        memset(heights, 0, sizeof(heights));
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }
        cout << divide_conquer(0, n-1) << endl;
    }
}
