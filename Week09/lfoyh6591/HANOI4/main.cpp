#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n;

int check[1<<24];

int readInput(){
    int input = 0;
    for(int i=0; i<4; i++){
        int num;
        cin >> num;
        for(int j=0; j<num; j++){
            int disc;
            cin >> disc;
            input |= (i<<(2*(disc-1)));
        }
    }
    return input;
}

vector<int> findTop(int here){
    vector<int> top(4, -1);
    for(int i=0; i<n; i++){
        int k = (here>> (i*2)) & 3;
        if(top[k] == -1){
            top[k] = i;
        }
    }
    return top;
}

int moveDisc(int here, int disc, int column){
    return (here & ~(3 << (disc*2))) | (column << (disc * 2));
}

int sign(int k){
    return k>0 ? 1 : -1;
}
int incr(int k){
    return k>0 ? k+1 : k-1;
}

int bfs(int start, int end){
    if(start == end)    return 0;

    memset(check, 0, sizeof(check));
    queue<int> q;
    q.push(start);  check[start] = 1;
    q.push(end);    check[end] = -1;

    while(!q.empty()){
        int here = q.front();
        q.pop();

        vector<int> top(4);
        top = findTop(here);

        for(int i=0; i<4; i++){
            if(top[i] != -1){
                for(int j=0; j<4; j++){
                    if(i!=j && ((top[j] == -1) || top[j] > top[i])){
                        int there = moveDisc(here, top[i], j);
                        if(check[there] == 0){
                            check[there] = incr(check[here]);
                            q.push(there);
                        }
                        else if(sign(check[here]) != sign(check[there])){
                            return abs(check[here])+abs(check[there])-1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int main(){
    int C;    cin >> C;
    for(int c=0; c<C; c++){
        cin >> n;
        int start = readInput();
        int end = (1<<(2*n)) -1;
        cout << bfs(start, end) << endl;
    }
}