#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define INF numeric_limits<double>::max()
int n, m;
vector<vector<pair<int, double>>> graph;

double dijkstra(){
    vector<double> noise(n, INF);
    noise[0] = 0;
    priority_queue<pair<double, int>> pq;
    pq.push(make_pair(0,0));
    while(!pq.empty()){
        double cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(noise[here] < cost) continue;

        for(int i=0; i<graph[here].size(); i++){
            int there = graph[here][i].first;
            double nextnoise = noise[here]+graph[here][i].second;

            if(noise[there] > nextnoise){
                noise[there] = nextnoise;
                pq.push(make_pair(-nextnoise, there));
            }
        }
    }
    return noise[n-1];
}
int main(){
    int C;    cin >> C;
    cout << fixed;
    cout.precision(10);
    for(int c=0; c<C; c++){
        cin >> n >> m;
        graph.resize(n);
        for(int i=0; i<m; i++){
            int v1, v2;
            double w;
            cin >> v1 >> v2 >> w;

            graph[v1].push_back(make_pair(v2, log10(w)));
            graph[v2].push_back(make_pair(v1, log10(w)));
        }
        cout << pow(10, dijkstra()) << endl;
        graph.clear();
    }
}