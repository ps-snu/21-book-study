#include <bits/stdc++.h>

using namespace std;

vector<int> getParitalMatch(string &N) {
    int m = N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while (begin + matched < m) {
        if (N[begin+matched] == N[matched]) {
            matched++;
            pi[begin+matched-1] = matched;
        } else {
            if (matched == 0)
                begin++;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return pi;
}

vector<int> KMPSearch(const string &S, const string &N, const vector<int> &pi) {
    vector<int> ret;
    int n = S.size(), m = N.size();
    int begin = 0, matched = 0;
    while (begin <= n - m) {
        if (matched < m && S[begin+matched] == N[matched]) {
            matched++;
            if (matched == m)
                ret.push_back(begin);
        } else {
            if (matched == 0)
                begin++;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    return ret;
}

int computeDistance(int prev, int curr, int m, bool clockwise) {
    int distance = curr - prev;
    if (clockwise) {
        if (distance >= 0)
            return distance;
        else
            return m + distance;
    } else {
        if (distance <= 0)
            return -distance;
        else
            return m - distance;
    }
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        int n;
        string N;
        cin >> n;
        cin >> N;

        vector<int> pi = getParitalMatch(N);

        int m = N.size();
        int prev_index = 0;
        int result = 0;
        bool clockwise = true;

        for (int i = 0; i < n; i++) {
            string S;
            cin >> S;
            vector<int> positions = KMPSearch(S+S, N, pi);
            int distance = INT_MAX;
            int curr_index = -1;
            for (int pos : positions){
                int temp = computeDistance(prev_index, pos, m, clockwise);
                if (temp != 0 && distance > temp) {
                    distance = temp;
                    curr_index = pos;
                }
            }
            result += distance;
            clockwise = !clockwise;
            prev_index = curr_index;
        }
        cout << result << endl;
    }
}
