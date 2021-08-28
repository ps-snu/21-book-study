#include <bits/stdc++.h>
using namespace std;
#define INF 987654321

int V, M, N;
int graph[200][200];
int cnt;

void floyd(){
    for(int k=0; k<V; k++){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }
}

void newfloyd(int a, int b, int c){
    bool updated = false;
    if(graph[a][b] > c){
        updated = true;
    }
    int tmp = graph[a][b];
    graph[a][b] = c;
    graph[b][a] = c;
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(graph[i][j] > graph[i][a] + graph[a][b] + graph[b][j]){
                updated = true;
                graph[i][j] = graph[i][a] + graph[a][b] + graph[b][j];
            }

            if(graph[i][j] > graph[i][b] + graph[b][a] + graph[a][j]){
                updated = true;
                graph[i][j] = graph[i][b] + graph[b][a] + graph[a][j];
            }
        }
    }

    if(!updated){
        graph[a][b] = tmp;
        graph[b][a] = tmp;
        cnt++;
    }
}

int main(){    
    int C;    cin >> C;
    for(int c=0; c<C; c++){
        cnt = 0;
        cin >> V >> M >> N;

        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(i==j){
                    graph[i][j] = 0;
                }
                else{
                    graph[i][j] = INF;
                }
            }
        }
        for(int i=0; i<M; i++){
            int a, b, c;    cin >> a >> b >> c;
            if(graph[a][b] > c){
                graph[a][b] = c;
                graph[b][a] = c;
            }
        }

        floyd();

        for(int i=0; i<N; i++){
            int a, b, c;    cin >> a >> b >> c;
            newfloyd(a, b, c);
        }
        cout << cnt << endl;
    }
}