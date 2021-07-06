#include <bits/stdc++.h>

using namespace std;


int m, q, n;
string word;
string words[500];
map<string, int> word2id;

double B[500];
double T[500][500];
double M[500][500];
int sentence[100];

double dp[500][101];
int next_id[500][101];

void init_dp() {
    for (int i = 0; i < 500; i++)
        for (int j = 0; j < 101; j++)
            dp[i][j] = -1;
}

double process(int prev_id, int index) {
    if (index == n) return 1.0;
    double &result = dp[prev_id][index];
    if (result != -1) return result;
    for (int i = 0; i < m; i++) {
        double temp_prob = T[prev_id][i] * M[i][sentence[index]] * process(i, index+1);
        if (result < temp_prob) {
            result = temp_prob;
            next_id[prev_id][index] = i;
        }
    }
    return result;
}

void high_prob_sentence() {
    double max_prob = -1;
    int item_id;
    for (int i = 0; i < m; i++) {
        double temp_prob = B[i] * M[i][sentence[0]] * process(i, 1);
        if (max_prob < temp_prob) {
            max_prob = temp_prob;
            item_id = i;
        }
    }
    cout << words[item_id] << " ";
    for (int i = 1; i < n; i++) {
        item_id = next_id[item_id][i];
        cout << words[item_id] << " ";
    }
    cout << endl;
}

int main() {
    cin >> m >> q;
    for (int i = 0; i < m; i++) {
        cin >> word;
        words[i] = word;
        word2id.insert({word, i});
    }
    for (int i = 0; i < m; i++)
        cin >> B[i];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cin >> T[i][j];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cin >> M[i][j];
    for (int i = 0; i < q; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> word;
            sentence[j] = word2id.find(word)->second;
        }
        init_dp();
        high_prob_sentence();
    }
}
