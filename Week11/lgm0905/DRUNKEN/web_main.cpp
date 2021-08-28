#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
#define INF 1000000
 
int V, E;
vector<vector<int>> adj, ans;
vector<pair<int, int>> weight;
 
void mkg()
{
    cin >> V >> E;
    ans = adj = vector<vector<int>>(V+1, vector<int>(V+1, INF));
    weight = vector<pair<int, int>>(V);
    int x, y, r;
    for(int i = 0; i<V; ++i)
    {
        cin >> x;
        weight[i].first = x;
        weight[i].second = i+1;
        ans[i+1][i+1] = adj[i+1][i+1] = 0;
    }
    sort(weight.begin(), weight.end());
    for(int i = 0; i<E; ++i)
    {
        cin >> x >> y >> r;
        ans[x][y] = ans[y][x] = adj[x][y] = adj[y][x] = r;
    }
 
    for(int k = 0; k<V; ++k)
    {
        int w = weight[k].second;
        int c = weight[k].first;
        for(int i = 1; i<=V; ++i)
            for(int j = 1; j<=V; ++j)
                if(adj[i][j] > adj[i][w] + adj[w][j])
                {
                    adj[i][j] = adj[i][w] + adj[w][j];
                    ans[i][j] = min(ans[i][j], adj[i][w] + adj[w][j] + c);
                }
    }
}
 
int main()
{
    mkg();
    int C; cin >> C;
    int st, ed;
    for(int tn = 0; tn<C; ++tn)
    {
        cin >> st >> ed;
        cout << ans[st][ed] << "\n";
    }
}
