#include <bits/stdc++.h>

using namespace std;

int isFriend[10][10];

int count(vector<int> &rest) {
    if (rest.size() == 0)
        return 1;
    int result = 0;
    int student = rest[0];
    rest.erase(rest.begin());
    for (int i = 0; i < rest.size(); i++) {
        int target = rest[i];
        if (isFriend[student][target]) {
            rest.erase(rest.begin()+i);
            result += count(rest);
            rest.insert(rest.begin()+i, target);
        }
    }
    rest.insert(rest.begin(), student);
    return result;
}

int main() {
    freopen("input.txt", "r", stdin);
    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        memset(isFriend, 0, sizeof(isFriend));
        int n, m;
        cin >> n >> m;
        for (int j = 0; j < m; j++) {
            int temp1, temp2;
            cin >> temp1 >> temp2;
            isFriend[temp1][temp2] = 1;
            isFriend[temp2][temp1] = 1;
        }
        vector<int> students;
        for (int i = 0; i < n; i++) {
            students.push_back(i);
        }
        cout << count(students) << endl;
    }
 }
 