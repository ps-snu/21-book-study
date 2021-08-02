#include <bits/stdc++.h>
using namespace std;

int C, N, a, b, result, A;

int main() {
    cin >> C;
    for (int i = 0; i < C; i++) {
        cin >> N >> a >> b;

        priority_queue<int, vector<int>, less<int>> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        A = 1983;

        for (int j = 0; j < N; j++) {
            if (j % 2) minHeap.push(A);
            else maxHeap.push(A);

            if (j > 1) {
                if (maxHeap.top() > minHeap.top()) {
                    int tmp1 = maxHeap.top();
                    int tmp2 = minHeap.top();
                    maxHeap.pop();
                    maxHeap.push(tmp2);
                    minHeap.pop();
                    minHeap.push(tmp1);
                }

                result = (result + maxHeap.top()) % 20090711;
            } else if (j == 0) {
                result = A;
            } else {
                result = (result + min(result, A)) % 20090711;
            }

            A = (A * (long long)a + b) % 20090711;
        }

        cout << result << endl;
    }
}