#include <bits/stdc++.h>

using namespace std;

int N, K;

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> N >> K;
        list<int> soldiers;
        int live_num = N;
        for (int i = 1; i <= N; i++) {
            soldiers.push_back(i);  
        }
        auto iter = soldiers.begin();
        int step = 1;
        while(true) {
            step--;
            if (step == 0) {
                iter = soldiers.erase(iter);
                live_num--;
                step = K;
            } else {
                iter++;
            }
            if (live_num == 2) break;
            if (iter == soldiers.end()) {
                iter = soldiers.begin();
            }
        }
        for (const auto& s: soldiers) {
            cout << s << " ";
        }
        cout << endl;
    }
}
