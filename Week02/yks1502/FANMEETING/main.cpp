#include <bits/stdc++.h>
using namespace std;

bool hug(int idol, int fan);

int main() {
    freopen("input.txt", "r", stdin);
    int C, result;
    string idol, fan;
    int idolB, fanB, idolLen, fanLen;
    cin >> C;

    for (int i = 0; i < C; i++) {
        cin >> idol;
        cin >> fan;
        idolLen = idol.length();
        fanLen = fan.length();
        idolB = fanB = result = 0;

        for (int j = 0; j < idolLen; j++) {
            char mf = idol.at(j);
            if (mf == 'M') {
                idolB = (idolB << 1) + 1;
            } else {
                idolB = (idolB << 1) + 0;
            }
        }
        for (int j = 0; j < fanLen; j++) {
            char mf = fan.at(j);
            fanB *= 2;
            if (mf == 'M') fanB++;

            if (j >= idolLen - 1) {
                bool allHug = hug(idolB, fanB);
                if (allHug) result++;
                fanB %= (int) pow(2, idolLen);
            }
        }
        
        cout << result << endl;
    }
}

bool hug(int idol, int fan) {
    int result = idol & fan;
    return result == 0;
}