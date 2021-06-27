#include <bits/stdc++.h>
using namespace std;

int C, N;
int elm[500];
int cache[500];
int result;

int lis(int idx) {
    if (idx == N - 1) return 1;
    int& ca = cache[idx];
    if (ca != -1) return ca;
    ca = 1;
    for (int i = idx + 1; i < N; i++) {
        if (elm[idx] < elm[i]) {
            ca = max(ca, 1 + lis(i));
        }
    }
    return ca;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> C;
    for (int i = 0; i < C; i++) {
        cin >> N;
        memset(cache, -1, sizeof(cache));
        result = 0;
        for (int j = 0; j < N; j++) {
            cin >> elm[j];
        }
        
        for (int j = 0; j < N; j++) {
            lis(j);
        }

        for (int j = 0; j < N; j++) {
            result = max(result, cache[j]);
        }
        
        cout << result << endl;
    }
}