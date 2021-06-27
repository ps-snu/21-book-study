#include <bits/stdc++.h>
using namespace std;

bool hug(int idol, int fan);

int main() {
    freopen("input.txt", "r", stdin);
    int C, result;
    string idol, fan;
    int idolLen, fanLen;
    long long int idolB, fanB;
    cin >> C;

    for (int i = 0; i < C; i++) {
        cin >> idol;
        cin >> fan;
        idolLen = idol.length();
        fanLen = fan.length();
        idolB = fanB = result = 0;

        for (int j = 0; j < idolLen; j++) {
            char mf = idol.at(j);
            idolB = idolB << 1;
            if (mf == 'M') idolB++;
        }

        for (int j = 0; j < fanLen; j++) {
            char mf = fan.at(j);
            fanB = fanB << 1;
            if (mf == 'M') fanB++;

            if (j >= idolLen - 1) {
                bool allHug = hug(idolB, fanB);
                if (allHug) result++;
                fanB %= ((long long int) 1 << idolLen);
            }
        }
        
        cout << result << endl;
    }
}

bool hug(int idol, int fan) {
    int result = idol & fan;
    return result == 0;
}
