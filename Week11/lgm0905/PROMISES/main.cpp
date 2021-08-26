#include <bits/stdc++.h>
#define INF 987654321
#define MAX_V 200
using namespace std;
int mg[MAX_V][MAX_V];
int V, M, N; 

void init() {
    for(int i = 0; i < V; i++) 
        for(int j = 0; j < V; j++) 
            mg[i][j] = (i == j) ? 0 : INF;
}

void findSP() {
    for(int k = 0; k < V; k++) 
        for(int i = 0; i < V; i++) 
            for(int j = 0; j < V; j++) 
                mg[i][j] = min(mg[i][j], mg[i][k] + mg[k][j]);
}
 
bool makeRoad(int u, int v, int w) {
    bool maked = false;
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(mg[i][j] > mg[i][u] + w + mg[v][j]) {
                mg[i][j] = mg[i][u] + w + mg[v][j];
                maked = true;
            }
            if(mg[i][j] > mg[i][v] + w + mg[u][j]) {
                mg[i][j] = mg[i][v] + w + mg[u][j];
                maked = true;
            }
        }
    }
    return maked;
}

/* From jongman book */
// bool update(int u, int v, int w) {
//     if(mg[u][v] <= w ) return false;
//     for(int i = 0; i < V; i++) 
//         for(int j = 0; j < V; j++) 
//             mg[i][j] = min( mg[i][j], min(mg[i][u]+w+mg[v][j], mg[i][v]+w+mg[u][j]) );
//     return true;
// }

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> V >> M >> N;
        init();
        for(int m = 0; m < M; m++) {
            int u, v, w; 
            cin >> u >> v >> w;
            mg[u][v] = min(mg[u][v], w);
            mg[v][u] = min(mg[v][u], w);
        }
        findSP();
        int ret = 0;
        for(int n = 0; n < N; n++) {
            int u, v, w; 
            cin >> u >> v >> w;
            ret = makeRoad(u, v, w) ? ret : ret+1;
        }
        cout << ret << endl;
    }
    return 0;
}