#include <bits/stdc++.h>
using namespace std;
#define MAX (INT_MAX-987654321)
#define MIN (INT_MIN+987654321)
//제자리 순환시 오버플로우 막기 위해 적당히 더하고 빼줌
#define M 9876543 //적당히 큰 수

int v, w;
vector<vector<pair<int, int>>> graph;

pair<string, string> bellmanFord(){
    vector<int> upper(v, MAX);
    vector<int> lower(v, MIN);
    vector<bool> fromZero(v, false); // 0에서 갈 수 있는지
    vector<bool> toOne(v, false);   // 1에 도달할 수 있는지
    vector<int> upcycle, lowcycle;  // 음수 사이클, 양수 사이클
    toOne[1] = true;
    fromZero[0] = true;
    upper[0] = 0;   lower[0] = 0;
    bool upupdated, lowupdated;
    for(int i=0; i<v; i++){
        upupdated = false;
        lowupdated = false;

        for(int here=0; here<v; here++){
            for(int j=0; j<graph[here].size(); j++){
                int there = graph[here][j].first;
                int cost = graph[here][j].second;
                if(toOne[there])    toOne[here] = true;
                if(fromZero[here])  fromZero[there] = true;

                if(upper[there] > upper[here] + cost){
                    upper[there] = upper[here] + cost;
                    upupdated = true;
                    if(i==v-1)  upcycle.push_back(there);
                }
                if(lower[there] < lower[here] + cost){
                    lower[there] = lower[here] + cost;
                    lowupdated = true;
                    if(i==v-1) lowcycle.push_back(there);
                }
            }
        }
        if(!upupdated && !lowupdated)    break;
    }

    string fast, slow;

    if(upper[1]>MAX-M || lower[1]<MIN+M) return make_pair("UNREACHABLE", "0");

    fast = to_string(upper[1]);
    slow = to_string(lower[1]);

    if(upupdated){
        for(int i=0; i<upcycle.size(); i++){
            if(fromZero[upcycle[i]] && toOne[upcycle[i]]){
                fast="INFINITY";
                break;
            }
        }
    }
    if(lowupdated){
        for(int i=0; i<lowcycle.size(); i++){
            if(fromZero[lowcycle[i]] && toOne[lowcycle[i]]){
                slow="INFINITY";
                break;
            }
        }
    }

    return make_pair(fast, slow);
}

int main(){    
    int C;    cin >> C;
    for(int c=0; c<C; c++){
        cin >> v >> w;
        graph.clear();
        graph.resize(v);
        for(int i=0; i<w; i++){
            int a, b, d;
            cin >> a >> b >> d;
            graph[a].push_back(make_pair(b, d));
        }
        pair<string, string> p = bellmanFord();

        if(p.first=="UNREACHABLE")  cout << p.first << endl;
        else{
            cout << p.first << " " << p.second << endl;
        }
    }
}