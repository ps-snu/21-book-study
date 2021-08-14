#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
 
int N;
int last, state;
int c[1 << 24];
 
int set(int base, int idx, int value)
{
    return (base & ~(3 << (idx*2))) | (value << (idx*2));
}
 
int get(int base, int idx)
{
    return 3 & (base >> (idx*2));
}
 
void init()
{
    cin >> N;
    int n, idx;
    int x = 0;
    last = state = 0;
    for(int i = 0; i<4; i++)
    {
        cin >> n;
        for(int j = 0; j<n; j++)
        {
            cin >> idx;
            state = set(state, idx-1, i);
            last = set(last, x++, 3);
        }
    }
}
 
int incr(int u)
{
    return u > 0 ? u+1 : u-1;
}
 
bool isEnd(int u, int v)
{
    return u*v < 0 ? true : false;
}
 
int bfs()
{
    if(state == last) return 0;
    queue<int> q;
    memset(c, 0, sizeof(c));
    c[state] = 1;
    q.push(state);
    c[last] = -1;
    q.push(last);
    int cost;
    while(true)
    {
        state = q.front(); q.pop();
        cost = c[state];
        int top[4] = {-1, -1, -1, -1};
        for(int i = N-1; i>=0; --i)
            top[get(state, i)] = i;
        for(int i = 0; i<4; i++)
            for(int j = 0; j<4; j++)
                if(i != j && top[i] != -1 && (top[j] == -1 || top[j] > top[i]))
                {
                    state = set(state, top[i], j);
                    if(isEnd(cost, c[state]))
                        return (cost > 0 ? cost : -1*cost) + (c[state] > 0 ? c[state] : -1*c[state]);
                    else if(c[state] == 0)
                    {
                        q.push(state);
                        c[state] = incr(cost);
                    }
                    state = set(state, top[i], i);
                }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int C; cin >> C;
    for(int t_num = 0; t_num < C; t_num++)
    {
        init();
        std::cout << bfs() -1 << "\n";
    }
}
