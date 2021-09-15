#include <bits/stdc++.h>
using namespace std;

vector<int> getPartialMatch(string s){
    int len = s.size();
    vector<int> v(len, 0);

    int begin = 1, matched = 0;
    while(begin+matched<len){
        if(s[begin+matched] == s[matched]){
            matched++;
            v[begin+matched-1] = matched;
        }
        else{
            if(matched==0){
                begin++;
            }
            else{
                begin+=matched-v[matched-1];
                matched = v[matched-1];
            }
        }
    }
    return v;
}

int palindrome_length(string reverses){
    string s = reverses;
    reverse(reverses.begin(), reverses.end());
    int len = s.size();

    vector<int> v = getPartialMatch(reverses);

    int begin = 0;
    int matched = 0;
    while(begin < len){
        if(matched < len && s[begin+matched] == reverses[matched]){
            matched++;
            if(begin+matched == len){
                return len+begin;
            }
        }
        else{
            if(matched==0){
                begin++;
            }
            else{
                begin += matched - v[matched-1];
                matched = v[matched-1];
            }
        }
    }
    return 0;
}

int main(){
    int C;    cin >> C;
    for(int c=0; c<C; c++){
        string s;
        cin >> s;
        cout << palindrome_length(s) << endl;
    }
}