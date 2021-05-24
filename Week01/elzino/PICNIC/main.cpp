#include <bits/stdc++.h>

using namespace std;

int isFriend[10][10];
int picked[10];

int count(int stu_num, int rest_num) {
    if (rest_num == 0)
        return 1;
    int result = 0;
    int stu1 = -1;
    for (int i = 0; i < stu_num; i++) {
        if (!picked[i]) {
            stu1 = i;
            break;
        }
    }
    picked[stu1] = 1;
    for (int stu2 = stu1+1; stu2 < stu_num; stu2++) {
        if (picked[stu2])
            continue;
        if (isFriend[stu1][stu2]) {
            picked[stu2] = 1;
            result += count(stu_num, rest_num-2);
            picked[stu2] = 0;
        }
    }
    picked[stu1] = 0;
    return result;
}

int main() {
    freopen("input.txt", "r", stdin);
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        memset(isFriend, 0, sizeof(isFriend));
        memset(picked, 0, sizeof(picked));
        int n, m;
        cin >> n >> m;
        for (int j = 0; j < m; j++) {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            isFriend[temp1][temp2] = 1;
            isFriend[temp2][temp1] = 1;
        }
        cout << count(n, n) << endl;
    }
 }
