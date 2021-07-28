#include <bits/stdc++.h>

using namespace std;


int N;

struct Fort {
    int x;
    int y;
    int r;
    vector<Fort *> childeren;
};

map<Fort *, int> fort2height;

// return val
// 1 : fort 1 contains fort 2
// 0 : They don't contain each other
// -1 : fort 2 contains fort 1
int find_rel_bet_forts(Fort* fort1, Fort* fort2) {
    int dx = abs(fort1->x - fort2->x);
    int dy = abs(fort1->y - fort2->y);
    double distance = sqrt(dx * dx + dy * dy);
    if (distance > fort1->r + fort2->r) return 0;
    else if (fort1->r > fort2->r) return 1;
    else return -1;
}

void insert_fort(Fort* root, Fort* query) {
    vector<int> move;
    int i = 0;
    for (auto& fort : root->childeren) {
        int rel = find_rel_bet_forts(fort, query);
        if (rel == 1) return insert_fort(fort, query);
        else if (rel == -1) move.push_back(i);
        i++;
    }
    for (int j : move)
        query->childeren.push_back(root->childeren[j]);
    int erase_num = 0;
    for (int j : move) {
        root->childeren.erase(root->childeren.begin()+j-erase_num);
        erase_num++;
    }
    root->childeren.push_back(query);
}

void preorder_t(Fort* node) {
    if (node == NULL) return;
    cout << node->x << " " << node->y << " " << node->r  << " " << node->childeren.size() << endl;
    for (auto p : node->childeren)
        preorder_t(p);
}

int height(Fort* root) {
    if (fort2height.count(root)) return fort2height[root];
    if (root->childeren.size() == 0) return 1;
    int ret = 1;
    for (auto p : root->childeren)
        ret = max(ret, 1 + height(p));
    fort2height[root] = ret;
    return ret;
}

int solve(Fort* root) {
    if (root->childeren.size() == 0) return 0;
    int largest_height = 0;
    int second_largest = 0;
    for (auto p : root->childeren) {
        int h = height(p);
        if (h > largest_height) {
            second_largest = largest_height;
            largest_height = h;
        } else if (h > second_largest)
            second_largest = h;
    }
    int ret = largest_height + second_largest;
    for (auto p : root->childeren) {
        ret = max(ret, solve(p));
    }
    return ret;
}

int main() {
    int C;
    cin >> C;
    for (int c = 0; c < C; c++) {
        cin >> N;
        int x, y, r;
        fort2height.clear();
        Fort *root = new Fort;
        cin >> root->x >> root->y >> root->r;
        for (int i = 1; i < N; i++) {
            Fort *node = new Fort;
            cin >> node->x >> node->y >> node->r;
            insert_fort(root, node);
        }
        cout << solve(root) << endl;
    }
}
