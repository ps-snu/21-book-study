#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
string input[100];
vector<string> graph[26][26];
int inward[26], outward[26], adj[26][26];
vector<int> seq;
int n;

void makegraph(){
    for(int i=0; i<26; i++){
        inward[i] = 0;
        outward[i] = 0;
        for(int j=0; j<26; j++){
            graph[i][j].clear();
            adj[i][j] = 0;
        }
    }
    for(int i=0; i<n; i++){
        int first = input[i][0]-'a';
        int last = input[i][input[i].size()-1]-'a';
        graph[first][last].push_back(input[i]);
        adj[first][last]++;
        outward[first]++;
        inward[last]++;
    }
}

void getcircuit(int start){
    for(int i=0; i<26; i++){
        while(adj[start][i]>0){
            adj[start][i]--;
            getcircuit(i);
        }
    }
    seq.push_back(start);
}

void circuit(){
    for(int i=0; i<26; i++){
        if(outward[i] == inward[i]+1){
            getcircuit(i);
            return;
        }
    }
    for(int i=0; i<26; i++){
        if(outward[i]>0){
            getcircuit(i);
            return;
        }
    }
}

void print(){
    if(seq.size()-1<n){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for(int i=seq.size()-1; i>0; i--){
        cout << graph[seq[i]][seq[i-1]].back() << " ";
        graph[seq[i]][seq[i-1]].pop_back();
    }
    cout << endl;
}

int main(){
    int C;    cin >> C;
    for(int c=0; c<C; c++){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> input[i];
        }
        makegraph();
        circuit();
        print();
        seq.clear();
    }
}