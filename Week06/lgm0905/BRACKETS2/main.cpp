#include <bits/stdc++.h>
using namespace std;
string in;
vector<char> stk;

bool solve() {
    for(int i = 0; i < in.size(); i++) {
        if(in[i] == '(' || in[i] == '{' || in[i] == '[') {
            stk.push_back(in[i]);
            continue;
        }
        switch(in[i]) {
            case ')' :
                if(stk.back() != '(') return false;
                else stk.pop_back();
                break;
            case '}' :
                if(stk.back() != '{') return false;
                else stk.pop_back();
                break;
            case ']' :
                if(stk.back() != '[') return false;
                else stk.pop_back();
                break;
        }
    }
    return stk.empty();
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        stk.clear();
        cin >> in;
        solve() ? cout << "YES" : cout << "NO";
        cout << endl;
    }
    return 0;
}