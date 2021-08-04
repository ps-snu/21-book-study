#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> words[26][26];

int indegree[26];
int outdegree[26];
int edgeNum[26][26];


void getEulerCircuit(int from, vector<int>& circuit) {
    for (int to = 0; to < 26; to++) {
        while (edgeNum[from][to]) {
            edgeNum[from][to]--;
            getEulerCircuit(to, circuit);
        }
    }
    circuit.push_back(from);
}

vector<int> getEulerCircuitOrTrail() {
    vector<int> circuit;
    for (int i = 0; i < 26; i++) {
        if (outdegree[i] == indegree[i] + 1) {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (outdegree[i]) {
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }
    return circuit;
}


bool checkEuler() {
    int plus1 = 0, minus1 = 0;
    for (int i = 0; i < 26; i++) {
        int delta = indegree[i] - outdegree[i];
        if (delta < -1 || delta > 1) return false;
        if (delta == -1) minus1++;
        else if (delta == 1) plus1++;
    }
    return (plus1==1 && minus1==1) || (plus1==0 && minus1==0);
}

string solve() {
    if (!checkEuler()) return "IMPOSSIBLE";
    vector<int> result = getEulerCircuitOrTrail();
    if (result.size() != N+1) return "IMPOSSIBLE";
    reverse(result.begin(), result.end());
    string ret;
    for (int i = 0; i < result.size()-1; i++) {
        int a = result[i], b = result[i+1];
        if (i > 0) ret += " ";
        ret += words[a][b].back();
        words[a][b].pop_back();
    }
    return ret;
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> N;
        memset(indegree, 0, sizeof(indegree));
        memset(outdegree, 0, sizeof(outdegree));
        memset(edgeNum, 0, sizeof(edgeNum));
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                words[i][j].clear();
        string word;
        for (int i = 0; i < N; i++) {
            cin >> word;
            int wlen = word.length();
            int s = word[0] - 'a';
            int e = word[wlen-1] - 'a';
            words[s][e].push_back(word);
            edgeNum[s][e]++;
            outdegree[s]++;
            indegree[e]++;
        }
        cout << solve() << endl;            
    }
}
