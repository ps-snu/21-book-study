#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
string d;
int n, m;
vector<int> num;

int append(int here, int edge){
    int there = here*10 + edge;
    if(there>=n)    return n + there%n;

    return there%n;
}

string bfs(){
    queue<string> result;
    queue<int> node;
    vector<int> parent(2*n,-1);
    result.push("");
    node.push(0);

    while(!result.empty()){
        string c = result.front();
        int start = node.front();
        result.pop();   node.pop();

        for(int i=0; i<num.size(); i++){
            int nextnode = append(start, num[i]);
            string nextresult = c+to_string(num[i]);
            
            if(parent[nextnode]==-1){
                if(nextnode>=n){
                    if(nextnode == n+m){
                        return nextresult;
                    }
                }
                node.push(nextnode);
                result.push(nextresult);
                parent[nextnode] = start;
            }
        }
    }
    if(parent[n+m] == -1){
        return "IMPOSSIBLE";
    }
    return "IMPOSSIBLE";
}

int main(){
    int T;    cin >> T;
    for(int t=0; t<T; t++){
        cin >> d >> n >> m;
        for(int i=0; i<d.size(); i++){
            num.push_back((int)(d[i]-'0'));
        }

        sort(num.begin(), num.end());
        
        cout << bfs() << endl;
        
        num.clear();
    }
}