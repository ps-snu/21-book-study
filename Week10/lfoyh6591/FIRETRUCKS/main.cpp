#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define INF numeric_limits<int>::max()
vector<vector<pair<int, int>>> graph;
vector<int> firepalce;
int v, e, n, m;

int dijkstra(){
    vector<int> distance(v+1, INF);
    distance[0] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, 0));

    while(!pq.empty()){
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(cost>distance[here]) continue;

        for(int i=0; i<graph[here].size(); i++){

            int there = graph[here][i].first;
            int nextd = graph[here][i].second + cost;

            if(nextd < distance[there]){
                distance[there] = nextd;
                pq.push(make_pair(-nextd, there));
            }
        }
    }

    int ret = 0;
    for(int i=0; i<firepalce.size(); i++){
        ret+=distance[firepalce[i]];
    }
    return ret;
}

int main(){    
    int C;    cin >> C;
    for(int c=0; c<C; c++){
        cin >> v >> e >> n >> m;
        graph.resize(v+1);
        for(int i=0; i<e; i++){
            int a, b, t;    cin >> a >> b >> t;
            graph[a].push_back(make_pair(b, t));
            graph[b].push_back(make_pair(a, t));
        }
        for(int i=0; i<n; i++){
            int place;  cin >> place;
            firepalce.push_back(place);
        }
        for(int i=0; i<m; i++){
            int s;    cin >> s;
            graph[0].push_back(make_pair(s, 0));
        }
        
        cout << dijkstra() << endl;
        graph.clear();  firepalce.clear();
    }
}