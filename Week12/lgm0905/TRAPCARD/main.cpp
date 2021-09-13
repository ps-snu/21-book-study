#include <bits/stdc++.h>
#define M 300
using namespace std;
typedef pair<int, int> pii;
int H, W, n, m;
string board[M];
vector<vector<int> >id;
bool adj[M][M];
vector<int> aMatch, bMatch;
vector<bool> aChosen, bChosen, visited;

void init() {
    memset(board, 0, sizeof(board));
}

inline bool inRange(int x, int y) { return (0 <= x && x <= H-1 && 0 <= y && y <= W-1); }

void makeGraph() {
    id = vector<vector<int> >(H, vector<int>(W,-1));
    n = m = 0;

    for(int i = 0; i < H; i++) 
        for(int j = 0; j < W; j++) {
            if(board[i][j] == '#') continue;
            id[i][j] = ((i+j)%2 == 0) ? n++ : m++; 
        }
    
    memset(adj, false, sizeof(adj));

    vector<pii> deltaMove = {pii(0,1), pii(1,0), pii(0,-1), pii(-1,0)};

    for(int i = 0; i < H; i++) 
        for(int j = 0; j < W; j++) {
            if(board[i][j] == '#') continue;
            if((i+j)%2 != 0) continue;

            for(auto move : deltaMove) {
                int di = i+move.first, dj = j+move.second;
                if(inRange(di,dj) && board[di][dj] != '#') 
                    adj[id[i][j]][id[di][dj]] = true;
            }
        }
}

bool dfs(int a) {
    if(visited[a]) return false;
    visited[a] = true;
    for(int b = 0; b < m; b++) 
        if(adj[a][b])
            if(bMatch[b] == -1 || dfs(bMatch[b])) {
                aMatch[a] = b;
                bMatch[b] = a;
                return true;
            }
    return false;
}

int bipartiteMatch() {
    int ret = 0;
    aMatch = vector<int>(n,-1);
    bMatch = vector<int>(m,-1);
    
    for(int start = 0; start < n; start++) {
        visited = vector<bool>(n,false);
        if(dfs(start)) ++ret;
    }
    return ret;
}

// getting max independent set
int calcMaxIndepSet() {
    // aMatch[]와 bMatch[]를 계산한다.
    int C = bipartiteMatch();
    // 1. A의 모든 정점들을 선택하고, B에서 대응되지 않은 정점들을 선택한다.
    aChosen = vector<bool>(n, true);
    bChosen = vector<bool>(m, false);
    for(int i = 0; i < m; i++) {
        if(bMatch[i] == -1) bChosen[i] = true;
        // 2. 두 정점이 연결되어 있을 경우, 그중 A의 정점을 지우고 B의 대응된 정점을 대신 선택한다. 
        // 더 이상 변화가 일어나지 않을 때까지 반복한다.
        while(1) {
            bool changed = false;
            for(int i = 0; i < n; i++)
                for(int j = 0;j < m; j++)
                    if(aChosen[i] && bChosen[j] && adj[i][j]) {
                        // A는 항상 매칭에 포함된 정점임을 증명할 수 있다.
                        //assert(aMatch[i]!=-1);
                        aChosen[i]=false;
                        bChosen[aMatch[i]]=true;
                        changed=true;
                    }
            if(!changed) break;
        }
    }

    return C;
}

void printUpdatedBoard() {
    for(int y = 0; y < H; y++) {
        for(int x = 0; x < W; x++) {
            if(board[y][x] == '#') cout << '#';
            else if(((y+x)%2==0 && aChosen[id[y][x]]) ||
                    ((y+x)%2==1 && bChosen[id[y][x]]))
                cout << '^';
            else cout << '.';
        }
        cout<<endl;
    }
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        init();
        cin >> H >> W;
        for(int h = 0; h < H; h++) { 
            string s; cin >> s;
            board[h] = s;
        }
        makeGraph();
        int maxSet = calcMaxIndepSet();
        cout << n+m-maxSet << endl;
        printUpdatedBoard();
    }
    return 0;
}