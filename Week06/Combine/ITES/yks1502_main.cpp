#include <bits/stdc++.h>
using namespace std;

int C, K, N, result, sum;
unsigned int A, sig;
queue<int> q;

int main() {
    cin >> C;
    
    for (int i = 0; i < C; i++) {
        cin >> K >> N;

        while (!q.empty()) q.pop();
        A = 1983;
        sig = A % 10000 + 1;
        result = 0;
        sum = 0;
        
        for (int j = 0; j < N; j++) {
            q.push(sig);
            sum += sig;

            if (sum == K) {
                result++;
                sum -= q.front();
                q.pop();
            } else if (sum > K) {
                while (sum > K) {
                    sum -= q.front();
                    q.pop();
                }

                if (sum == K) {
                    result++;
                    sum -= q.front();
                    q.pop();
                }
            }

            A = A * 214013 + 2531011;
            sig = A % 10000 + 1;
        }

        cout << result << endl;
    }
}