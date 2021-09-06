#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> x;
vector<int> y;
bool check[500];
double d[500][500];
bool cable[500][500];

double dist(int x, int y, int x1, int y1){
    return sqrt(((double)x-(double)x1)*((double)x-(double)x1) + ((double)y-(double)y1)*((double)y-(double)y1));
}

double prim(){
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    int cnt = 0;
    double result = 0;
    
    for(int i=0; i<n; i++){
        pq.push(make_pair(d[0][i], i));
    }
    check[0] = true;
    while(!pq.empty()){
        double cost = pq.top().first;
        int start = pq.top().second;
        pq.pop();

        if(check[start])    continue;
        else{
            check[start] = true;
            cnt++;
            result+=cost;

            if(cnt == n)    return result;

            for(int i=0; i<n; i++){
                if(!check[i]){
                    pq.push(make_pair(d[start][i], i));

                }
            }
        }
    }
    return result;
}

int main(){
    int C;    cin >> C;
    cout << fixed;
    cout.precision(10);
    for(int c=0; c<C; c++){
        cin >> n >> m;
        memset(check, false, sizeof(check));
        x.clear();      y.clear();
        x.resize(n);    y.resize(n);

        for(int i=0; i<n; i++){
            cin >> x[i];
        }
        for(int i=0; i<n; i++){
            cin >> y[i];
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                d[i][j] = dist(x[i], y[i], x[j], y[j]);
                if(i==j)    d[i][j] = DBL_MAX;
            }
        }
        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;
            d[a][b] = 0;
            d[b][a] = 0;
        }
        cout << prim() << endl;
    }
}