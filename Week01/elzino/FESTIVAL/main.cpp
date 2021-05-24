#include <bits/stdc++.h>

using namespace std;

int N, L;
int partial_sums[1001];

double min_price() {
    double result = 1000.0;
    for (int i = L; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            double avg = (double)(partial_sums[j] - partial_sums[j-i]) / i;
            if (result > avg)
                result = avg;
        }
    }
    return result;
}

int main() {
    freopen("input.txt", "r", stdin);
    cout.precision(10);
    cout << fixed;
    int c;
    cin >> c;
    for (int w = 0; w < c; w++) {
        cin >> N >> L;
        memset(partial_sums, 0, sizeof(partial_sums));
        for (int i = 1; i <= N; i++) {
            int price;
            cin >> price;
            partial_sums[i] = partial_sums[i-1] + price;
        }
        cout << min_price() << endl;
    }
}