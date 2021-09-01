#include <bits/stdc++.h>
#define N_MAX 500
#define M_MAX 2000
using namespace std;
typedef pair<double, double> pdd;
typedef pair<int, int> pii;

int N, M;
pdd point[N_MAX];
double dist[N_MAX][N_MAX];
vector<int> sets;

/* disjoint set functions */
int getParent(int a) {
    if(sets[a] == a) return a;
    return getParent(sets[a]);
}

bool isSameParent(int a, int b) { return getParent(a) == getParent(b); }

void unionSet(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if(a < b) sets[b] = a;
    else sets[a] = b;
}
/* End disjoint set functions */

void init() {
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) 
            dist[i][j] = -1;
    for(int i = 0; i < N; i++) 
        point[i] = pdd(0,0);
}

double getDist(pdd a, pdd b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + 
            (a.second - b.second) * (a.second - b.second));
}

double solve() {
    vector<pair<double, pii> > edges;
    for(int i = 0; i < N; i++) 
        for(int j = 0; j < N; j++) 
            edges.push_back(make_pair(dist[i][j], pii(i,j)));
    sort(edges.begin(), edges.end());

    // kruskal using disjoint set
    sets = vector<int>(N);
    for(int i = 0; i < N; i++) 
        sets[i] = i;
    
    double ret = 0;
    for(int i = 0; i < edges.size(); i++) {
        double w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if(!isSameParent(u,v)) {
            unionSet(u,v);
            ret += w;
        }
    }
    return ret;
}   

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> N >> M;
        init();
        for(int i = 0; i < N; i++)
            cin >> point[i].first;
        for(int i = 0; i < N; i++)
            cin >> point[i].second;
        
        for(int i = 0; i < M; i++) {
            int u, v; cin >> u >> v;
            dist[u][v] = dist[v][u] = 0;
        }
        // calc dist(precalc)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++) {
                if(dist[i][j] != -1) continue;
                dist[i][j] = dist[j][i] = getDist(point[i], point[j]);
            }

        printf("%.10lf\n", solve());
    }
    return 0;
}