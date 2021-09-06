#include <bits/stdc++.h>
using namespace std;
int n, m, totalwin;
int winnum[12];
int match[100][2];
int capacity[115][115], flow[115][115];

int networkFlow(int source, int sink){
    while(true){
        vector<int> parent(115, -1);
        queue<int> q;
        q.push(source);
        parent[source] = source;
        while(!q.empty() && parent[sink]==-1){
            int here = q.front(); q.pop();
            for(int i=0; i<2+n+m; i++){
                if(capacity[here][i] - flow[here][i] > 0 && parent[i]==-1){
                    q.push(i);
                    parent[i] = here;
                }
            }
        }
        if(parent[sink]==-1){
            break;
        }

        int minnum = INT_MAX;
        for(int i=sink; i!=source; i=parent[i]){
            minnum = min(capacity[parent[i]][i] - flow[parent[i]][i], minnum);
        }

        for(int i=sink; i!=source; i=parent[i]){
            flow[parent[i]][i] += minnum;
            flow[i][parent[i]] -= minnum;
        }

        totalwin += minnum;
    }

    return totalwin;
}

void makeGraph(){
    memset(capacity, 0, sizeof(capacity));
    
    for(int i=0; i<m; i++){
        capacity[0][2+i]++;
        capacity[2+i][match[i][0]+2+m]++;
        capacity[2+i][match[i][1]+2+m]++;
    }
    for(int i=0; i<n; i++){
        if(i==0){
            capacity[2+m+i][1] = 0;
        }
        else{
            capacity[2+m+i][1] = winnum[0]-winnum[i]-1;
        }
    }
}
bool canWin(int minwin){
    for(int i=1; i<n; i++){
        if(winnum[i]>=minwin){
            return false;
        }
    }

    return (networkFlow(0, 1) == m);
}

int main(){
    int C;    cin >> C;
    for(int c=0; c<C; c++){
        cin >> n >> m;
        for(int i=0; i<n; i++){
            cin >> winnum[i];
        }
        int extrawin = 0;
        for(int i=0; i<m; i++){
            int a, b;   cin >> a >> b;
            match[i][0] = a;
            match[i][1] = b;
            if((a == 0) || (b == 0)){
                extrawin++;
            }
        }
        totalwin = 0;
        memset(flow, 0, sizeof(flow));
        makeGraph();
        int updated = false;
        for(int i=0; i<=extrawin; i++){
            if(canWin(winnum[0]+i)){

                cout << winnum[0]+i << endl;
                updated = true;
                break;
            }                    
            for(int i=0; i<n; i++){
                capacity[2+m+i][1]++;
            }
        }
        if(!updated){
            cout << -1 << endl;
        }
    }
}