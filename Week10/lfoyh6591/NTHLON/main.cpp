#include <bits/stdc++.h>
using namespace std;
#define INF numeric_limits<int>::max()

vector<pair<int, int>> input;
vector<int> dif;
vector<vector<pair<int, int>>> graph;
int m;

void makeGraph(){
    graph.resize(401); // -200~200 -> 0~400     0 is 200
    for(int i=0; i<401; i++){
        for(int j=0; j<input.size(); j++){
            if((i+dif[j]) < 0 || (i+dif[j]) > 401)     continue;

            graph[i].push_back(make_pair(i+dif[j], input[j].first));
        }
    }
}

int dijkstra(int start){
    vector<int> dist(401, INF);
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    dist[start] = INF;

    while(!pq.empty()){
        int here = pq.top().second;
        int d = -pq.top().first;
        pq.pop();

        if(d>dist[here])    continue;

        for(int i=0; i<graph[here].size(); i++){
            int there = graph[here][i].first;
            int nextd = graph[here][i].second + d;

            if(nextd < dist[there]){
                dist[there] = nextd;
                pq.push(make_pair(-nextd, there));
            }
        }
    }

    return dist[start];
}

int main(){    
    int C;    cin >> C;
    for(int c=0; c<C; c++){
        cin >> m;
        for(int i=0; i<m; i++){
            int a, b;   cin >> a >> b;
            input.push_back(make_pair(a, b));
            dif.push_back(a-b);
        }
        makeGraph();
        int result = dijkstra(200);
        if(result == INF){
            cout << "IMPOSSIBLE" << endl;
        }
        else{
            cout << result << endl;
        }
        input.clear();  dif.clear();    graph.clear();
    }
}