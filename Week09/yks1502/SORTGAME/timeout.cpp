#include <bits/stdc++.h>
using namespace std;

int C, N, k, result, sorted[8];
vector<int> num;

class Vertex {
    public:
        vector<int> arr;
        int dist;
        Vertex(vector<int> arr, int dist)
            : arr(arr), dist(dist) { }
};

bool checkSorted(vector<int> arr) {
    bool ret = true;

    for (int i = 0; i < N; i++) {
        if (arr[i] != sorted[i]) {
            ret = false;
            break;
        }
    }

    return ret;
}

vector<int> reflect(Vertex* e, int left, int right) {
    vector<int> ret = e->arr;
    reverse(ret.begin() + left, ret.begin() + right);

    return ret;
}

void rankNum() {
    vector<int> newArray = num;
    sort(newArray.begin(), newArray.end());

    map<int, int> ranks;
    int rank = 1;
    for (int i = 0; i < N; i++) {
        int elm = newArray[i];

        if (ranks[elm] == 0)
            ranks[elm] = rank++;
    }

    for (int i = 0; i < N; i++)
        num[i] = ranks[num[i]];
}

int main() {
    for (int i = 0; i < 8; i++) sorted[i] = i + 1;

    cin >> C;
    for (int tc = 0; tc < C; tc++) {
        cin >> N;
        num.clear();
        for (int n = 0; n < N; n++) {
            cin >> k;
            num.push_back(k);
        }
        rankNum();

        queue<Vertex*> q;
        Vertex* vertex = new Vertex(num, 0);
        q.push(vertex);

        map<vector<int>, bool> discovered;
        discovered[num] = true;

        while (!q.empty()) {
            vertex = q.front();
            q.pop();

            if (checkSorted(vertex->arr)) {
                result = vertex->dist;
                break;
            }

            for (int i = 0; i < N; i++) {
                for (int j = i + 1; j < N + 1; j++) {
                    vector<int> reflected = reflect(vertex, i, j);
                    if (discovered.find(reflected) == discovered.end()) {
                        Vertex* v = new Vertex(reflected, vertex->dist + 1);
                        q.push(v);
                        discovered[reflected] = true;
                    }
                }
            }
        }

        cout << result << endl;
    }
}