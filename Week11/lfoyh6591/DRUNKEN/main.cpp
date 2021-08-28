#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int V, E, s, t;
int delay[500];
int graph[500][500];
int taketime[500][500];

void floyd(){
    vector<pair<int, int>> order;

    for(int i=0; i<V; i++){
        order.push_back(make_pair(delay[i], i));
    }
    sort(order.begin(), order.end());

    for(int k=0; k<V; k++){
        int w = order[k].second;
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                graph[i][j] = min(graph[i][j], graph[i][w]+graph[w][j]);
                taketime[i][j] = min(taketime[i][j], graph[i][w]+graph[w][j]+delay[w]);
            }
        }
    }
}

int main(){
    cin >> V >> E;

    for(int i=0; i<V; i++){
        cin >> delay[i];
    }

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(i == j){
                graph[i][i] = 0;
                taketime[i][i] = 0;
            }
            else{
                graph[i][j] = INF;
                taketime[i][j] = INF;
            }
        }
    }

    for(int i=0; i<E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a-1][b-1] = c;
        graph[b-1][a-1] = c;
        taketime[a-1][b-1] = c;
        taketime[b-1][a-1] = c;
    }

    floyd();

    int T;    cin >> T;
    for(int i=0; i<T; i++){
        cin >> s >> t;
        cout << taketime[s-1][t-1] << endl;
    }
}