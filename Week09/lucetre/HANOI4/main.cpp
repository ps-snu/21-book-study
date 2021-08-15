#include <bits/stdc++.h>
using namespace std;
int N, srt, dst;
int dist[1<<24];

int getPlace(int state, int disc) {
    return (state >> (disc*2)) & 3;
}
 
void setState(int& state, int disc, int place) {
    state = (state & ~(3 << (disc*2))) | (place << (disc*2));
}
 
int process() {
    if (srt == dst) return 0;
    memset(dist, 0, sizeof(dist));
    queue<int> Q;
    Q.push(srt); dist[srt] =  1;
    Q.push(dst); dist[dst] = -1;
    while (!Q.empty()) {
        int f = Q.front(); Q.pop();
        int top[4] = {-1, -1, -1, -1};
        for (int i = N-1; i >= 0; i--)
            top[getPlace(f, i)] = i;
        for (int i = 0; i < 4; i++) {
            if (top[i] != -1) {
                for (int j = 0; j < 4; j++) {
                    if (i != j && (top[j] == -1 || top[i] < top[j])) {
                        int t = f;
                        setState(t, top[i], j);
                        if (dist[t] == 0) {
                            int v = abs(dist[f]) + 1;
                            dist[t] = dist[f] > 0 ? v : -v;
                            Q.push(t);
                        }
                        if (dist[t]*dist[f] < 0)
                            return abs(dist[t]) + abs(dist[f]) - 1;
                    }
                }
            }
        }
    }
    return -1;
}
 
int main(){
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        srt = dst = 0;
        for (int p = 0; p < 4; p++) {
            int n; cin >> n;
            for (int i = 0; i < n; i++) {
                int disk; cin >> disk;
                setState(srt, disk-1, p);
            }
        }
        for (int i = 0; i < N; i++) setState(dst, i, 3);
        cout << process() << endl;
    }
}
