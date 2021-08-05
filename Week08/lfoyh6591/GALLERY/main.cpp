#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int g, h;
int adj[1000][1000];
bool dfscheck[1000];
bool cctvcheck[1000];
bool cctvinstalled[1000];
int cctvnum;

void dfs(int here){
    dfscheck[here] = true;
    for(int i=0; i<g; i++){
        if(adj[here][i]>0 && !dfscheck[i]){
            dfs(i);
            
            if(cctvinstalled[i]){
                cctvcheck[here] = true;
            }

            if(!cctvcheck[i]){
                if(cctvinstalled[here]){
                    cctvcheck[i] = true;
                }
                else{
                    cctvinstalled[here] = true;
                    cctvnum++;
                    cctvcheck[here] = true;
                    cctvcheck[i] = true;
                }
            }
        }
    }
}

int main(){
    int C;    cin >> C;
    for(int c=0; c<C; c++){
        cin >> g;
        cin >> h;
        memset(adj, 0, sizeof(adj));
        memset(dfscheck, false, sizeof(dfscheck));
        memset(cctvcheck, false, sizeof(cctvcheck));
        memset(cctvinstalled, false, sizeof(cctvinstalled));
        for(int i=0; i<h; i++){
            int a, b;
            cin >> a;
            cin >> b;
            adj[a][b]++;
            adj[b][a]++;
        }
        cctvnum = 0;
        for(int i=0; i<g; i++){
            if(!dfscheck[i]){
                dfs(i);
                if(!cctvcheck[i]){
                    cctvnum++;
                }
            }
        }
        cout << cctvnum << endl;
    }
}