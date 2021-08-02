#include <bits/stdc++.h>

using namespace std;

int N;
int ps[50000];
int qs[50000];
int live[50000];

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> N;
        int p, q;
        scanf("%d %d\n", &p, &q);
        ps[0] = p;
        qs[0] = q;
        live[0] = 1;
        int result = 1;
        for (int i = 1; i < N; i++) {
            scanf("%d %d\n", &p, &q);
            ps[i] = p; qs[i] = q; live[i] = 1;
            int cur_live = 1;
            for (int j = 0; j < i; j++) {
                if (live[j]) {
                    if (ps[j] < p && qs[j] < q)
                        live[j] = 0;
                    else
                        cur_live += 1;
                }
            }
            result += cur_live;
        }
        cout << result << endl;
    }
}
