#include <bits/stdc++.h>

using namespace std;

int inputs[8];
int normalized[8];

map<string, int> order2id;
string start;
string destination;

vector<int> dist;

int N;

void initMap() {
    string s;
    for (int i = 1; i <= 8; i++)
        s += char('0' + i);
    start = s;
    int i = 0;
    do {
		order2id[s] = i++;
	} while (next_permutation(s.begin(), s.end()));
}

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++)
        result *= i;
    return result;
}

string partialReverse(string s, int start, int end) {
    string result = s;
    string p = s.substr(start, end+1-start);
    reverse(p.begin(), p.end());
    result.replace(start, end+1-start, p);
    return result;
}

int preCalc() {
    order2id.clear();
    initMap();

    dist = vector<int> (factorial(8), -1);
    queue<string> q;

    int id = order2id[start];
    dist[id] = 0;
    q.push(start);

    while(!q.empty()) {
        string here = q.front();
        q.pop();
        int hereID = order2id[here];
        for (int i = 0; i < 7; i++) {
            for (int j = i+1; j < 8; j++) {
                string there = partialReverse(here, i, j);
                int thereID = order2id[there];
                if (dist[thereID] == -1) {
                    dist[thereID] = dist[hereID] + 1;
                    q.push(there);
                }
            }
        }
    }
    return -1;
}

int main() {
    int C;
    cin >> C;
    preCalc();

    for (int c = 0; c < C; c++) {
        cin >> N;
        vector<pair<int,int>> pv;
        for (int i = 0; i < N; i++) {
            cin >> inputs[i];
            pv.push_back({inputs[i], i});
        }
        sort(pv.begin(), pv.end());
        for (int i = 0; i < N; i++)
            normalized[pv[i].second] = i+1;

        destination = "";
        for (int i = 0; i < N; i++)
            destination += char('0' + normalized[i]);
        for (int i = N; i < 8; i++)
            destination += char('0' + (i+1));
        int destID = order2id[destination];
        cout << dist[destID] << endl;
    }
}
