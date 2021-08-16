#include <bits/stdc++.h>
using namespace std;

const long long MAX_INT = (long long)INT_MAX + 1;
int C, N, K, maxLen;
int arr[500];
vector<int> starts;

class LIS {
    public:
        int len;
        long long count;
        vector<int> next;
        LIS() : len(0), count(0) {}
};

LIS* lis[500];

LIS* calcLis(int idx) {
    LIS*& l = lis[idx];
    if (l->len != 0) return l;

    for (int i = idx + 1; i < N; i++) {
        if (arr[idx] < arr[i]) {
            LIS* v = calcLis(i);

            if (l->len < v->len + 1) {
                l->len = v->len + 1;
                l->count = v->count;
                l->next.clear();
                l->next.push_back(i);

                maxLen = max(maxLen, l->len);
            } else if (l->len == v->len + 1) {
                l->count = min<long long>(l->count + v->count, MAX_INT);
                l->next.push_back(i);
            }
        }
    }

    if (l->len == 0) {
        l->len = 1;
        l->count = 1;
        maxLen = max(maxLen, l->len);
    }

    return l;
}

vector<int> rankList(vector<int> list) {
    vector<int> newArray, res;
    map<int, int> ranks;
    for (int i = 0; i < list.size(); i++) {
        newArray.push_back(arr[list[i]]);
        ranks[arr[list[i]]] = list[i];
    }

    sort(newArray.begin(), newArray.end());
    
    for (int i = 0; i < list.size(); i++) {
        res.push_back(ranks[newArray[i]]);
    }

    return res;
}

string klis(long long k, vector<int> list, int length) {
    if (length == maxLen) {
        int idx = list[k];
        return to_string(arr[idx]);
    }

    long long sum = 0;
    for (int i = 0; i < list.size(); i++) {
        int idx = list[i];
        LIS* l = lis[idx];
        if (k >= sum && k < sum + l->count) {
            vector<int> next = l->next;
            next = rankList(next);
            return to_string(arr[idx]) + " " + klis(k - sum, next, length + 1);
        } else {
            sum += l->count;
        }
    }

    return "";
}

int main() {
    cin >> C;
    for (int tc = 0; tc < C; tc++) {
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            lis[i] = new LIS();
        }

        maxLen = 0;
        for (int i = N - 1; i >= 0; i--)
            calcLis(i);
            
        starts.clear();
        for (int i = 0; i < N; i++) {
            if (lis[i]->len == maxLen) {
                starts.push_back(i);
            }
        }
        starts = rankList(starts);

        cout << maxLen << endl;
        cout << klis(K - 1, starts, 1) << endl;
    }
}