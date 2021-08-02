#include <bits/stdc++.h>

using namespace std;

int N;

map<int, int> xy;

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> N;
        int p, q;
        int result = 0;
        xy.clear();
        for (int i = 0; i < N; i++) {
            scanf("%d %d\n", &p, &q);
            auto right_iter = xy.lower_bound(p);
            if (right_iter == xy.end() || q > right_iter->second) {
                auto iter_and_bool = xy.insert({p, q});
                auto left_iter = iter_and_bool.first;
                while (left_iter != xy.begin()) {
                    left_iter = prev(left_iter);
                    if (left_iter->second < q) {
                        auto temp_it = left_iter;
                        left_iter = next(left_iter);
                        xy.erase(temp_it);
                    } else {
                        break;
                    }
                }
            }
            result += xy.size();
        }
        cout << result << endl;
    }
}
