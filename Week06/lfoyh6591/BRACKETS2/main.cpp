#include <bits/stdc++.h>
using namespace std;
int n, k;
string bracket(string s){
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(st.empty() || st.top()!='('){
                return "NO";
            }
            else    st.pop();
        }
        else if(s[i]=='}'){
            if(st.empty() || st.top()!='{'){
                return "NO";
            }
            else    st.pop();
        }
        else if(s[i]==']'){
            if(st.empty() || st.top()!='['){
                return "NO";
            }
            else    st.pop();
        }
    }
    if(st.empty())    return "YES";
    else                return "NO";    
}

int main(){    
    int C;    cin >> C;
    for(int c=0; c<C; c++){
        string s;   cin >> s;
        cout << bracket(s) << endl;
    }
}