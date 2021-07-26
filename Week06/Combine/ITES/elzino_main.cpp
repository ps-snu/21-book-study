#include <bits/stdc++.h>

using namespace std;


int K, N;

long long get_next_num(long long a) {
    return (a * 214013 + 2531011) % ((long long)1 << 32);
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> K >> N;
        int result = 0;
        int current_sum = 0;
        long long a = 1983;
        int signal = a % 10000 + 1;
        queue<int> q;
        for (int i = 0; i < N; i++) {
            current_sum += signal;
            q.push(signal);
            while (current_sum >= K) {
                if (current_sum == K) result++;
                int front = q.front();
                current_sum -= front;
                q.pop();
            }
            a = get_next_num(a);
            signal = a % 10000 + 1;
        }
        cout << result << endl;
    }
}
