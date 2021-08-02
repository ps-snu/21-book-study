#include <bits/stdc++.h>
using namespace std;

int C, N;
int A[50000];

int main() {
    cin >> C;
    for (int i = 0; i < C; i++) {
        cin >> N;
        for (int j = 0; j < N; j++)
            cin >> A[j];

        vector<int> before, sorted;
        for (int j = 1; j <= N; j++)
            sorted.push_back(j);
        
        for (int j = N - 1; j >= 0; j--) {
            auto it = sorted.end() - A[j] -1;
            before.push_back(*it);
            sorted.erase(it);
        }

        for (int j = N - 1; j > 0; j--) {
            cout << before[j] << " ";
        }
        cout << before[0] << endl;
    }
}