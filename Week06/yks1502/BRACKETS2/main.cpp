#include <bits/stdc++.h>
using namespace std;

int C, N;
string br;
stack<char> s;

int main() {
    cin >> C;
    for (int i = 0; i < C; i++) {
        cin >> br;
        N = br.size();
        while (!s.empty()) s.pop();

        for (int j = 0; j < N; j++) {
            if (s.empty()) {
                s.push(br[j]);
                continue;
            }
            char top = s.top();
            switch (br[j]) {
                case '(':
                case '{':
                case '[':
                    s.push(br[j]);
                    break;
                case ')':
                    if (top == '(') s.pop();
                    break;
                case '}':
                    if (top == '{') s.pop();
                    break;
                case ']':
                    if (top == '[') s.pop();
                    break;
            }
        }
            
        string result = s.empty() ? "YES" : "NO";
        cout << result << endl;
    }
}