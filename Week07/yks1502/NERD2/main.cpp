#include <bits/stdc++.h>
using namespace std;

int main() {
    int C, N, p, q, result;
    map<int, int> tree;

    cin >> C;
    for (int i = 0; i < C; i++) {
        cin >> N;
        result = 0;
        tree.clear();

        for (int j = 0; j < N; j++) {
            scanf("%d %d", &p, &q);

            auto it = tree.lower_bound(p);

            if (it != tree.end() && q < it->second){
                result += tree.size();
                continue;
            }

            if (it != tree.begin()) {
                it--;
                while (true) {
                    if (it->second > q) break;
                    if (it == tree.begin()) {
                        tree.erase(it);
                        break;
                    }
                    else tree.erase(it--);
                }
            }

            /*while (it != tree.begin()) {
                it--;
                if (it->second > q) break;
                tree.erase(it);
            }*/

            tree[p] = q;
            result += tree.size();
        }

        cout << result << endl;
    }
}