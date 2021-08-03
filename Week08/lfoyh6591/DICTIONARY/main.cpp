#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
string input[1000];
bool check[26][26];
bool checkalphabet[26];
int n, state;
bool visited[26];
vector<char> seq;

void findseq(){
    for(int i=0; i<n-1; i++){
        int al = input[i].size();
        int bl = input[i+1].size();

        for(int j=0; j<min(al, bl); j++){
            char c1 = input[i][j];
            char c2 = input[i+1][j];
            if(c1 == c2){
                /*if(j==min(al, bl)-1){
                    if(al>bl){
                        state = 2;
                        return;
                    }
                }*/
                continue;
            }
            else{
                if(!check[c1-'a'][c2-'a']){
                    if(check[c2-'a'][c1-'a']){
                        state = 2;
                        return;
                    }
                    else{
                        check[c1-'a'][c2-'a'] = true;
                        checkalphabet[c1-'a'] = true;
                    }
                }
                break;
            }
        }
    }
}

void dfs(int n){
    visited[n] = true;
    for(int i=0; i<26; i++){
        if(check[n][i] && !visited[i]){
            dfs(i);
        }
    }
    seq.push_back(n);
}

void print(){
    if(state == 2){
        cout << "INVALID HYPOTHESIS" << endl;
        return;
    }

    for(int i=0; i<26; i++){
        if(checkalphabet[i] && !visited[i]){
            dfs(i);
        }
    }

    int size = seq.size();
    for(int i=0; i<size; i++){
        cout << char(seq.back()+'a');
        seq.pop_back();
    }

    for(int i=0; i<26; i++){
        if(!visited[i]){
            cout << char(i+'a');
        }
    }
    cout << endl;
}

int main(){
    int C;    cin >> C;
    for(int c=0; c<C; c++){
        cin >> n;
        memset(check, false, sizeof(check));
        memset(checkalphabet, false, sizeof(checkalphabet));
        memset(visited, false, sizeof(visited));
        for(int i=0; i<n; i++){
            cin >> input[i];
        }
        findseq();
        print();
        state = 0;
        seq.clear();
    }
}