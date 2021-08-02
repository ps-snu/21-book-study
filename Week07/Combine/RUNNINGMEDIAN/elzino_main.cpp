#include <bits/stdc++.h>

using namespace std;

#define BIGNUM 20090711

int N, a, b;

long long A;

int generate_num() {
    if (A == -1) return A = 1983;
    return A = (A * a + b) % BIGNUM;
}

void push_num(priority_queue<int, vector<int>, less<int>> &low,
                priority_queue<int, vector<int>, greater<int>> &high, int num) {
    if (low.size() == 0) {
        low.push(num);
        return;
    }
    if (low.size() == high.size()) {
        if (high.top() < num) {
            low.push(high.top());
            high.pop();
            high.push(num);
        } else {
            low.push(num);
        }
    } else if (low.size() == high.size() + 1){
        if (low.top() > num) {
            high.push(low.top());
            low.pop();
            low.push(num);
        } else {
            high.push(num);
        }
    } else {
        cout << "Error happend!!!" << endl;
    }
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        // max heap
        priority_queue<int, vector<int>, less<int>> low;
        // min heap
        priority_queue<int, vector<int>, greater<int>> high;
        cin >> N >> a >> b;
        A = -1;
        int result = 0;
        for (int i = 1; i <= N; i++) {
            int num = generate_num();
            push_num(low, high, num);
            result += low.top();
            result %= BIGNUM;
        }
        cout << result << endl;
    }
}
