#include <bits/stdc++.h>

using namespace std;

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        string input;
        cin >> input;
        stack<char> s;
        bool matched = true;
        for (int i = 0; i < input.length(); i++) {
            if (s.empty()) s.push(input[i]);
            else if (input[i] == '(' || input[i] == '{' || input[i] == '[') s.push(input[i]);
            else if (s.top() == '(' && input[i] == ')') s.pop();
            else if (s.top() == '{' && input[i] == '}') s.pop();
            else if (s.top() == '[' && input[i] == ']') s.pop();
            else {
                matched = false; break;
            }
        }
        if (matched && s.empty()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
