#include <bits/stdc++.h>
using namespace std;
vector<int> h;

// using brute force
// int solve(int he, int res) {
//     int wi = 0;
//     int max_wi = 0;

//     if(he == 10001) return 0;

//     for(int i = 0; i < h.size(); i++) {
//         if(h[i] >= he) {
//             wi++;
//             max_wi = max(max_wi, wi);
//         }
//         else wi = 0;
//     }
//     res = max(res, he * max_wi);
//     res = max(res, solve(he+1, res));
    
//     return res;
// }

int solve(int left, int right) {
    int ret;
    if(left == right) return h[left];
    int mid = floor((left + right) / 2);
    // printf("left : %d, mid : %d, right : %d\n", left, mid, right);
    ret = max(solve(left, mid), solve(mid+1, right));

    int lo = mid; 
    int hi = mid+1;
    int height = min(h[lo], h[hi]);
    ret = max(ret, 2 * height);
    while(lo > left || hi < right) {
        if(lo > left && (hi == right || h[lo-1] > h[hi+1])) {
            height = min(height, h[--lo]);
        }
        else if(hi < right && (lo == left || h[lo-1] <= h[hi+1])){
            height = min(height, h[++hi]);
        }
        ret = max(ret, (hi-lo+1) * height);
    }
    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int n; cin >> n;
        h.clear();
        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            h.push_back(tmp);
        }
        printf("%d\n", solve(0, h.size()-1));
    }
    return 0;
}