#include <bits/stdc++.h>

using namespace std;

string inputs[50];

bool checkMatch(string wildcard, string input) {
    int ws = wildcard.size();
    int is = input.size();
    if (ws == 0 && is == 0) return true;
    if (ws == 0 && is != 0) return false;

    int index = 0;
    for (index = 0; index < ws; index++) {
        if (index >= is) return false;
        if (wildcard[index] == '?') continue;
        if (wildcard[index] == '*') break;
        if (wildcard[index] != input[index]) return false;
    }
    if (index == ws && index == is) return true;

    for (int i = index; i <= is; i++) {
        if (checkMatch(wildcard.substr(index+1), input.substr(i))) return true;
    }
    return false;
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        string wildcard;
        cin >> wildcard;
        int N;
        cin >> N;
        for (int n = 0; n < N; n++) {
            cin >> inputs[n];
        }
        sort(inputs, inputs+N);
        for (int n = 0; n < N; n++) {
            if (checkMatch(wildcard, inputs[n])) cout << inputs[n] << endl;
        }
    }
}
